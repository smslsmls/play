#include<bits/stdc++.h>
#include<conio.h>
#include<Windows.h>
using namespace std;
//����
typedef struct {
	unsigned short STR = 0;//����
	unsigned short INT = 0;//����
	unsigned short WIS = 0;//����
	unsigned short DEX = 0;//����
	unsigned short AGI = 0;//��ø��
	unsigned short VIT = 0;//ü��
}stat_struct;
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
//���� ����
typedef struct {
	string name;
	enum_rarity rarity;
	int weapon_skill_code;
	stat_struct plus_stat;
}weapon_status;
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
	COMMON = 0,
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
	int n = 1;
	while (per != (int)per) {
		per *= 10.0;
		n *= 10;
	}
	int ra = rand() % n;
	return ra < per;
}
//���ÿ� Ŭ����
class select_class {
private:
	int now_select = 0;
	selection_array arr;
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
		if (arr.SIZE > 10) {
			if (now_select < 5)
				st = 0;
			else if (now_select >= arr.SIZE - 5)
				st = arr.SIZE - 11;
			else
				st = now_select - 5;
			for (int i = st; i <= st + 10; i++)
			{
				c++;
				cout << '|';
				strs = (s + 4 - arr.arr[i].size());
				r = strs / 2;
				l = r;
				if (strs % 2 == 1)
					r++;
				if (now_select != i) {
					for (int j = 0; j < l; j++)
					{
						cout << ' ';
					}
					cout << arr.arr[i];
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
					cout << "->" << arr.arr[i] << "<-";
					for (int j = 0; j < r; j++)
					{
						cout << ' ';
					}
				}
				cout << "|\n";
			}
		}
		else {
			for (int i = 0; i < arr.SIZE; i++)
			{
				cout << '|';
				strs = (s + 4 - arr.arr[i].size());
				r = strs / 2;
				l = r;
				if (strs % 2 == 1)
					r++;
				if (now_select != i) {
					for (int j = 0; j < l; j++)
					{
						cout << ' ';
					}
					cout << arr.arr[i];
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
					cout << "->" << arr.arr[i] << "<-";
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
		for (int i = 0; i < arr.SIZE; i++)
		{
			t = arr.arr[i].size();
			if (t > big)
				big = t;
		}
		return big;
	}
public:
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
							now_select = arr.SIZE - 1;
						break;
					case 80:
						now_select++;
						if (now_select >= arr.SIZE)
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
					return arr.SIZE;
			}
		}
	}
	//������ �ޱ�
	void init(selection_array a) {
		arr = a;
	}
};
//��� Ŭ����
class player {
private:
	job_classes job;
	stat_struct statistics;
	status stat;
	buffs buff;
	debuffs debuff;
protected:

public:
};

class rpg {
private:
	int selection;
	selection_array maps = { {
		"����",
		"�ʿ�","��","��ο� ��",
		"������ ��","��� ���","��ũ�� ����","������ ����","������ ��",
		"���� ��","���ϵ���",
		"������ ����","��Ÿ�� ����",
		"��ũ��������","����",
		"����","õ��","���ɰ�",
		"���� ��ó"
	}, 19 };
	selection_array title = { {
		"���ӽ���",
		"�̾��ϱ� *���߿���",
		"������"
	},3 };
	selection_array town = { {
		"��ȭ",
		"���",
		"â��",
		"��ų",
		"������"
	} ,4 };
	inventory inven = { {},0 };
	inventory skills = { {},0 };
public:
	select_class map_select;
	select_class title_select;

	//�ʱ�ȭ
	rpg() {
		map_select.init(maps);
		title_select.init(title);
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
			else if (selection == 2 || selection == title.SIZE)
				return -1;
		}
	}
	//����
	void game() {
		while (1) {
			if (select_title() == -1)
				return;
			selection = map_select.select_selection();
			if (selection != maps.SIZE) {
				cout << "������ " << maps.arr[selection] << "�Դϴ�.";
				break;
			}
		}
	}
};