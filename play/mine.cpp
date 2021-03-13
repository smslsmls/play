#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
using namespace std;

class find_mine {
private:
	//grid 선언
	typedef struct {
		int y;
		int x;
	}grid;
	//기본 변수 선언
	int mine[35][70] = {};//29,60
	int cou[35][70] = {};
	int open[35][70] = {};
	int check[35][70] = {};
	int X[8] = { 1,0,-1,-1,-1,0,1,1 };
	int Y[8] = { 1,1,1,0,-1,-1,-1,0 };
	int rp;
	//입력변수 선언
	int N, M, cmine;
	int input, n;
	grid inpg;
	//에러 확인 변수
	int e;

	//주변 지뢰 갯수 반환
	int fmine(int y, int x) {
		int f = 0;
		for (int i = 0; i < 8; i++)
		{
			if (mine[y + Y[i]][x + X[i]] == 1)
				f++;
		}
		return f;
	}
	//주변 표시 갯수 반환
	int count_check(int y, int x) {
		int c = 0;
		for (int i = 0; i < 8; i++)
		{
			if (check[y + Y[i]][x + X[i]])
				c++;
		}
		return c;
	}
	//맵 출력
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
	//한 점 출력
	void printp(int y, int x) {
		if (check[y][x] == 1) {
			cout << "ㅇ";
		}
		else if (open[y][x] == 0)
			cout << "ㅁ";
		else {
			if (cou[y][x])
				cout << ' ' << cou[y][x];
			else
				cout << "  ";
		}
	}
	//한 점 열기(DFS)
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
	//한 점 열기 확인
	int opche(int y, int x) {
		if (mine[y][x] == 0) {
			op(y, x);
			rp = -1;
			return 1;
		}
		else {
			system("cls");
			cout << "game over!\n\n\nDo you want to play again? y/n\n";
			char str;
			while (1) {
				cin >> str;
				if (str!='y'&&str!='x') {
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
	//기본 배열 초기화, 랜덤 시드 초기화
	void init() {
		memset(mine, 0, sizeof(mine));
		memset(open, 0, sizeof(open));
		memset(check, 0, sizeof(check));
		srand((unsigned int)time(NULL));
	}
	//오류메시지 출력
	void wrong_input() {
		system("cls");
		print();
		cout << "incollect selection\n";
	}
	//기본 인풋
	void stdinp() {
		e = 0;
		cin >> N >> M >> cmine;
		if (N < 1 || N>29 || M < 1 || M>60 || cmine<1 || cmine>N * M - 1)
			system("cls");
		if (N < 1 || N>29) {
			cout << "select wigth 1~29\n";
			e++;
		}
		if (M < 1 || M>60) {
			cout << "select length 1~60\n";
			e++;
		}
		if (cmine<1 || cmine>N * M - 1) {
			cout << "select mine under area\n";
			e++;
		}
		return;
	}
	//지뢰 생성
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
	//cou초기화
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
		tmp.x = input % M;
		return tmp;
	}
public:
	void start() {
		while (1) {
			stdinp();
			if (e)
				continue;
			init();
			spmine();
			init_cou();
			system("cls");
			print();
			while (1) {
				cin >> n >> input;
				inpg = ch(input);
				if (inpg.y <= 0 || inpg.y > N || inpg.x <= 0 || inpg.x > M) {
					wrong_input();
					continue;
				}
				if (n == 0) {//칸 열기
					if (open[inpg.y][inpg.x] == 1) {
						if (cou[inpg.y][inpg.x] == count_check(inpg.y, inpg.x)) {
							for (int i = 0; i < 8; i++)
							{
								if (!opche(inpg.y,inpg.x)) {
									break;
								}
							}
							if (rp != -1) {
								if (rp)
									break;
								else
									return;
							}
						}
						else {
							wrong_input();
							continue;
						}
					}
					else {
						if (!opche(inpg.y,inpg.x)) {
							if (rp)
								break;
							else
								return;
						}
					}
				}
				else if (n == 1) {//지뢰 표시
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
					if (open[inpg.y][inpg.x] == 1) {
						wrong_input();
						continue;
					}

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