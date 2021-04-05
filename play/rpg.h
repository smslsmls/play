#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
enum job_classes;
enum buffs;
enum debuffs;
enum enum_rarity;
enum weapons;
class stat_struct;
bool random(double per);
class select_class;
class player;
class rpg;
//����
class stat_struct {
public:
	unsigned short STR = 0;//���� hp 2 atk 3
	unsigned short INT = 0;//���� mp 5
	unsigned short WIS = 0;//���� mp 3 hp 2
	unsigned short DEX = 0;//���� def 3 hp 2
	unsigned short AGI = 0;//��ø�� atk 1 cri 4
	unsigned short VIT = 0;//ü�� hp 4 def 1
};
//���� ����
typedef struct {
	string name;
	enum_rarity rarity;
	int weapon_skill_code;
	stat_struct plus_stat;
}weapon_status;
//�������ͽ�
typedef struct {
	int hp;
	int mp;
	int atk;
	int def;
	int cri;
}status;
//������ ����ü
typedef struct {
	string arr[100];
	int SIZE;
}selection_array;
//���� ����ü
typedef struct {
	string arr[1000];
	int idx;
}inventory;
//����
enum job_classes {
	//����
	//�����Ǿ�
	DUELER = 0,//0
	//��, ����, �۷���
	FIGHTER,//1
	//�ܰ�, ���
	ASSASSIN,//2
	//â
	LANCER,//3
	//���, ����
	WARRIOR,//4
	//�ظ�
	BRACKSMITH,//5
	//����
	LUMBERJACK,//6
	//Ȱ
	ARCHER,//7
	//����
	CLOSSBOWER,//8
	//����, ������, ����, ����
	SOLDIER,//9
	//����
	SNIPER,//10
	//������, ����
	ASSAULT,//11
	//���� ��繫��
	//���� ��� ��
	WEAPONMASTER,//12
	//����
	//������,�ϵ�
	//�κ�
	WIZARD//13
};
//���� �����
enum buffs {
	//���
	REGENERATION = 0,
	//��
	STRENGTH,
	//����
	RESISTANCE,
	//��ø
	AGILITY,
	//����, ��
	REINFORCE,
	//����ȣ��(�ٴ�������)
	WATERBREATHING,
	//���(��ȸ�� ü��)
	ABSORPTION,
	//��ƿ������(���ݷ°� ������ ���� �ɷ�ġ�� ȹ��)
	UTILIZE
};
//�����
enum debuffs {
	//��
	POISON = 0,
	//��ȭ(���ݷ� ����)
	WEAKNESS,
	//��������
	SHIELDBREAK,
	//��üȭ(���ݷ�, ���� ����)
	WEAKENING,
	//��ø�� ����
	SLOWNESS,
	//����
	STUN,
	//�Ǹ�
	BLIND,
	//ħ��
	SILENCE,
	//����
	TAUNT
};
//��͵�
enum enum_rarity {
	COMMON,
	UNCOMMON,
	RARE,
	EPIC,
	LEGENDARY,
	RELIC,
	CONTRABAND,
	UNOBTAINABLE
};
enum weapons {
	//�����Ǿ�
	//����
	EPEE,
	//�÷ڷ�
	FLEURET,
	//�����ҵ�
	SMALLSWORD,
	//�����Ĵ� �����
	ESPADAROPERA,
	//�̽�ƿ����
	MISTILTEINN,
	//��
	//�ռҵ�
	LONGSWORD,
	//��Ű���ҵ�
	VALKYRIESWORD,
	//�۶��콺
	GLADIUS,
	//�ٽ�Ÿ��ҵ�
	BASTARDSWORD,
	//�������Ÿ��
	FUTSUNOMITAMA,
	//�ַ��
	DOUBLEDRAGONSWORD,
	//����Į����
	EXCALIBUR,
	//���ν�������
	DAINSLEIF,
	//Ŭ���̸��
	CLAYMORE,
	//����������
	FLAMBERGE,
	//��ü��
	MACHETE,
	//�ù���
	SCIMITAR,
	//��ũ��
	KUKRI,
	//�Ƚÿ�, �޼�
	FALCHION,
	//������
	//Ƽ����
	TYRFINGR,
	//�ܰ�
	//���
	DAGGER,
	//���ΰ�
	MAINGAUCHE,
	//Ŭ���ֶ�
	CLAIOMHSOLAIS,
	//�ҵ�극��Ŀ
	SWORDBREAKER,
	//â
	//�ôϸ�
	GUNGNIR,
	//�ձ⴩����â
	LONGINUS,
	//����
	RUIN,
	//Ʈ�����̳�(�����̵��� â)
	TRIAINA,
	//Ʈ������(�ε��� �ı��� �� �ù��� â)
	TRIDENT,
	//���
	//�巡�ｽ���̾�
	DRAGONSLAYER,
	//�෣��, �ڶ���
	DURANDAL,
	//�׶�
	GRAM,
	//��������
	LAEATEINN,
	//�߹�
	BALMUNG,
	//�Ʒд���Ʈ
	ARONDIGHT,
	//�����۽�
	ECKESACHS,
	//��ġ
	//���ϸ�
	MOLNIR,
	//���������� ��ġ
	BLACKSMITHHAMMER
};
weapon_status weapons_status[] = {
	{
		"����",UNCOMMON,0,{}

}
}
//����Ȯ��   0<per<1
bool random(double per) {
	if (per <= 0)
		return false;
	else if (per >= 1)
		return true;
	long long n = 1;
	long long tmp = (int)per;
	while (per != (int)per) {
		per *= 10.0;
		tmp *= 10;
		tmp += (int)per;
		n *= 10;
	}
	int ra = rand() % n;
	return ra < tmp;
}
//���ÿ� Ŭ����
class select_class {
private:
	int now_select = 0;
	string arr[100];
	//������ �̸� ���
	void print_select_selection() {
		system("cls");
		int s = bsize();
		int strs;
		int r, l;
		int c = 0;
		int st;
		cout << ' ';
		for (int i = 0; i < s + 4; i++)
		{
			cout << '-';
		}
		cout << "\n";
		if (size > 10) {
			if (now_select < 5)
				st = 0;
			else if (now_select >= size - 5)
				st = size - 11;
			else
				st = now_select - 5;
			for (int i = st; i <= st + 10; i++)
			{
				c++;
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
		}
		else {
			for (int i = 0; i < size; i++)
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
		}
		cout << ' ';
		for (int i = 0; i < s + 4; i++)
		{
			cout << '-';
		}
		cout << '\n';
	}
	//������ �̸� ���� ū �� ��ȯ
	int bsize() {
		int big = 0;
		int t;
		for (int i = 0; i < size; i++)
		{
			t = arr[i].size();
			if (t > big)
				big = t;
		}
		return big;
	}
public:
	int size;
	//������ ����
	int select_selection() {
		now_select = -1;
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
							now_select = size - 1;
						break;
					case 80:
						now_select++;
						if (now_select >= size)
							now_select = 0;
						break;
					default:
						break;
					}
					system("cls");
					print_select_selection();
				}
				if (t == 13) {
					if (now_select != -1)
						return now_select;
				}
				if (t == 27)
					return size;
			}
		}
	}
	//������ �ޱ�
	void init(string a[100]) {
		int t = 0;
		string tmp;
		for (int i = 0; i < 100; i++)
		{
			if (a[i] == tmp)
				break;
			t++;
		}
		size = t;
		for (int i = 0; i < size; i++)
		{
			arr[i] = a[i];
		}
	}
};
//��� Ŭ����
class player {
private:
	job_classes job;
	stat_struct statistics;
	status basic_stat;
	status stat;
	buffs buff;
	debuffs debuff;
protected:

public:
	void init() {
		stat.hp = basic_stat.hp + statistics.STR * 2 + statistics.VIT * 4 + statistics.WIS * 2 + statistics.DEX * 2;
		stat.mp = basic_stat.mp + statistics.INT * 5 + statistics.WIS * 3;
		stat.atk = basic_stat.atk + statistics.STR * 3 + statistics.AGI;
		stat.def = basic_stat.def + statistics.DEX * 3 + statistics.VIT;
		stat.cri = basic_stat.cri + statistics.AGI * 4;
	}
};

class rpg {
private:
	int selection;
	string maps[100] = {
		"����",
		"�ʿ�","��","��ο� ��",
		"������ ��","��� ���","��ũ�� ����","������ ����","������ ��",
		"���� ��","���ϵ���",
		"������ ����","��Ÿ�� ����",
		"��ũ��������","����",
		"����","õ��","���ɰ�",
		"���� ��ó"
	};
	string title[100] = {
		"���ӽ���",
		"�̾��ϱ� *���߿���",
		"������"
	};
	string town[100] = {
		"��ȭ",
		"����",
		"���",
		"��ų",
		"â��",
		"������"
	};
	inventory inven = { {},0 };
	inventory skills = { {},0 };
public:
	select_class map_select;
	select_class title_select;
	select_class town_select;

	//�ʱ�ȭ
	rpg() {
		map_select.init(maps);
		title_select.init(title);
		town_select.init(town);
	}
	int select_title() {
		selection = -1;
		while (1) {
			selection = title_select.select_selection();
			if (selection == 0)
				return 0;
			else if (selection == 1) {
				cout << "�˼��մϴ�.\n�̾��ϱ� ����� �������Դϴ�.\n�ƹ�Ű�� ��������.";
				while (1) {
					if (_kbhit()) {
						break;
					}
				}
			}
			else if (selection == 2 || selection == title_select.size)
				return -1;
		}
	}
	//����
	void game() {
		if (select_title() == -1)
			return;
		while (1) {
			selection = map_select.select_selection();
			if (selection != map_select.size) {
				if (maps[selection] == "����") {
					while (1) {
						selection = town_select.select_selection();
						if (selection != town_select.size) {
							if (town[selection] == "������")
								break;
							cout << "������ " << town[selection] << "�Դϴ�.";
							break;
						}
					}
					if (town[selection] == "������")
						continue;
				}
				else
					cout << "������ " << maps[selection] << "�Դϴ�.";
				break;
			}
		}
	}
};