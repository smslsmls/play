#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
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

profiles profile;

int play_main() {
	profile.init("Youn Seo Joon", 17, "motto", "Deagu Software meister highschool");
	profile.show();
	return 0;
}