#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"tetris.h"

#define left 75
#define right 77
#define down 80
#define full_down 115
#define change 97
#define stop 27
#define reset 122

typedef struct block_xy
{
    int x;
    int y;
}block_xy;

//�����͸� ó������ ��� �޸� ����  
int n = 0;

int background[13][21] = { 0 };
int time_count = 1000, score = 0, stack = 125;

//2������ ����� ���� ��ϵ�
block_xy block[19][4] = { {{-1,0},{0,0},{1,0},{2,0}}, {{0,-1}, {0,0},{0,1},{0,2}},
                  {{-1,-1},{-1,0},{0,0},{0,1}}, {{-1,0},{0,0},{0,-1},{1,-1}},
                  {{0,1},{0,0},{1,0},{1,-1}}, {{-1,-1},{0,-1},{0,0},{1,0}},

    //4������ ����� ���� ��ϵ�
    {{0,-1},{0,0},{0,1},{1,1}}, {{-1,1},{-1,0},{0,0},{1,0}}, {{-1,-1},{0,-1},{0,0},{0,1}}, {{-1,0},{0,0},{1,0},{1,-1}},
    {{-1,1},{0,1},{0,0},{0,-1}}, {{-1,-1},{-1,0},{0,0},{1,0}}, {{0,1},{0,0},{0,-1},{1,-1}}, {{-1,0},{0,0},{1,0},{1,1}},
    {{-1,0},{0,-1},{0,0},{1,0}}, {{0,-1},{0,0},{0,1},{1,0}}, {{-1,0},{0,0},{0,1},{1,0}}, {{-1,0},{0,-1},{0,0},{0,1}},

    //1������ ����� ���� ���  
    {{0,-1},{0,0},{1,-1},{1,0}} };

void gotoxy(int x, int y);
void mouse();

//��� ���
void print_background();
void block_start(block_xy start_xy, int* block_type);

//�� ������ �� �ִ��� üũ
int block_chack(block_xy start_xy, int* block_type);

//�� ���
void block_print(block_xy start_xy, int* block_type);
//�� ����
void block_delete(block_xy start_xy, int* block_type);

//�� �̵�
block_xy block_move(block_xy start_xy, int* block_type);

void block_stop(block_xy start_xy, int* block_type);
void line_chack_and_remove();

void next_block(block_xy start_xy, int* next_type);
void next_block_background();
void clear_next_block();
void esc_remove();

void key_check();

int tetris_main()
{
    mouse();   //���콺 ��� �ٲ��ֱ�  

    int chack;
    block_xy start_xy;

    int block_type;
    int next_type = 0;

    srand(time(NULL));
    block_type = rand() % 19;

    while (1)
    {
        print_background();

        start_xy.x = 6;
        start_xy.y = 0;
        block_type = next_type;

        next_type = rand() % 19;

        block_start(start_xy, &block_type);

        clear_next_block();
        next_block(start_xy, &next_type);

        while (1)
        {
            start_xy = block_move(start_xy, &block_type);
            start_xy.y++;
            chack = block_chack(start_xy, &block_type);

            esc_remove();

            if (chack == 1)
            {
                start_xy.y--;
                block_stop(start_xy, &block_type);
                line_chack_and_remove();

                break;
            }
            else
            {
                start_xy.y--;
                block_delete(start_xy, &block_type);
                start_xy.y++;
                block_print(start_xy, &block_type);
            }
        }
    }
    return 0;
}
//����â���� Ŀ���� �̵������ִ�  �Լ� 
void gotoxy(int x, int y)
{
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void mouse() {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//�⺻ ����ȭ���� ������ְ� �޸𸮿� ���� �־��ִ� �Լ� 
void print_background()
{
    for (int i = 0; i < 13; i++)
    {
        gotoxy(i * 2 + 1, 21);
        printf("��");
        background[i][20] = 1;
    }
    for (int i = 0; i < 13; i += 12)
    {
        for (int j = 0; j < 21; j++)
        {
            gotoxy(i * 2 + 1, j + 1);
            printf("��");
            background[i][j] = 1;
        }
    }

    key_check();
    next_block_background();
}

//���ο� ����� �����Ǵ� �� ��  
void block_start(block_xy start_xy, int* block_type)
{
    int chack = block_chack(start_xy, block_type);
    if (chack == 1)
    {
        system("cls");
        gotoxy(1, 9);
        printf("=============���� ����=============\n");
        printf("===========���� ���� : %d=========\n\n\n\n\n\n\n", score);
        Sleep(1000);
        exit(0);
    }
    else
    {
        block_print(start_xy, block_type);
    }
}

//�ش� ����� ǥ�� �� �� �ִ��� Ȯ�����ִ� �Լ� 
int block_chack(block_xy start_xy, int* block_type)
{
    int i;
    block_xy chack;
    for (i = 0; i < 4; i++)
    {
        chack.x = block[*block_type][i].x + start_xy.x;
        chack.y = block[*block_type][i].y + start_xy.y;

        if (chack.y >= 0)
        {
            if (background[chack.x][chack.y] == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}

//�ش� ����� ������ִ� �� ��  
void block_print(block_xy start_xy, int* block_type) {

    int i;
    block_xy chack;

    for (i = 0; i < 4; i++)
    {
        chack.x = block[*block_type][i].x + start_xy.x;
        chack.y = block[*block_type][i].y + start_xy.y;

        if (chack.y >= 0)
        {
            gotoxy(chack.x * 2 + 1, chack.y + 1);
            printf("��");
        }
    }
}

//��µ� ����� �������ֱ� ���� �Լ�   ��� �̵��� ����  
void block_delete(block_xy start_xy, int* block_type)
{
    int i;
    block_xy chack;
    for (i = 0; i < 4; i++)
    {
        chack.x = block[*block_type][i].x + start_xy.x;
        chack.y = block[*block_type][i].y + start_xy.y;
        gotoxy(chack.x * 2 + 1, chack.y + 1);
        printf("  ");
    }
}

//����� �������� �޸𸮿� ���ϸ������ ���� �־��ִ� �Լ� 
void block_stop(block_xy start_xy, int* block_type)
{
    int i;
    block_xy chack;
    for (i = 0; i < 4; i++)
    {
        chack.x = block[*block_type][i].x + start_xy.x;
        chack.y = block[*block_type][i].y + start_xy.y;
        background[chack.x][chack.y] = 1;
    }
}



//Ű�� �ԷµǾ����� ����� �̵����ɿ��θ� Ȯ�����ְ� ��ȭ�����ִ� �Լ�
block_xy block_move(block_xy start_xy, int* block_type)
{
    clock_t t1, t2, full_count = 0;

    int direction, chack, chack2;
    t1 = clock();

    while (1)
    {
        if (_kbhit())
        {
            direction = _getch();

            if (direction == 224)
            {
                direction = _getch();
            }

            switch (direction)
            {
            case left:
                start_xy.x--;
                chack = block_chack(start_xy, block_type);

                if (chack == 1)
                {
                    start_xy.x++;
                }
                else
                {
                    start_xy.x++;
                    block_delete(start_xy, block_type);

                    start_xy.x--;
                    block_print(start_xy, block_type);
                }
                break;

            case right:
                start_xy.x++;
                chack = block_chack(start_xy, block_type);

                if (chack == 1)
                {
                    start_xy.x--;
                }
                else
                {
                    start_xy.x--;
                    block_delete(start_xy, block_type);

                    start_xy.x++;
                    block_print(start_xy, block_type);
                }
                break;

            case down:
                start_xy.y++;
                chack = block_chack(start_xy, block_type);

                if (chack == 1)
                {
                    start_xy.y--;
                }
                else
                {
                    start_xy.y--;
                    block_delete(start_xy, block_type);
                    start_xy.y++;
                    block_print(start_xy, block_type);
                }
                break;

            case 's':
                while (1)
                {
                    start_xy.y++;
                    chack = block_chack(start_xy, block_type);

                    if (chack == 1)
                    {
                        start_xy.y--;
                        full_count = 1000;
                        break;
                    }
                    else
                    {
                        start_xy.y--;
                        block_delete(start_xy, block_type);

                        start_xy.y++;
                        block_print(start_xy, block_type);
                    }
                }
                break;

            case  'a':
                if (*block_type >= 0 && *block_type <= 5)
                {
                    if (*block_type % 2 == 1)
                    {
                        *block_type -= 1;
                        chack2 = block_chack(start_xy, block_type);

                        if (chack2 == 1)
                        {
                            *block_type += 1;
                        }
                        else
                        {
                            *block_type += 1;
                            block_delete(start_xy, block_type);

                            *block_type -= 1;
                            block_print(start_xy, block_type);
                        }
                    }
                    else
                    {
                        *block_type += 1;
                        chack2 = block_chack(start_xy, block_type);

                        if (chack2 == 1)
                        {
                            *block_type -= 1;
                        }
                        else {
                            *block_type -= 1;
                            block_delete(start_xy, block_type);
                            *block_type += 1;
                            block_print(start_xy, block_type);
                        }
                    }
                }
                else if (*block_type >= 6 && *block_type <= 17)
                {
                    if ((*block_type - 6) % 4 == 3)
                    {
                        *block_type -= 3;
                        chack2 = block_chack(start_xy, block_type);

                        if (chack2 == 1)
                        {
                            *block_type += 3;
                        }
                        else
                        {
                            *block_type += 3;
                            block_delete(start_xy, block_type);
                            *block_type -= 3;
                            block_print(start_xy, block_type);
                        }
                    }
                    else
                    {
                        *block_type += 1;
                        chack2 = block_chack(start_xy, block_type);

                        if (chack2 == 1)
                        {
                            *block_type -= 1;
                        }
                        else
                        {
                            *block_type -= 1;
                            block_delete(start_xy, block_type);
                            *block_type += 1;
                            block_print(start_xy, block_type);
                        }
                    }
                }
                break;
            case stop:
                gotoxy(3, 25);
                printf("�Ͻ����� �մϴ�.\n\n");
                system("PAUSE");
                break;
            case ' ':
                system("cls");
                gotoxy(1, 9);
                printf("=============���� ����=============\n");
                printf("===========���� ���� : %d=========\n\n\n\n\n\n\n", score);
                Sleep(1000);
                exit(0);
            case reset:
                print_background();
                for (int i = 19; i > 0; i--)
                {
                    for (int j = 1; j < 12; j++)
                    {
                        for (int t = i; t > 1; t--)
                        {
                            background[j][t] = 0;
                            gotoxy(j * 2 + 1, t + 1);
                            printf("  ");
                        }
                    }
                }
                break;
            }
        }
        t2 = clock();
        t2 += full_count;
        if (t2 - t1 > time_count)break;
    }
    return start_xy;
}

//����� ���߰� ������ �˻��ϰ� ������ �������ִ� �Լ�   
void line_chack_and_remove() {

    int chack;
    for (int i = 19; i > 0; i--)
    {
        for (int j = 1; j < 12; j++)
        {
            chack = background[j][i];

            if (chack == 0)break;
        }

        if (chack == 1)
        {
            for (int j = 1; j < 12; j++)
            {
                for (int t = i; t > 1; t--)
                {
                    background[j][t] = background[j][t - 1];
                    gotoxy(j * 2 + 1, t + 1);

                    if (background[j][t] == 1)
                    {
                        printf("��");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
            }
            i++;
            score += 100;

            /*if (stack > 0) {
                time_count -= stack;
                stack -= 10;
            }*/
            gotoxy(30, 21);
            printf(" ���� ���� : %d", score);
        }
    }
}

void next_block(block_xy start_xy, int* next_type)
{
    if (*next_type == 0)
    {
        gotoxy(34, 5);
        printf("�����");
    }
    else if (*next_type == 1)
    {
        gotoxy(34, 5);
        printf("��");
        gotoxy(34, 6);
        printf("��");
        gotoxy(34, 7);
        printf("��");
        gotoxy(34, 8);
        printf("��");

    }
    else if (*next_type == 2)
    {
        gotoxy(34, 5);
        printf("��  ");
        gotoxy(34, 6);
        printf("���  ");
        gotoxy(34, 7);
        printf("  ��  ");
    }
    else if (*next_type == 3)
    {
        gotoxy(34, 5);
        printf("  ���");
        gotoxy(34, 6);
        printf("���  ");
    }
    else if (*next_type == 4)
    {
        gotoxy(34, 5);
        printf("  ��");
        gotoxy(34, 6);
        printf("���");
        gotoxy(34, 7);
        printf("��  ");
    }
    else if (*next_type == 5)
    {
        gotoxy(34, 5);
        printf("���  ");
        gotoxy(34, 6);
        printf("  ���");
    }
    else if (*next_type == 6)
    {
        gotoxy(34, 5);
        printf("��    ");
        gotoxy(34, 6);
        printf("��    ");
        gotoxy(34, 7);
        printf("���  ");
    }
    else if (*next_type == 7)
    {
        gotoxy(34, 5);
        printf("����");
        gotoxy(34, 6);
        printf("��    ");
    }
    else if (*next_type == 8)
    {
        gotoxy(34, 5);
        printf("  ���");
        gotoxy(34, 6);
        printf("    ��");
        gotoxy(34, 7);
        printf("    ��");
    }
    else if (*next_type == 9)
    {
        gotoxy(34, 5);
        printf("    ��");
        gotoxy(34, 6);
        printf("����");
    }
    else if (*next_type == 10)
    {
        gotoxy(34, 5);
        printf("    ��");
        gotoxy(34, 6);
        printf("    ��");
        gotoxy(34, 7);
        printf("  ���");
    }
    else if (*next_type == 11)
    {
        gotoxy(34, 5);
        printf("��    ");
        gotoxy(34, 6);
        printf("����");
    }
    else if (*next_type == 12)
    {
        gotoxy(34, 5);
        printf("���  ");
        gotoxy(34, 6);
        printf("��    ");
        gotoxy(34, 7);
        printf("��    ");
    }
    else if (*next_type == 13)
    {
        gotoxy(34, 5);
        printf("����");
        gotoxy(34, 6);
        printf("    ��");
    }
    else if (*next_type == 14)
    {
        gotoxy(34, 5);
        printf("  ��  ");
        gotoxy(34, 6);
        printf("����");
    }
    else if (*next_type == 15)
    {
        gotoxy(34, 5);
        printf("  ��  ");
        gotoxy(34, 6);
        printf("  ���");
        gotoxy(34, 7);
        printf("  ��  ");
    }
    else if (*next_type == 16)
    {
        gotoxy(34, 5);
        printf("����");
        gotoxy(34, 6);
        printf("  ��  ");
    }
    else if (*next_type == 17)
    {
        gotoxy(34, 5);
        printf("  ��  ");
        gotoxy(34, 6);
        printf("���  ");
        gotoxy(34, 7);
        printf("  ��  ");
    }
    else if (*next_type == 18)
    {
        gotoxy(34, 5);
        printf("���");
        gotoxy(34, 6);
        printf("���");
    }
}

void clear_next_block()
{
    gotoxy(32, 5);
    printf("          ");
    gotoxy(32, 6);
    printf("          ");
    gotoxy(32, 7);
    printf("          ");
    gotoxy(32, 8);
    printf("          ");
}

void esc_remove()
{

    gotoxy(3, 25);
    printf("                   ");
    gotoxy(1, 27);
    printf("                                       ");
}

void key_check()
{
    gotoxy(30, 12);
    printf("|------------------------|------------------------|");
    gotoxy(30, 13);
    printf("|��: ��� �Ʒ������� �̵�|    esc   : �Ͻ�����");
    gotoxy(30, 14);
    printf("|------------------------|------------------------|");
    gotoxy(30, 15);
    printf("|   a : ��� ��� ����   |    space : ��������");
    gotoxy(30, 16);
    printf("|------------------------|------------------------|");
    gotoxy(30, 17);
    printf("|   s : ��� ����߸���  |    z     : ����");
    gotoxy(30, 18);
    printf("|------------------------|------------------------|");
    gotoxy(30, 21);
    printf(" ���� ���� : %d", score);
}

void next_block_background()
{
    gotoxy(32, 2);
    printf("���� ��");
    gotoxy(30, 3);
    printf("���������");
    gotoxy(30, 4);
    printf("��            ��");
    gotoxy(30, 5);
    printf("��            ��");
    gotoxy(30, 6);
    printf("��            ��");
    gotoxy(30, 7);
    printf("��            ��");
    gotoxy(30, 8);
    printf("��            ��");
    gotoxy(30, 9);
    printf("��            ��");
    gotoxy(30, 10);
    printf("���������");
}