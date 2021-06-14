#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include"maze.h"

//맵
int maze[10000][10000];
int visit[10000][10000];
//크기
int maze_N, maze_M;
//좌표
extern COORD zero;
COORD play = { 1,1 };
int X[] = { 2,0,-2,0 };
int x[] = { 1,0,-1,0 };
int Y[] = { 0,2,0,-2 };
int y[] = { 0,1,0,-1 };
//핸들
HANDLE h_in, h_out;
//함수 원형
void dfs_maze(COORD, int);

void make_maze() {
	COORD grid;
	maze_N = -1;
	maze_M = -1;
	h_in = GetStdHandle(STD_INPUT_HANDLE);
	h_out = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode con: cols=186 line=120");
	while (maze_N < 0 || maze_M < 0 || maze_N % 2 == 0 || maze_M % 2 == 0 || maze_M>93) {
		SetConsoleCursorPosition(h_out, zero);
		printf("미로를 만들 크기를 설정해 주세요.\n가로(93이하)(홀수) : ");
		scanf("%d", &maze_M);
		printf("세로(49이하 권장)(홀수) : ");
		scanf("%d", &maze_N);
	}
	for (int i = 0; i < maze_N; i++)
	{
		for (int j = 0; j < maze_M; j++)
		{
			if (i == 0 || i == maze_N - 1 || j == 0 || j == maze_M - 1)
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
	maze[1][1] = 2;
	maze[maze_N - 2][maze_M - 2] = 3;
	SetConsoleCursorPosition(h_out, zero);
	for (int i = 0; i < maze_N; i++)
	{
		for (int j = 0; j < maze_M; j++)
		{
			if (maze[i][j] == 0)
				SetConsoleTextAttribute(h_out, 7 | 7 << 4);
			if (maze[i][j] == 1 || (i % 2 == 0 && j % 2 == 0))
				SetConsoleTextAttribute(h_out, 8 | 8 << 4);
			if (maze[i][j] == 2)
				SetConsoleTextAttribute(h_out, 11 | 11 << 4);
			if (maze[i][j] == 3)
				SetConsoleTextAttribute(h_out, 12 | 12 << 4);
			printf("■");
		}
		zero.Y++;
		SetConsoleCursorPosition(h_out, zero);
	}
	zero.Y = 0;
	SetConsoleTextAttribute(h_out, 7);
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