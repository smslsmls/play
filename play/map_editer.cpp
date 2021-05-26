#include <windows.h>
#include <tchar.h>
#include <stdio.h>

HANDLE hStdin;
HANDLE hStdout;
DWORD fdwSaveOldMode;
COORD zero;
COORD position;

VOID ErrorExit(LPCSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

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

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE || hStdout == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	cout << "맵 사이즈를 입력하세요 : ";
	cin >> N >> M;
	clear();

	while (con)
	{

		if (!ReadConsoleInput(
			hStdin,
			irInBuf,
			128,
			&cNumRead))
			ErrorExit("ReadConsoleInput");

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
					break;
				}

				break;

			default:
				ErrorExit("Unknown event type");
				break;
			}
		}
	}

	SetConsoleMode(hStdin, fdwSaveOldMode);

	return 0;
}

VOID ErrorExit(LPCSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

VOID KeyEventProc(KEY_EVENT_RECORD ker)
{
	printf("Key event: ");
	printf("%c ", ker.uChar.AsciiChar);
	if (ker.bKeyDown)
		printf("key pressed\n");
	else printf("key released\n");
}

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	printf("Mouse event: ");
	printf("%d %d ", mer.dwMousePosition.X, mer.dwMousePosition.Y);
	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			printf("left button press \n");
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			printf("right button press \n");
		}
		else
		{
			printf("button press\n");
		}
		break;
	case DOUBLE_CLICK:
		printf("double click\n");
		break;
	case MOUSE_HWHEELED:
		printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		printf("mouse moved\n");
		break;
	case MOUSE_WHEELED:
		printf("vertical mouse wheel\n");
		break;
	default:
		printf("unknown\n");
		break;
	}
}

VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
	printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}

void map_print() {
	SetconsoleCursorPosition(hStdout, zero);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2) {
				SetConsoleTextAttribute(hStdout, 6);
			}
			else if (map[i][j] == 1) {
				SetConsoleTextAttribute(hStdout, 11);
			}
			else if (map[i][j] == 9)
				SetConsoleTextAttribute(hStdout, 4);
			else
				SetConsoleTextAttribute(hStdout, 0);
			cout << "■";
		}
		cout << '\n';
	}
}

void clear(){
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