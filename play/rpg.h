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
//스탯
class stat_struct {
public:
	unsigned short STR = 0;//물공 hp 2 atk 3
	unsigned short INT = 0;//마공 mp 5
	unsigned short WIS = 0;//마나 mp 3 hp 2
	unsigned short DEX = 0;//방어력 def 3 hp 2
	unsigned short AGI = 0;//민첩성 atk 1 cri 4
	unsigned short VIT = 0;//체력 hp 4 def 1
};
//무기 성능
typedef struct {
	string name;
	enum_rarity rarity;
	int weapon_skill_code;
	stat_struct plus_stat;
}weapon_status;
//스테이터스
typedef struct {
	int hp;
	int mp;
	int atk;
	int def;
	int cri;
}status;
//선택지 구조체
typedef struct {
	string arr[100];
	int SIZE;
}selection_array;
//소지 구조체
typedef struct {
	string arr[1000];
	int idx;
}inventory;
//직군
enum job_classes {
	//물리
	//레이피어
	DUELER = 0,//0
	//검, 월도, 글러브
	FIGHTER,//1
	//단검, 비수
	ASSASSIN,//2
	//창
	LANCER,//3
	//대검, 월도
	WARRIOR,//4
	//해머
	BRACKSMITH,//5
	//도끼
	LUMBERJACK,//6
	//활
	ARCHER,//7
	//석궁
	CLOSSBOWER,//8
	//권총, 라이플, 샷건, 스나
	SOLDIER,//9
	//스나
	SNIPER,//10
	//라이플, 샷건
	ASSAULT,//11
	//물리 모든무기
	//물리 모든 방어구
	WEAPONMASTER,//12
	//마법
	//스테프,완드
	//로브
	WIZARD//13
};
//버프 디버프
enum buffs {
	//재생
	REGENERATION = 0,
	//힘
	STRENGTH,
	//방어력
	RESISTANCE,
	//민첩
	AGILITY,
	//방어력, 힘
	REINFORCE,
	//수중호흠(바다지형등)
	WATERBREATHING,
	//흡수(일회용 체력)
	ABSORPTION,
	//유틸라이즈(공격력과 방어력중 낮은 능력치를 획득)
	UTILIZE
};
//디버프
enum debuffs {
	//독
	POISON = 0,
	//약화(공격력 저하)
	WEAKNESS,
	//방어력저하
	SHIELDBREAK,
	//약체화(공격력, 방어력 저하)
	WEAKENING,
	//민첩성 저하
	SLOWNESS,
	//기절
	STUN,
	//실명
	BLIND,
	//침묵
	SILENCE,
	//도발
	TAUNT
};
//희귀도
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
	//레이피어
	//에페
	EPEE,
	//플뢰레
	FLEURET,
	//스몰소드
	SMALLSWORD,
	//에스파다 로페라
	ESPADAROPERA,
	//미스틸테인
	MISTILTEINN,
	//검
	//롱소드
	LONGSWORD,
	//발키리소드
	VALKYRIESWORD,
	//글라디우스
	GLADIUS,
	//바스타드소드
	BASTARDSWORD,
	//후츠노미타마
	FUTSUNOMITAMA,
	//쌍룡검
	DOUBLEDRAGONSWORD,
	//엑스칼리버
	EXCALIBUR,
	//다인슬레이프
	DAINSLEIF,
	//클레이모어
	CLAYMORE,
	//프람베르그
	FLAMBERGE,
	//마체테
	MACHETE,
	//시미터
	SCIMITAR,
	//쿠크리
	KUKRI,
	//팔시온, 펄션
	FALCHION,
	//마법검
	//티르빙
	TYRFINGR,
	//단검
	//대거
	DAGGER,
	//메인고쉬
	MAINGAUCHE,
	//클라우솔라스
	CLAIOMHSOLAIS,
	//소드브레이커
	SWORDBREAKER,
	//창
	//궁니르
	GUNGNIR,
	//롱기누스의창
	LONGINUS,
	//루인
	RUIN,
	//트리아이나(포세이돈의 창)
	TRIAINA,
	//트리슈라(인도의 파괴의 신 시바의 창)
	TRIDENT,
	//대검
	//드래곤슬레이어
	DRAGONSLAYER,
	//듀랜달, 뒤랑달
	DURANDAL,
	//그람
	GRAM,
	//레바테인
	LAEATEINN,
	//발뭉
	BALMUNG,
	//아론다이트
	ARONDIGHT,
	//에케작스
	ECKESACHS,
	//망치
	//묠니르
	MOLNIR,
	//대장장이의 망치
	BLACKSMITHHAMMER
};
weapon_status weapons_status[] = {
	{
		"에페",UNCOMMON,0,{}

}
}
//랜덤확률   0<per<1
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
//선택용 클래스
class select_class {
private:
	int now_select = 0;
	string arr[100];
	//선택지 이름 출력
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
	//선택지 이름 가장 큰 것 반환
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
	//선택지 선택
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
	//선택지 받기
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
//사람 클래스
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
		"마을",
		"초원","숲","어두운 숲",
		"슬라임 숲","고블린 취락","오크의 동굴","버려진 무덤","오래된 고성",
		"깊은 곳","지하동굴",
		"얼어붙은 빙하","불타는 지옥",
		"네크로폴리스","신전",
		"마계","천계","정령계",
		"신의 거처"
	};
	string title[100] = {
		"게임시작",
		"이어하기 *개발예정",
		"나가기"
	};
	string town[100] = {
		"강화",
		"제작",
		"장비",
		"스킬",
		"창고",
		"나가기"
	};
	inventory inven = { {},0 };
	inventory skills = { {},0 };
public:
	select_class map_select;
	select_class title_select;
	select_class town_select;

	//초기화
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
				cout << "죄송합니다.\n이어하기 기능은 개발중입니다.\n아무키나 누르세요.";
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
	//게임
	void game() {
		if (select_title() == -1)
			return;
		while (1) {
			selection = map_select.select_selection();
			if (selection != map_select.size) {
				if (maps[selection] == "마을") {
					while (1) {
						selection = town_select.select_selection();
						if (selection != town_select.size) {
							if (town[selection] == "나가기")
								break;
							cout << "선택은 " << town[selection] << "입니다.";
							break;
						}
					}
					if (town[selection] == "나가기")
						continue;
				}
				else
					cout << "선택은 " << maps[selection] << "입니다.";
				break;
			}
		}
	}
};