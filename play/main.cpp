#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<conio.h>
#include"mine.h"
#include"2048.h"
#include"my_tetris.h"
#include"play.h"
#include"rpg.h"
#include"yacht.h"
using namespace std;

find_mine m;
_2048 _2048_;
tetris te;
profiles profile;
rpg RPG;
yacht_game yacht;
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
	m.start();
	//RPG.game();
	//yacht.game();
	//keyboardtest();
}