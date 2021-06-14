#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<conio.h>
#include"mine.h"
#include"2048.h"
#include"rpg.h"
#include"yacht.h"
#include"1-20code.h"
#include"mouseinput.h"
#include"tetris.h"
#include"map_editer.h"
#include"maze.h"
#pragma warning(disable:4996)
using namespace std;

//find_mine m;
//_2048 _2048_;
//rpg RPG;
//yacht_game yacht;
//입력 테스트
void input_test() {
	HANDLE h_in = GetStdHandle(STD_INPUT_HANDLE);
	DWORD console_mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
	INPUT_RECORD input_buf[128];
	DWORD input_size;
	SetConsoleMode(h_in, console_mode);
	while (1) {
		ReadConsoleInput(h_in, input_buf, 128, &input_size);
		for (DWORD i = 0; i < input_size; i++)
		{
			switch (input_buf[i].EventType)
			{
			case KEY_EVENT:
				if (input_buf[i].Event.KeyEvent.bKeyDown)
					printf("%d\n", input_buf[i].Event.KeyEvent.uChar.AsciiChar);
				break;
			case MOUSE_EVENT:
				switch (input_buf[i].Event.MouseEvent.dwEventFlags)
				{
				case 0:
					switch (input_buf[i].Event.MouseEvent.dwButtonState) {
					case FROM_LEFT_1ST_BUTTON_PRESSED:
						printf("left\n");
						break;
					case RIGHTMOST_BUTTON_PRESSED:
						printf("right\n");
						break;
					}
					break;
				case DOUBLE_CLICK:
					printf("double click\n");
					break;
				default:
					break;
				}
			default:
				break;
			}

		}
	}
}

COORD zero = { 0,0 };

void test() {
	fprintf(stderr, "%s\n", "test");
}

int main() {
	//mine_start();
	//_2048_start();
	//rpg_start();
	//yacht_start();
	//_1_20_main();
	//tetris_start();
	//mouseinput();
	//input_test();
	//test();
	//map_editer();
	make_maze();
}