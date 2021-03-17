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
	//초기화
	void init() {
		srand((unsigned int)time(NULL));
		memset(map, 0, sizeof(map));
		score = 0;
	}
	//맵 출력
	void print() {
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] == 0)
					cout << "  ";
				else
					cout << map[i][j] << ' ';
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
	//움직일 수 있는지 확인
	int empty() {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if(!map[i][j]||)
			}
		}
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

public:
	void start() {
		init();
		summon();
		summon();
		while (!empty()) {

		}
	}
};

_2048 _2_0_4_8;

int main() {
	_2_0_4_8.start();
}