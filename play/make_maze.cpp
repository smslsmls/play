#include<bits/stdc++.h>
#include<Windows.h>
#include"make_maze.h"
using namespace std;

//��
int maze[10000][10000];
int visit[10000][10000];
//ũ��
int N, M;
//��ǥ
COORD grid;
COORD zero;
int X[] = { 2,0,-2,0 };
int x[] = { 1,0,-1,0 };
int Y[] = { 0,2,0,-2 };
int y[] = { 0,1,0,-1 };
//�ڵ�
HANDLE h_in, h_out;
//�Լ� ����
void dfs_maze(COORD);

void make_maze() {
	N = -1;
	M = -1;
	h_in = GetStdHandle(STD_INPUT_HANDLE);
	h_out = GetStdHandle(STD_OUTPUT_HANDLE);

	while (N < 0 || M < 0 || N % 2 == 1 || M % 2 == 1) {
		SetConsoleCursorPosition(h_out, zero);
		cout << "�̷θ� ���� ũ�⸦ ������ �ּ���.\n����(189���� ����)(Ȧ��) : ";
		cin >> M;
		cout << "����(59���� ����)(Ȧ��) : ";
		cin >> N;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
				maze[i][j] = 1;
			else
				maze[i][j] = 0;
		}
	}
	srand((unsigned int)time((NULL)));
	grid.X = 1;
	grid.Y = 1;
	dfs_maze(grid);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			SetCon
		}
	}
}

void dfs_maze(COORD grid) {
	COORD now;
	int in[5] = { 0, };
	int r;
	visit[grid.Y][grid.X] = 1;
	for (int i = 0; i < 4; i++)
	{
		r = rand() % 4;
		if (in[r]) {
			i--;
			continue;
		}
		in[r] = 1;
		now.X = grid.X + X[r];
		now.Y = grid.Y + Y[r];
		if (now.X < 0 || now.Y < 0 || now.X >= M || now.Y >= N)
			continue;
		if (visit[now.Y][now.X]) {
			maze[grid.Y + y[r]][grid.X + x[r]] = 1;
			continue;
		}
		dfs_maze(now);
	}
}