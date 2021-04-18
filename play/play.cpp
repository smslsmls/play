#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include"play.h"
using namespace std;

class profiles {
private:
	string name;
	int age;
	string motto;
	string school;
public:
	void init(string name, int age, string motto, string school) {
		this->name = name;
		this->age = age;
		this->motto = motto;
		this->school = school;
	}

	void show() {
		cout << "Hello?\nMy name is : " << name << "\n";
		cout << "my age is " << age << '\n';
		cout << "my motto is " << motto << '\n';
		cout << "my school is " << school << '\n';
	}
};

class bitwise_calculator {
private:
	typedef pair<char, char> pa;
	//이진수2개
	string bi1, bi2;
	//크기 같게 하기
	void setsize() {
		string tmp;
		int s1 = bi1.size(), s2 = bi2.size();
		if (s1 == s2)
			return;
		int bs = (s1 > s2) ? s1 : s2;
		int ss = (s1 < s2) ? s1 : s2;
		for (int i = 0; i < bs - ss; i++)
		{
			tmp += '0';
		}
		if (s1 < s2)
			bi1 += tmp;
		else
			bi2 += tmp;
		return;
	}
	//가산기
	pa adder(char b1, char b2){
		bool bo1, bo2;
		if (b1 == '0')
			bo1 = false;
		else
			bo1 = true;
		if (b2 == '0')
			bo2 = false;
		else
			bo2 = true;
		pa tmp;
		if (bo1 != bo2)
			tmp.first = '1';
		else
			tmp.first = '0';
		if (bo1 && bo2)
			tmp.second = '1';
		else
			tmp.second = '0';
		return tmp;
	}
public:
	bitwise_calculator(string b1, string b2, char oper) {
		bi1 = b1;
		bi2 = b2;
		setsize();
	}
};