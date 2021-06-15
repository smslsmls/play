#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>
#include"maze.h"

enum sprint {
	TITLE,
	MAP
};

//����
//��
int maze[10000][10000];
int visit[10000][10000];
//ũ��
int maze_N, maze_M;
//��ǥ
extern COORD zero;
COORD mouse;
int X[] = { 2,0,-2,0 };
int x[] = { 1,0,-1,0 };
int Y[] = { 0,2,0,-2 };
int y[] = { 0,1,0,-1 };
//Ÿ��Ʋ ������
char title[5][20] = { "�̷θ����","ÿ�������","����" };
//���콺 �Է�
DWORD insize;
//���
DWORD old_mode;
DWORD new_mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
//�ڵ�
HANDLE h_in, h_out;
//�Լ� ����
void dfs_maze(COORD, int);
int dfs(COORD);
void print(sprint, int);
void make_maze();
void set_NM();
void init();
int select_title();

void maze_play() {

}

void make_maze() {
	COORD grid;
	for (int i = 0; i < maze_N; i++)
	{
		for (int j = 0; j < maze_M; j++)
		{
			if (i == 0 || i == maze_N - 1 || j == 0 || j == maze_M - 1 || (i % 2 == 0 && j % 2 == 0))
				maze[i][j] = 1;
			else
				maze[i][j] = 0;
		}
	}
	srand((unsigned int)time((NULL)));
	grid.X = 1;
	grid.Y = 1;
	system("cls");
	dfs_maze(grid, 4);
}

void dfs_maze(COORD grid, int n) {
	COORD now;
	int in[5] = { 0, };
	int r;
	in[n] = 1;
	visit[grid.Y][grid.X] = 1;
	if (grid.X == maze_M - 2 && grid.Y == maze_N - 2)
		return;
	if (n == 4) {
		r = rand() % 4;
		in[r] = 1;
		now.X = grid.X + X[r];
		now.Y = grid.Y + Y[r];
		dfs_maze(now, (r + 2) % 4);
	}
	for (int i = 0; i < 3; i++)
	{
		r = rand() % 4;
		if (in[r]) {
			i--;
			continue;
		}
		in[r] = 1;
		now.X = grid.X + X[r];
		now.Y = grid.Y + Y[r];
		if (now.X < 0 || now.Y < 0 || now.X >= maze_M || now.Y >= maze_N)
			continue;
		if (visit[now.Y][now.X]) {
			maze[grid.Y + y[r]][grid.X + x[r]] = 1;
			continue;
		}
		dfs_maze(now, (r + 2) % 4);
	}
}

int dfs(COORD grid, COORD end) {
	COORD next = grid;
	maze[grid.Y][grid.X] = 4;
	if (grid.Y == end.Y && grid.X == end.X)
		return 1;
	for (int i = 0; i < 4; i++)
	{
		if (maze[grid.Y + y[i]][grid.X + x[i]] != 1 && maze[grid.Y + y[i]][grid.X + x[i]] != 4) {
			next.Y += y[i];
			next.X += x[i];
			if (dfs(next, end))
				return 1;
			next = grid;
		}
	}
	maze[grid.Y][grid.X] = 0;
	return 0;
}

void print(sprint select, int title_select = 0) {
	SetConsoleCursorPosition(h_out, zero);
	switch (select)
	{
	case TITLE:
		int len;
		int big = 10;
		printf(" ");
		for (int i = 0; i < 14; i++)
		{
			printf("-");
		}
		zero.Y++;
		SetConsoleCursorPosition(h_out, zero);
		for (int i = 0; i < 3; i++)
		{
			len = strlen(title[i]);
			printf("|");
			for (int j = 0; j < (s - len) / 2 + (s - len) % 2; j++)
			{
				printf(" ");
			}
			if (i + 1 == title_select)
				printf("->");
			else
				printf("  ");
			printf("%s", title[i]);
			if (i + 1 == title_select)
				printf("<-");
			else
				printf("  ");
			for (int j = 0; j < (s - len) / 2; j++)
			{
				printf(" ");
			}
			printf("|");
			zero.Y++;
			SetConsoleCursorPosition(h_out, zero);
		}
		printf(" ");
		for (int i = 0; i < 14; i++)
		{
			printf("-");
		}
		break;
	case MAP:
		for (int i = 0; i < maze_N; i++)
		{
			for (int j = 0; j < maze_M; j++)
			{
				if (maze[i][j] == 0)
					SetConsoleTextAttribute(h_out, 7 | 7 << 4);
				if (maze[i][j] == 1)
					SetConsoleTextAttribute(h_out, 8 | 8 << 4);
				if (i == 1 && j == 1)
					SetConsoleTextAttribute(h_out, 11 | 11 << 4);
				if (i == maze_N - 2 && j == maze_M - 2)
					SetConsoleTextAttribute(h_out, 12 | 12 << 4);
				if (maze[i][j] == 4)
					SetConsoleTextAttribute(h_out, 10 | 10 << 4);
				printf("��");
			}
		}
		break;
	default:
		break;
	}
	zero.Y++;
	SetConsoleCursorPosition(h_out, zero);
}

void set_NM() {
	maze_N = -1;
	maze_M = -1;
	h_in = GetStdHandle(STD_INPUT_HANDLE);
	h_out = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode con: cols=186 line=120");
	while (maze_N < 0 || maze_M < 0 || maze_N % 2 == 0 || maze_M % 2 == 0 || maze_M>93) {
		SetConsoleCursorPosition(h_out, zero);
		printf("�̷θ� ���� ũ�⸦ ������ �ּ���.\n����(93����)(Ȧ��) : ");
		scanf("%d", &maze_M);
		printf("����(49���� ����)(Ȧ��) : ");
		scanf("%d", &maze_N);
	}
}

void init() {
	GetConsoleMode(h_in, old_mode);
}

int select_title() {
	INPUT_RECORD in_buf[100];
	SetConsoleMode(h_in, new_mode);
	while (true)
	{
		ReadConsoleInput(h_in, in_buf, 100, &insize);
		for (DWORD i = 0; i < insize; i++)
		{
			switch (in_buf[i].EventType)
			{
			case MOUSE_EVENT:
				in_buf[i].Event.MouseEvent.dwMousePosition
			default:
				break;
			}
		}
	}
}