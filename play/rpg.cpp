#include<bits/stdc++.h>
#include<Windows.h>
#include<tchar.h>
#include"rpg.h"

//핸들
HANDLE in_h, out_h;
//출력 클래스
class print_class {
	COORD grid = { 0,0 };
	COORD zero = { 0,0 };
public:
	void move(int x, int y) {
		grid.X = x;
		grid.Y = y;
	}
	void print(char str) {
		zero.X = 0;
		zero.Y = 0;
		SetConsoleCursorPosition(out_h, zero);
		while (zero.Y < grid.Y) {
			for (int i = 0; i < 192; i++)
			{
				cout << " ";
			}
			cout << '\n';
			zero.Y++;
		}
		for (int i = 0; i < grid.Y; i++)
		{
			cout << ' ';
		}
		SetConsoleCursorPosition(out_h, grid);
		std::cout << str;
		grid.Y = grid.Y + 1;
		if (grid.Y > 50)
			grid.Y = 0;
	}
};
//RPG
class rpg : public print_class{

};




int rpg_game() {
	system("mode con: lines=50 cols=192");
	in_h = GetStdHandle(STD_INPUT_HANDLE);
	out_h = GetStdHandle(STD_OUTPUT_HANDLE);
	return 0;
}