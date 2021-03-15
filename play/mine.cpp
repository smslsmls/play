#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
using namespace std;

class find_mine {
private:
	//grid ����
	typedef struct {
		int y;
		int x;
	}grid;
	//�⺻ ���� ����
	int mine[35][70] = {};//27,58
	int cou[35][70] = {};
	int open[35][70] = {};
	int check[35][70] = {};
	int X[8] = { 1,0,-1,-1,-1,0,1,1 };
	int Y[8] = { 1,1,1,0,-1,-1,-1,0 };
	int rp;
	//�Էº��� ����
	int N, M, cmine;
	int input, n;
	grid inpg;
	//���� Ȯ�� ����
	int e;

	//�ֺ� ���� ���� ��ȯ
	int fmine(int y, int x) {
		int f = 0;
		for (int i = 0; i < 8; i++)
		{
			if (mine[y + Y[i]][x + X[i]] == 1)
				f++;
		}
		return f;
	}
	//�ֺ� ǥ�� ���� ��ȯ
	int count_check(int y, int x) {
		int c = 0;
		for (int i = 0; i < 8; i++)
		{
			if (check[y + Y[i]][x + X[i]])
				c++;
		}
		return c;
	}
	//�� ���
	void print() {
		cout << ' ';
		for (int i = 0; i < M; i++)
		{
			cout << "--";
		}
		cout << " \n";
		for (int i = 1; i <= N; i++)
		{
			cout << '|';
			for (int j = 1; j <= M; j++)
			{
				printp(i, j);
				//cout << mine[i][j];
			}
			cout<<'|';
			cout << '\n';
		}
		cout << ' ';
		for (int i = 0; i < M; i++)
		{
			cout << "--";
		}
		cout << " \n";
	}
	//�� �� ���
	void printp(int y, int x) {
		if (open[y][x] == 0)
			cout << "��";
		else if (check[y][x] == 1) {
			cout << "��";
		}
		else {
			if (cou[y][x])
				cout << ' ' << cou[y][x];
			else
				cout << "  ";
		}
	}
	//�� �� ����(DFS)
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
	//�� �� ���� Ȯ��
	int opche(int y, int x) {
		if (mine[y][x] == 0) {
			op(y, x);
			rp = -1;
			return 1;
		}
		else {
			system("cls");
			cout << "game over!\n\n\n";
			lose++;
			cout << "Do you want to play again? y/n\n";
			char str;
			while (1) {
				cin >> str;
				if (str != 'y' && str != 'n') {
					system("cls");
					wrong_input();
					cout << "input y or n\n";
				}
				else {
					break;
				}
			}
			if (str == 'y') {
				system("cls");
				rp = 1;
				return 0;
			}
			else {
				rp = 0;
				return 0;
			}
		}
	}
	//�⺻ �迭 �ʱ�ȭ, ���� �õ� �ʱ�ȭ
	void init() {
		memset(mine, 0, sizeof(mine));
		memset(open, 0, sizeof(open));
		memset(check, 0, sizeof(check));
		srand((unsigned int)time(NULL));
	}
	//�����޽��� ���
	void wrong_input() {
		system("cls");
		print();
		cout << "incollect selection\n";
	}
	//�⺻ ��ǲ
	void stdinp() {
		e = 0;
		while (1) {
			cin >> N >> M >> cmine;
			if (N < 1 || N>27 || M < 1 || M>58 || cmine<1 || cmine>N * M - 1)
				system("cls");
			if (N < 1 || N>27) {
				cout << "select wigth 1~27\n";
				e++;
			}
			if (M < 1 || M>58) {
				cout << "select length 1~58\n";
				e++;
			}
			if (cmine<1 || cmine>N * M - 1) {
				cout << "select mine under area\n";
				e++;
			}
			if (!e)
				break;
		}
		return;
	}
	//���� ����
	void spmine() {
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
		return;
	}
	//cou�ʱ�ȭ
	void init_cou() {
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cou[i][j] = fmine(i, j);
			}
		}
		return;
	}
	//int to grid
	grid ch(int input) {
		grid tmp;
		tmp.y = (input / N) + 1;
		tmp.x = input % N;
		return tmp;
	}
	//����
	int game() {
		while (1) {
			cin >> n >> input;
			inpg = ch(input);
			if (inpg.y <= 0 || inpg.y > N || inpg.x <= 0 || inpg.x > M) {
				wrong_input();
				continue;
			}
			if (n == 0) {//ĭ ����
				if (open[inpg.y][inpg.x] == 1) {
					if (cou[inpg.y][inpg.x]&&cou[inpg.y][inpg.x] == count_check(inpg.y, inpg.x)) {
						for (int i = 0; i < 8; i++)
						{
							if (!opche(inpg.y, inpg.x)) {
								break;
							}
						}
						if (rp != -1) {
							if (rp)
								break;
							else
								return 1;
						}
					}
					else {
						wrong_input();
						continue;
					}
				}
				else {
					if (!opche(inpg.y, inpg.x)) {
						if (rp)
							break;
						else
							return 1;
					}
				}
			}
			else if (n == 1) {//���� ǥ��
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
				if (cmine == 0) {
					cout << "You Win!!\n";
					wins++;
					cout << "Do you want to play again? y/n\n";
					char str;
					while (1) {
						cin >> str;
						if (str != 'y' && str != 'n') {
							system("cls");
							wrong_input();
							cout << "input y or n\n";
						}
						else {
							break;
						}
					}
					if (str == 'y') {
						system("cls");
						return 0;
					}
					else {
						return 1;
					}
				}
			}
			else {
				wrong_input();
				continue;
			}
			system("cls");
			print();
		}
		return 0;
	}
public:
	int wins, lose;
	void start() {
		while (1) {
			stdinp();
			init();
			spmine();
			init_cou();
			system("cls");
			print();
			if (game())
				break;
		}
		cout << "Your score\nWins : " << wins << "\nLoses : " << lose << '\n';
	}
};

find_mine m;

int main(void) {
	m.start();
}