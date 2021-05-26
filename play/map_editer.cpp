#include <windows.h>
#include <tchar.h>
#include <iostream>
#include"map_editer.h"
using namespace std;

HANDLE h_input;
HANDLE h_output;
DWORD console_old_mode;
COORD zero;
COORD position;

VOID Error(LPCSTR);

int map[100][100];
int con = 1;
int x, y;
int N, M;
int ch = 0;

void map_print();
void clear();

int map_editer()
{
	zero.X = 0;
	zero.Y = 0;
	DWORD cNumRead, fdwMode;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	h_input = GetStdHandle(STD_INPUT_HANDLE);
	h_output = GetStdHandle(STD_INPUT_HANDLE);
	if (h_input == INVALID_HANDLE_VALUE || h_output == INVALID_HANDLE_VALUE)
		Error("GetStdHandle");

	if (!GetConsoleMode(h_input, &console_old_mode))
		Error("GetConsoleMode");

	cout << "맵 사이즈를 입력하세요 : ";
	cin >> N >> M;
	clear();

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(h_input, fdwMode))
		Error("SetConsoleMode");

	while (con)
	{

		if (!ReadConsoleInput(
			h_input,
			irInBuf,
			128,
			&cNumRead))
			Error("ReadConsoleInput");

		for (DWORD i = 0; i < cNumRead; i++)
		{
			if (con == 0)
				break;
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT:
				if (irInBuf[i].Event.KeyEvent.uChar.AsciiChar == 13)
					con = 0;
				break;

			case MOUSE_EVENT:
				position = irInBuf[i].Event.MouseEvent.dwMousePosition;
				switch (irInBuf[i].Event.MouseEvent.dwEventFlags)
				{
				case 0:
					if (irInBuf[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						if (map[position.Y][position.X / 2] == 2)
							map[position.Y][position.X / 2] = 0;
						else
							map[position.Y][position.X / 2] = 2;
					}
					else if (irInBuf[i].Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
					{
						if (ch) {
							if (map[position.Y][position.X / 2] == 9)
								map[position.Y][position.X / 2] = 0;
							else
								map[position.Y][position.X / 2] = 9;
							ch = !ch;
						}
						else {
							if (map[position.Y][position.X / 2] == 1)
								map[position.Y][position.X / 2] = 0;
							else
								map[position.Y][position.X / 2] = 1;
							ch = !ch;
						}
					}
					map_print();
					break;
				}
				break;
			}
		}
	}

	SetConsoleMode(h_input, console_old_mode);

	return 0;
}

VOID Error(LPCSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	SetConsoleMode(h_input, console_old_mode);

	ExitProcess(0);
}

void map_print() {
	for (int i = 0; i < N; i++)
	{
		SetConsoleCursorPosition(h_output, zero);
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2) {
				SetConsoleTextAttribute(h_output, 6);
			}
			else if (map[i][j] == 1) {
				SetConsoleTextAttribute(h_output, 11);
			}
			else if (map[i][j] == 9)
				SetConsoleTextAttribute(h_output, 4);
			else
				SetConsoleTextAttribute(h_output, 0);
			cout << "■";
		}
		zero.Y++;
	}
	zero.Y = 0;
}

void clear() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
				map[i][j] = 2;
			else
				map[i][j] = 0;
		}
	}
}