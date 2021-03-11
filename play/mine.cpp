#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
using namespace std;

class find_mine {
private:
	int mine[10005][10005] = {};
	int cou[10005][10005] = {};
	int open[10005][10005] = {};
	int N, M, CM, inx, iny;
	int X[8] = { 1,0,-1,-1,-1,0,1,1 };
	int Y[8] = { 1,1,1,0,-1,-1,-1,0 };
	int fmine(int y, int x) {
		int f = 0;
		for (int i = 0; i < 8; i++)
		{
			if (mine[y + Y[i]][x + X[i]] == 1)
				f++;
		}
		return f;
	}
	void print() {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printp(i, j);
				cout << mine[i][j];
			}
			cout << '\n';
		}
	}
	void printp(int y, int x) {
		if (open[y][x] == 0)
			cout << "¤±";
		else {
			if (cou[y][x])
				cout << cou[y][x];
			else
				cout << ' ';
		}
	}
	void op(int y, int x) {
		if (y <= 0 && x <= 0 && y > N && x > M)
			return;
		if (open[y][x] == 1)
			return;
		open[y][x] = 1;
		cou[y][x] = fmine(y, x);
		if (cou[y][x])
			return;
		for (int i = 0; i < 8; i++)
		{
			if (fmine(y + Y[i], x + X[i]) == 0) {
				op(y + Y[i], x + X[i]);
			}
		}
	}
public:
	void start() {
		cin >> N >> M >> CM;
		srand((unsigned int)time(NULL));
		int x, y;
		for (int i = 0; i < CM; i++)
		{
			x = rand() % M;
			y = rand() % N;
			x++;
			y++;
			if (mine[y][x] == 1) {
				i--;
				continue;
			}
			mine[y][x] = 1;
		}
		print();
		while (1) {
			cin >> iny >> inx;
			if (open[iny][inx]) {
				cout << "incollect selection\n";
				continue;
			}
			op(iny, inx);
			system("cls");
			print();
		}
	}
};

find_mine m;

int main(void) {
	m.start();
}