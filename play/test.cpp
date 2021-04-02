#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<conio.h>
#include"rpg.h"
#include"2048.h"
#include"mine.h"
#include"play.h"
#include"tetris.h"
using namespace std;

find_mine m;
_2048 _2_0_4_8;
tetris te;
profiles profile;
rpg RPG;
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	RPG.game();
}