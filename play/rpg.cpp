#include<bits/stdc++.h>
#include<Windows.h>
#include<tchar.h>
#include"rpg.h"

//핸들
HANDLE in_h, out_h;
//출력 클래스
class print_class {
	COORD grid = { 0,0 };
public:
	void move(int x, int y) {
		grid.X = x;
		grid.Y = y;
	}
	void print(const char str) {
		SetConsoleCursorPosition(out_h, grid);
		std::cout << str;
		grid.Y = grid.Y + 1;
		if (grid.Y > 50)
			grid.Y = 0;
	}
};
//RPG
class rpg {

};




int rpg_game() {
	in_h = GetStdHandle(STD_INPUT_HANDLE);
	out_h = GetStdHandle(STD_OUTPUT_HANDLE);
	return 0;
}