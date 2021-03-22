#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class _2048 {
private:
	//기본변수 선언
	int N, M;//10,10
	int score;
	int map[15][15];
	int X[4] = { 1,0,-1,0 };
	int Y[4] = { 0,1,0,-1 };
	int move;
	//초기화
	void init() {
		srand((unsigned int)time(NULL));
		memset(map, 0, sizeof(map));
		score = 0;
	}
	//기본 인풋
	void stdinp() {
		while (1) {
			cin >> N >> M;
			if (N > 10 || N < 0 || M > 10 || M < 0) {
				wrong_input();
				cout << "select 1~10\n";
			}
			else
				break;
		}
	}
	//맵 출력
	void print() {
		cout << " ";
		for (int i = 1; i <= M * 3 - 1; i++)
		{
			cout << '-';
		}
		cout << '\n';
		for (int i = 1; i <= N; i++)
		{
			cout << "|";
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] == 0)
					cout << "  ";
				else
					cout << map[i][j] << ' ';
				cout << "|";
			}
			cout << "\n ";
			for (int i = 1; i <= M * 3 - 1; i++)
			{
				if (i % 3 == 0)
					cout << ' ';
				else
					cout << '-';
			}
			cout << '\n';
		}
	}
	//2,4 생성
	void summon() {
		int ran = rand();
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
				return 0;
		}
		return 1;
	}
	//이동 위
	void moveup() {
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				move = i;
				for (int t = i - 1; t > 0; t--)
				{
					if (map[t][j] != 0) {
						if (map[i][j] == map[t][j]) {
							map[i][j] *= 2;
							move = t;
						}
						break;
					}
					else
						move = t;
				}
				map[move][j] = map[i][j];
				if (move != i)
					map[i][j] = 0;
			}
		}
		//system("cls");
	}
	//이동 왼쪽
	void moveleft() {
		for (int j = 1; j <= N; j++)
		{
			for (int i = 1; i <= M; i++)
			{
				move = j;
				for (int t = i - 1; t > 0; t--)
				{
					if (map[i][t] != 0) {
						if (map[i][j] == map[i][t]) {
							map[i][j] *= 2;
							move = t;
						}
						break;
					}
					else
						move = t;
				}
				map[i][move] = map[i][j];
				if (move != j)
					map[i][j] = 0;
			}
		}
		//system("cls");
	}
	//이동 오른쪽
	void moveright() {
		for (int j = N; j > 0; j--)
		{
			for (int i = M; i > 0; i--)
			{
				move = j;
				for (int t = i + 1; t <= N; t++)
				{
					if (map[i][t] != 0) {
						if (map[i][j] == map[i][t]) {
							map[i][j] *= 2;
							move = t;
						}
						break;
					}
					else
						move = t;
				}
				map[i][move] = map[i][j];
				if (move != j)
					map[i][j] = 0;
			}
		}
		//system("cls");
	}
	//이동 아래
	void movedown() {
		for (int i = N; i > 0; i--)
		{
			for (int j = M; j > 0; j--)
			{
				move = i;
				for (int t = i + 1; t <= N; t++)
				{
					if (map[t][j] != 0) {
						if (map[i][j] == map[t][j]) {
							map[i][j] *= 2;
							move = t;
						}
						break;
					}
					else
						move = t;
				}
				map[move][j] = map[i][j];
				if (move != i)
					map[i][j] = 0;
			}
		}
		//system("cls");
	}
public:
	void start() {
		init();
		stdinp();
		summon();
		summon();
		print();
		map[1][1] = 2;
		map[1][2] = 2;
		map[1][3] = 2;
		moveleft();
		print();
		while (!empty()) {

		}
	}
};

_2048 _2_0_4_8;

int main() {
	_2_0_4_8.start();

	return 0;
}