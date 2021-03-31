#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class _2048 {
private:
	//상수 선언
	int X[4] = { 1,0,-1,0 };//X이동
	int Y[4] = { 0,1,0,-1 };//Y이동
	//기본변수 선언
	int N, M;//10,10 맵 크기
	int score;//점수
	int map[15][15];//맵
	int ch[15][15];//바뀌었는지 체크
	int print_buffer[15];//출력버퍼
	int print_now;//출력시 사용변수
	int inp;//입력
	int move;//이동위치
	int check;//이동하였는지 체크
	int bignum;//최대 숫자
	int con;//계속 플레이
	char yn;//재시작, 끝내기
	//초기화
	void init() {
		system("cls");
		srand((unsigned int)time(NULL));
		memset(map, 0, sizeof(map));
		score = 0;
		bignum = 0;
		con = 0;
	}
	//기본 인풋
	void stdinp() {
		while (1) {
			cin.clear();
			cin >> N >> M;
			if (N > 10 || N < 2 || M > 10 || M < 2) {
				wrong_input();
				cout << "select 2~10\n";
			}
			else
				break;
		}
	}
	//맵 출력
	void print() {
		cout << " ";
		for (int i = 1; i <= M * 5 - 1; i++)
		{
			if (i % 5 == 0)
				cout << ' ';
			else
				cout << '-';
		}
		cout << '\n';
		for (int i = 1; i <= N; i++)
		{
			memset(print_buffer, 0, sizeof(print_buffer));
			cout << "|";
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] == 0)
					cout << "    ";
				else if (map[i][j] < 10)
					cout << "  " << map[i][j] << ' ';
				else if (map[i][j] < 100)
					cout << " " << map[i][j] << ' ';
				else if (map[i][j] < 1000)
					cout << ' ' << map[i][j];
				else if (map[i][j] < 10000)
					cout << map[i][j];
				else if (map[i][j] < 100000) {
					print_now = map[i][j];
					print_buffer[j] = print_now % 10;
					print_now /= 10;
					cout << print_now;
				}
				else if (map[i][j] < 1000000) {
					print_now = map[i][j];
					print_buffer[j] = print_now % 100;
					print_now /= 100;
					cout << print_now;
				}
				else if (map[i][j] < 10000000) {
					print_now = map[i][j];
					print_buffer[j] = print_now % 1000;
					print_now /= 1000;
					cout << print_now;
				}
				else if (map[i][j] < 100000000) {
					print_now = map[i][j];
					print_buffer[j] = print_now % 10000;
					print_now /= 10000;
					cout << print_now;
				}
				cout << "|";
			}
			cout << "\n|";
			for (int j = 1; j <= M; j++)
			{
				if (print_buffer[j] == 0)
					cout << "    ";
				else if (print_buffer[j] < 10)
					cout << "  " << print_buffer[j] << ' ';
				else if (print_buffer[j] < 100)
					cout << ' ' << print_buffer[j] << ' ';
				else if (print_buffer[j] < 1000)
					cout << ' ' << print_buffer[j];
				else if (print_buffer[j] < 10000)
					cout << print_buffer[j];
				cout << "|";
			}
			cout << "\n ";
			for (int j = 1; j <= M * 5 - 1; j++)
			{
				if (j % 5 == 0)
					cout << ' ';
				else
					cout << '-';
			}
			cout << '\n';
		}
		cout << "\nscore : " << score << "\n\n\n";
	}
	//2,4 생성
	void summon() {
		int ran = rand() % 10;
		int n;
		int rx, ry;
		if (ran)
			n = 2;
		else
			n = 4;
		while (1) {
			rx = rand() % M;
			ry = rand() % N;
			rx++; ry++;
			if (map[ry][rx])
				continue;
			map[ry][rx] = n;
			break;
		}
	}
	//에러 메시지
	void wrong_input() {
		system("cls");
		cout << "incollect input!\n";
	}
	//움직일 수 있는지 확인
	int empty() {
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (!map[i][j] || nch(j, i))
					return 0;
			}
		}
		return 1;
	}
	//주변과 내가 같은지 확인
	int nch(int x, int y) {
		if (!map[y][x])
			return 0;
		for (int i = 0; i < 4; i++)
		{
			if (map[y][x] == map[y + Y[i]][x + X[i]])
				return 1;
		}
		return 0;
	}
	//이동 위
	int moveup() {
		int re = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				move = i;
				for (int t = i - 1; t > 0; t--)
				{
					if (map[t][j] != 0) {
						if (map[i][j] == map[t][j] && ch[t][j] == 0) {
							map[i][j] *= 2;
							score += map[i][j];
							bignum = (map[i][j] > bignum) ? map[i][j] : bignum;
							ch[t][j] = 1;
							move = t;
						}
						break;
					}
					else
						move = t;
				}
				map[move][j] = map[i][j];
				if (move != i && map[i][j] != 0) {
					map[i][j] = 0;
					re = 1;
				}
			}
		}
		system("cls");
		return re;
	}
	//이동 왼쪽
	int moveleft() {
		int re = 0;
		for (int j = 1; j <= M; j++)
		{
			for (int i = 1; i <= N; i++)
			{
				move = j;
				for (int t = j - 1; t > 0; t--)
				{
					if (map[i][t] != 0) {
						if (map[i][j] == map[i][t] && ch[i][t] == 0) {
							map[i][j] *= 2;
							score += map[i][j];
							bignum = (map[i][j] > bignum) ? map[i][j] : bignum;
							ch[i][t] = 1;
							move = t;
						}
						break;
					}
					else {
						move = t;
						re = 1;
					}
				}
				map[i][move] = map[i][j];
				if (move != j && map[i][j] != 0)
					map[i][j] = 0;
			}
		}
		system("cls");
		return re;
	}
	//이동 아래
	int movedown() {
		int re = 0;
		for (int i = N; i > 0; i--)
		{
			for (int j = M; j > 0; j--)
			{
				move = i;
				for (int t = i + 1; t <= N; t++)
				{
					if (map[t][j] != 0) {
						if (map[i][j] == map[t][j] && ch[t][j] == 0) {
							map[i][j] *= 2;
							score += map[i][j];
							bignum = (map[i][j] > bignum) ? map[i][j] : bignum;
							ch[t][j] = 1;
							move = t;
						}
						break;
					}
					else
						move = t;
				}
				map[move][j] = map[i][j];
				if (move != i && map[i][j] != 0) {
					map[i][j] = 0;
					re = 1;
				}
			}
		}
		system("cls");
		return re;
	}
	//이동 오른쪽
	int moveright() {
		int re = 0;
		for (int j = M; j > 0; j--)
		{
			for (int i = N; i > 0; i--)
			{
				move = j;
				for (int t = j + 1; t <= M; t++)
				{
					if (map[i][t] != 0) {
						if (map[i][j] == map[i][t] && ch[i][t] == 0) {
							map[i][j] *= 2;
							score += map[i][j];
							bignum = (map[i][j] > bignum) ? map[i][j] : bignum;
							ch[i][t] = 1;
							move = t;
						}
						break;
					}
					else {
						move = t;
						re = 1;
					}
				}
				map[i][move] = map[i][j];
				if (move != j && map[i][j] != 0)
					map[i][j] = 0;
			}
		}
		system("cls");
		return re;
	}
	//게임
	int game() {
		while (!empty()) {
			if (_kbhit()) {
				inp = _getch();
				if (inp == 224) {
					inp = _getch();
					memset(ch, 0, sizeof(ch));
					check = 0;
					switch (inp)
					{
					case 72:
						if (moveup())
							check = 1;
						break;
					case 75:
						if (moveleft())
							check = 1;
						break;
					case 80:
						if (movedown())
							check = 1;
						break;
					case 77:
						if (moveright())
							check = 1;
						break;
					default:
						system("cls");
						break;
					}
					if (check) {
						if (bignum >= 2048 && con == 0) {
							cout << "You make 2048!\nDo you want to play continue? y/n\n";
							cin >> yn;
							while (yn != 'y' && yn != 'n') {
								wrong_input();
								cin >> yn;
							}
							if (yn == 'n') {
								cout << "Do you want to play again? y/n\n";
								cin >> yn;
								while (yn != 'y' && yn != 'n') {
									wrong_input();
									cin >> yn;
								}
								if (yn == 'y')
									return 1;
								else
									return 0;
							}
							else
								con = 1;
						}
						summon();
					}
					print();
				}
			}
		}
		system("cls");
		print();
		cout << "game over!\nscore : " << score << "\nDo you want to play again? y/n\n";
		while (1) {
			cin >> yn;
			if (yn != 'y' && yn != 'n') {
				system("cls");
				wrong_input();
				cout << "input y/n\n";
			}
			else {
				if (yn == 'y')
					return 1;
				if (yn == 'n')
					return 0;
			}
		}
	}
public:
	void start() {
		while (1) {
			init();
			stdinp();
			summon();
			summon();
			system("cls");
			print();
			if (!game())
				break;
		}
	}
};

_2048 _2_0_4_8;

int main() {
	_2_0_4_8.start();

	return 0;
}