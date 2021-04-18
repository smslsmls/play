#include<bits/stdc++.h>
#include<conio.h>
#include"yacht.h"
using namespace std;
class yacht_game {
private:
	int dice[7], lock[7];
	int dice_dot[10] = {};
	int select_arr[4][6];
	int number[10];
	int sum, four_of_kind, full_house, sstaight, bstraight, yacht;
	int select = 0;
	int key;
public:
	yacht_game() {
		srand((unsigned int)time(NULL));
	}
	void roll() {
		memset(dice_dot, 0, sizeof(dice_dot));
		sum = 0;
		four_of_kind = 0;
		full_house = 0;
		sstaight = 0;
		bstraight = 0;
		yacht = 0;
		for (int i = 0; i < 5; i++)
		{
			if (lock[i])
				continue;
			dice[i] = (rand() % 6) + 1;
			dice_dot[dice[i]]++;
			sum += dice[i];
		}
		for (int i = 1; i <= 6; i++)
		{
			number[i] = dice_dot[i] * i;
		}
		for (int i = 1; i <= 6; i++)
		{
			if (dice_dot[i] >= 4)
				four_of_kind = i * 4;
			if (dice_dot[i] == 5)
				yacht = 50;
		}
		for (int i = 1; i <= 6; i++)
		{
			for (int j = 1; j <= 6; j++)
			{
				if (dice_dot[i] == 2 && dice_dot[j] == 3)
					full_house = i * 2 + j * 3;
			}
		}
		for (int i = 1; i <= 3; i++)
		{
			if (dice_dot[i] && dice_dot[i + 1] && dice_dot[i + 2] && dice_dot[i + 3])
				sstaight = 15;
		}
		for (int i = 1; i <= 2; i++)
		{
			if (dice_dot[i] && dice_dot[i + 1] && dice_dot[i + 2] && dice_dot[i + 3] && dice_dot[i + 4])
				bstraight = 30;
		}
	}
	void print() {
		sort(dice, dice + 5);
		cout << " Aces  " << number[1] << "   Choice    " << sum << '\n';
		cout << "Deuces " << number[2] << " 4 of a Kind " << four_of_kind << '\n';
		cout << "Threes " << number[3] << " Full House  " << full_house << '\n';
		cout << " Fours " << number[4] << " S. Straight " << sstaight << '\n';
		cout << " Fives " << number[5] << " L. Straight " << bstraight << '\n';
		cout << " Sixes " << number[6] << "    Yacht    " << yacht << '\n';
		cout << '\n';
		cout << " ---------- \t ---------- \t ---------- \t ---------- \t ---------- \n";
		for (int i = 0; i < 5; i++)
		{
			cout << "|          |\t";
		}
		cout << '\n';
		for (int i = 0; i < 5; i++)
		{
			if (i==select) {
				switch (dice[i])
				{
				case 1:
				case 2:
				case 3:
					cout << "|          |\t";
					break;
				case 4:
				case 5:
				case 6:
					cout << "|  ¡Û  ¡Û  |\t";
					break;
				default:
					break;
				}
			}
			else if(lock[i]){
				switch (dice[i])
				{
				case 1:
				case 2:
				case 3:
					cout << "|          |\t";
					break;
				case 4:
				case 5:
				case 6:
					cout << "|  ¡Ý  ¡Ý  |\t";
					break;
				default:
					break;
				}
			}
			else {
				switch (dice[i])
				{
				case 1:
				case 2:
				case 3:
					cout << "|          |\t";
					break;
				case 4:
				case 5:
				case 6:
					cout << "|  ¡Ü  ¡Ü  |\t";
					break;
				default:
					break;
				}
			}
		}
		cout << '\n';
		for (int i = 0; i < 5; i++)
		{
			if (i==select) {
				switch (dice[i])
				{
				case 4:
					cout << "|          |\t";
					break;
				case 1:
				case 5:
					cout << "|    ¡Û    |\t";
					break;
				case 2:
				case 6:
					cout << "|  ¡Û  ¡Û  |\t";
					break;
				case 3:
					cout << "| ¡Û ¡Û ¡Û |\t";
					break;
				default:
					break;
				}
			}
			else if(lock[i]) {
				switch (dice[i])
				{
				case 4:
					cout << "|          |\t";
					break;
				case 1:
				case 5:
					cout << "|    ¡Ý    |\t";
					break;
				case 2:
				case 6:
					cout << "|  ¡Ý  ¡Ý  |\t";
					break;
				case 3:
					cout << "| ¡Ý ¡Ý ¡Ý |\t";
					break;
				default:
					break;
				}
			}
			else {
				switch (dice[i])
				{
				case 4:
					cout << "|          |\t";
					break;
				case 1:
				case 5:
					cout << "|    ¡Ü    |\t";
					break;
				case 2:
				case 6:
					cout << "|  ¡Ü  ¡Ü  |\t";
					break;
				case 3:
					cout << "| ¡Ü ¡Ü ¡Ü |\t";
					break;
				default:
					break;
				}
			}
		}
		cout << '\n';
		for (int i = 0; i < 5; i++)
		{
			if (i == select) {
				switch (dice[i])
				{
				case 1:
				case 2:
				case 3:
					cout << "|          |\t";
					break;
				case 4:
				case 5:
				case 6:
					cout << "|  ¡Û  ¡Û  |\t";
					break;
				default:
					break;
				}
			}
			else if (lock[i]) {
				switch (dice[i])
				{
				case 1:
				case 2:
				case 3:
					cout << "|          |\t";
					break;
				case 4:
				case 5:
				case 6:
					cout << "|  ¡Ý  ¡Ý  |\t";
					break;
				default:
					break;
				}
			}
			else {
				switch (dice[i])
				{
				case 1:
				case 2:
				case 3:
					cout << "|          |\t";
					break;
				case 4:
				case 5:
				case 6:
					cout << "|  ¡Ü  ¡Ü  |\t";
					break;
				default:
					break;
				}
			}
		}
		cout << '\n';
		for (int i = 0; i < 5; i++)
		{
			cout << "|          |\t";
		}
		cout << '\n';
		cout << " ---------- \t ---------- \t ---------- \t ---------- \t ---------- \n";
	}
	void game() {
		while (1) {
			roll();
			print();
			while (1) {
				if (_kbhit()) {
					key = _getch();
					if (key == 224) {
						key = _getch();
						switch (key)
						{
						case 75:
							select--;
							if (select < 0)
								select = 0;
							break;
						case 77:
							select++;
							if (select > 4)
								select = 4;
							break;
						case 72:
							select -= 6;
							if (select < 0)
								select += 6;
						case 80:
							select += 6;
							if (select == 17)
								select = 16;
							if (select > 16)
								select -= 6;
							break;
						default:
							break;
						}
						system("cls");
						print();
					}
					if (key == 114)
						break;
					if (key == 13)
						lock[select] = !lock[select];
				}
			}
		}
	}
};