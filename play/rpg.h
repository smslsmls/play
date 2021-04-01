#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class select {
private:
	int now_select = 0;
	string* arr;
	int SIZE;
public:
	//������ �̸� ���� ū �� ��ȯ
	int bsize() {
		int big = 0;
		int t;
		for (int i = 0; i < SIZE; i++)
		{
			t = arr[i].size();
			if (t > big)
				big = t;
		}
		return big;
	}
	//������ �̸� ���
	void print_select_selection() {
		system("cls");
		int s = bsize();
		int strs;
		int r, l;
		cout << ' ';
		for (int i = 0; i < s + 4; i++)
		{
			cout << '-';
		}
		cout << "\n";
		for (int i = 0; i < SIZE; i++)
		{
			cout << '|';
			strs = (s + 4 - arr[i].size());
			r = strs / 2;
			l = r;
			if (strs % 2 == 1)
				r++;
			if (now_select != i) {
				for (int j = 0; j < l; j++)
				{
					cout << ' ';
				}
				cout << arr[i];
				for (int j = 0; j < r; j++)
				{
					cout << ' ';
				}
			}
			else {
				r -= 2;
				l -= 2;
				for (int j = 0; j < l; j++)
				{
					cout << ' ';
				}
				cout << "->" << arr[i] << "<-";
				for (int j = 0; j < r; j++)
				{
					cout << ' ';
				}
			}
			cout << "|\n";
		}
		cout << ' ';
		for (int i = 0; i < s + 4; i++)
		{
			cout << '-';
		}
		cout << '\n';
	}
	//������ ����
	int select_selection() {
		int t;
		print_select_selection();
		while (true)
		{
			if (_kbhit()) {
				t = _getch();
				if (t == 224) {
					t = _getch();
					switch (t)
					{
					case 72:
						now_select--;
						if (now_select < 0)
							now_select = SIZE - 1;
						break;
					case 80:
						now_select++;
						if (now_select >= SIZE)
							now_select = 0;
						break;
					default:
						break;
					}
					system("cls");
					print_select_selection();
				}
				if (t == 13)
					return now_select;
				if (t == 27)
					return -1;
			}
		}
	}
	//������ �ޱ�
	void init(string _arr[], int _SIZE){
		SIZE = _SIZE;
		arr = _arr;
	}
};

class rpg{
private:
	const int MAPSIZE = 18;
	const int TITLESIZE = 3;
	string m[18] = {
		"������ ����","��Ÿ�� ����",
		"���� ��","���ϵ���",
		"�ʿ�","��","��ο� ��",
		"������ ��","��� ���","��ũ�� ����","������ ����","������ ��",
		"��ũ��������","����",
		"����","õ��","���ɰ�",
		"���� ��ó"
	};
	string title[3] = {
		"���ӽ���",
		"����",
		"������"
	};
public:
	select map_select;
	select title_select;
	rpg() {
		map_select.init(m, MAPSIZE);
		title_select.init(title, TITLESIZE);
	}
};