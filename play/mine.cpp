#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<Windows.h>
#include<tchar.h>
#include"mine.h"
#define BUFSIZE 128
using namespace std;

class find_mine {
private:
	//pair 선언
	typedef pair<string, pair<int, int>> p;
	//grid 선언
	typedef struct {
		int y;
		int x;
	}grid;
	//기본 변수 선언
	int mine[35][70] = {};//27,58
	int cou[35][70] = {};//주변지뢰갯수
	int open[35][70] = {};//열렸는지 확인
	int check[35][70] = {};//지뢰 체크
	int X[8] = { 1,0,-1,-1,-1,0,1,1 };//X이동
	int Y[8] = { 1,1,1,0,-1,-1,-1,0 };//Y이동
	int rp;//재시작 확인 변수
	int wins, loses;//승패
	string name;//파일입출력 이름
	set<string> s;//파일입출력 이름 저장
	map<string, pair<int, int>> data;//파일입출력 데이터 저장
	DWORD consolemode;//콘솔 모드 설정 변수
	DWORD oldconsolemode;//이전 콘솔 모드
	DWORD inputsize;//입력 크기
	HANDLE h_in, h_out;//입출력 핸들
	int con;//반복 탈출
	COORD mouse_grid;//마우스 위치
	grid first_input;
	//입력변수 선언
	int N, M, cmine;//맵크기, 지뢰갯수
	int input, n;//입력
	grid inpg;//입력 좌표
	INPUT_RECORD in_buf[BUFSIZE];//입력 버퍼
	int double_click;//더블클릭 확인 변수
	MOUSE_EVENT_RECORD input_status;//마우스 상태
	//에러 확인 변수
	int e;

	//다시시작
	int replay(int wl) {
		if (wl == 1) {
			cout << "You Win!!\n";
			wins++;
		}
		else {
			cout << "You lose!\n";
			loses++;
		}
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
	//마우스 입력
	grid mouseinput() {
		grid input_grid;
		con = 1;
		SetConsoleMode(h_in, consolemode);
		while (con) {
			ReadConsoleInput(h_in, in_buf, BUFSIZE, &inputsize);
			for (DWORD i = 0; i < inputsize; i++)
			{
				if (in_buf[i].EventType == MOUSE_EVENT) {
					input_status = in_buf[i].Event.MouseEvent;
					mouse_grid = input_status.dwMousePosition;
					if (input_status.dwEventFlags != 0 && input_status.dwEventFlags != DOUBLE_CLICK)
						continue;
					switch (input_status.dwEventFlags)
					{
					case 0:
						if (input_status.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
							n = 0;
						if (input_status.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
							n = 1;
						break;
					case DOUBLE_CLICK:
						n = 2;
						break;
					default:
						break;
					}
					input_grid = { input_status.dwMousePosition.X ,input_status.dwMousePosition.Y };
					if (input_grid.x > 0 && input_grid.y > 0 && input_grid.x <= N && input_grid.y / 2 <= M)
						con = 0;
					input_grid = { input_grid.x,input_grid.y / 2 };
				}
			}
		}
		return input_grid;
	}
	//파일로 데이터 받기  *실패
	void data_init() {
		ifstream file;
		file.open("data.txt");

		if (file.is_open())
		{
			while (!file.eof())
			{
				string str;
				getline(file, str);
				p tmp;
				if (s.find(tmp.first) == s.end()) {
					s.insert(tmp.first);
					data[tmp.first] = tmp.second;
				}
				else {
					char a;
					while (1) {
						cout << "Data is already inserted\nDo you want to change? y/n\n";
						cin >> a;
						if (a != 'y' && a != 'n') {
							wrong_input();
						}
						else
							break;
					}
					if (a == 'y')
						data[tmp.first] = tmp.second;
				}
			}
			file.close();
		}
	}
	//string을 pair로 변환
	p str_to_pair(string a) {
		p out;
		string str_arr[1000];
		int str_cnt = 0;

		char* str_buff = new char[1000];
		strcpy(str_buff, a.c_str());

		char* tok = strtok(str_buff, " ");
		while (tok != nullptr) {
			str_arr[str_cnt++] = string(tok);
			tok = strtok(nullptr, " ");
		}

		out.first = str_arr[0];
		out.second.first = stoi(str_arr[1]);
		out.second.second = stoi(str_arr[2]);

		return out;
	}
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
		SetConsoleCursorPosition(h_out, { 0,0 });
		cout << " ";
		for (int i = 1; i <= M; i++)
		{
			cout << "--";
		}
		cout << "\n";
		for (int i = 1; i <= N; i++)
		{
			cout << '|';
			for (int j = 1; j <= M; j++)
			{
				printp(i, j);
				//cout << mine[i][j];
			}
			cout << '|';
			cout << '\n';
		}
		cout << " ";
		for (int i = 0; i < M; i++)
		{
			cout << "--";
		}
		cout << "\n";
	}
	//한 점 출력
	void printp(int y, int x) {
		if (open[y][x] == 0) {
			if (check[y][x] == 1) {
				cout << "ㅇ";
			}
			else
				cout << "ㅁ";
		}
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
			cout << "game over!\n\n\n";
			loses++;
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
		SetConsoleMode(h_in, oldconsolemode);
		while (1) {
			e = 0;
			cin >> N >> M >> cmine;
			if (N < 4 || N>27 || M < 4 || M>58 || cmine<1 || cmine>N * M - 1)
				system("cls");
			if (N < 4 || N>27) {
				cout << "select wigth 4~27\n";
				e++;
			}
			if (M < 4 || M>58) {
				cout << "select length 4~58\n";
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
		tmp.y = (input / M) + 1;
		tmp.x = input % M;
		if (tmp.x == 0) {
			tmp.x = M;
			tmp.y--;
		}
		return tmp;
	}
	//게임
	int game() {
		while (1) {
			inpg = mouseinput();
			SetConsoleMode(h_in, oldconsolemode);
			if (n == 0) {//칸 열기
				if (!opche(inpg.y, inpg.x)) {
					if (rp)
						break;
					else
						return 1;
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
				if (cmine == 0) {
					
				}
			}
			else {
				if (cou[inpg.y][inpg.x] && cou[inpg.y][inpg.x] == count_check(inpg.y, inpg.x)) {
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
					continue;
				}
			}
			system("cls");
			print();
		}
		return 0;
	}
public:
	find_mine() {
		consolemode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
		h_in = GetStdHandle(STD_INPUT_HANDLE);
		h_out = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleMode(h_in, &oldconsolemode);
	}
	//시작
	void start() {
		while (1) {
			init();
			stdinp();
			spmine();
			init_cou();
			system("cls");
			print();
			if (game())
				break;
		}
		cout << "Your score\nWins : " << wins << "\nLoses : " << loses << '\n';

	}
};

void mine_start() {
	find_mine mine;
	mine.start();
}