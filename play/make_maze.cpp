#include<bits/stdc++.h>
#include<Windows.h>
#include"make_maze.h"
using namespace std;

//��
int maze[100][100];
//ũ��
int N, M;
COORD zero;
HANDLE h_in, h_out;

void make_maze() {
	N = -1;
	M = -1;
	h_in = GetStdHandle(STD_INPUT_HANDLE);
	h_out = GetStdHandle(STD_OUTPUT_HANDLE);

	while (N < 0 || M < 0||N%2==1||M%2==1) {
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
			maze[i][j] = 0;
		}
	}
	srand((unsigned int)time((NULL)));

}