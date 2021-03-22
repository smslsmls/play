#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int test_main() {
	int a;
	while (1) {
		if (_kbhit()) {
			a = _getch();
			cout << a << '\n';
		}
	}
}