#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
using namespace std;

class find_mine {
private:
	typedef struct {
		int y;
		int x;
	}grid;
	int mine[10005][10005] = {};
	int cou[10005][10005] = {};
	int open[10005][10005] = {};
	int check[10005][10005] = {};
	int N, M, cmine;
	int input, n;
	grid inpg;
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
	int count_check(int y, int x) {
		for (int i = 0; i < 8; i++)
		{

		}
	}
	void print() {
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				printp(i, j);
				//cout << mine[i][j];
			}
			cout << '\n';
		}
	}
	void printp(int y, int x) {
		if (check[y][x] == 1) {
			cout << "¤·";
		}
		else if (open[y][x] == 0)
			cout << "¤±";
		else {
			if (cou[y][x])
				cout << ' ' << cou[y][x];
			else
				cout << "  ";
		}
	}
	void op(int y, int x) {
		if (y <= 0 || x <= 0 || y > N || x > M)
			return;
		if (open[y][x] == 1)
			return;
		open[y][x] = 1;
		if (cou[y][x])
			return;
		for (int i = 0; i < 8; i++)
		{
			if (mine[y + Y[i]][x + X[i]] == 0) {
				op(y + Y[i], x + X[i]);
			}
		}
	}
	void init() {
		memset(mine, 0, sizeof(mine));
		memset(open, 0, sizeof(open));
		memset(check, 0, sizeof(check));
		srand((unsigned int)time(NULL));
	}
	void wrong_input() {
		system("cls");
		print();
		cout << "incollect selection\n";
	}
	grid ch(int input) {
		grid tmp;
		tmp.y = (input / N) + 1;
		tmp.x = input % M;
		return tmp;
	}
public:
	void start() {
		while (1) {
			cin >> N >> M >> cmine;
			init();
			int x, y;
			for (int i = 0; i < cmine; i++)
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
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					cou[i][j] = fmine(i, j);
				}
			}
			system("cls");
			print();
			while (1) {
				cin >> n >> input;
				inpg = ch(input);
				if (inpg.y <= 0 || inpg.y > N || inpg.x <= 0 || inpg.x > M) {
					wrong_input();
					continue;
				}
				if (n == 0) {
					if (open[inpg.y][inpg.x] == 1) {
						wrong_input();
						continue;
					}
					if (mine[inpg.y][inpg.x] == 0) {
						op(inpg.y, inpg.x);
					}
					else {
						system("cls");
						cout << "game over!\n\n\nDo you want to play again? y/n\n";
						char str;
						cin >> str;
						if (str == 'y')
							break;
						else
							return;
					}
				}
				else if (n == 1) {
					if (check[inpg.y][inpg.x] == 0) {
						check[inpg.y][inpg.x] = 1;
						if (mine[inpg.y][inpg.x] == 1)
							cmine--;
					}
					else {
						check[inpg.y][inpg.x] = 0;
						if (mine[inpg.y][inpg.x] == 1)
							cmine++;
					}
				}
				else {

				}
				system("cls");
				print();
			}
		}
	}
};

find_mine m;

int main(void) {
	m.start();
}