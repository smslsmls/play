#include <stdio.h> 
#include <Windows.h>
#include"mouseinput.h"


HANDLE COUT = 0;    // �ܼ� ��� ��ġ
HANDLE CIN = 0;        // �ܼ� �Է� ��ġ

int be_input()
{
    INPUT_RECORD input_record;
    DWORD input_count;

    PeekConsoleInput(CIN, &input_record, 1, &input_count);
    return input_count;
}

int get_input(WORD* vkey, COORD* pos)
{
    INPUT_RECORD input_record;
    DWORD input_count;

    ReadConsoleInput(CIN, &input_record, 1, &input_count);
    switch (input_record.EventType) {
    case MOUSE_EVENT:
        if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
            CONSOLE_SCREEN_BUFFER_INFO csbi;

            GetConsoleScreenBufferInfo(COUT, &csbi);

            *pos = input_record.Event.MouseEvent.dwMousePosition;
            pos->X -= csbi.srWindow.Left;
            pos->Y -= csbi.srWindow.Top;

            return MOUSE_EVENT;
        }
        break;

    }

    //    FlushConsoleInputBuffer(CIN);
    return 0;
}

void gotoxy(int x, int y)      // ��ǥ ������ gotoxy
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void mouseinput()
{
    DWORD mode;
    WORD key;
    COORD pos;

    int event;        // ���콺 �̺�Ʈ�� �̿�
    int x;            // ���콺�� x��ǥ �����
    int y;            // ���콺�� y��ǥ �����

    CIN = GetStdHandle(STD_INPUT_HANDLE);
    COUT = GetStdHandle(STD_OUTPUT_HANDLE);

    // ���콺 Ȱ��ȭ
    GetConsoleMode(CIN, &mode);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

    while (1)
    {
        if (be_input())
        {
            if (get_input(&key, &pos) != 0)
            {
                MOUSE_EVENT;
                x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
                y = pos.Y;
                gotoxy(x, y);
                printf("*");
            }
        }
    }
}
