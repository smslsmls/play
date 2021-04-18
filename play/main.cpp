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
using namespace std;

//find_mine m;
//_2048 _2048_;
//rpg RPG;
//yacht_game yacht;
void keyboardtest() {
	int t;
	while (1) {
		if (_kbhit()) {
			t = _getch();
			cout << t << '\n';
		}
	}
}

int main() {
	//mine_start();
	//_2048_start();
	//rpg_start();
	//yacht_start();
	//_1_20_main();
	//tetris_start();
	//mouseinput();
	keyboardtest();
}