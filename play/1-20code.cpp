#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
#pragma warning (disable:4996)
#pragma warning (disable:6236)
#pragma warning (disable:6031)
#pragma warning (disable:6328)
#pragma warning (disable:4477)
#pragma warning (disable:4473)
#pragma warning (disable:6064)
int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0; // a, b, c, d, e = 선택지
int key = 0;

int page = 1;
int ans;
void print(const char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
		_sleep(10);
	}
	printf("\n");
}
int main() {
	system("cls");
	int next = 0;
	int ans6 = 0;
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0; // a, b, c, d, e = 선택지
	int key = 0;
	int key2f = 0;
	int page = 1;
	int ans;

	char page1 = 0;
	print("게임을 시작하겠습니까? (y = 1/n = 0)");
	scanf("%d", &ans);
	if (ans == 0) {

		print("게임을 종료합니다");
		return 0;
	}
	else if(ans!=1) {
		print("Error");
		return 0;
	}

	print("게임의 룰은 간단합니다.");
	print("선택지에 나오는 앞 숫자만 따라 입력해 주시면 됩니다.");
	print("선택지 외의 번호를 입력시 게임이 오류가 날 수 있으니 조심해 주시길 바랍니다.");
	print("또한 숫자를 입력했을때 씹히는 경우가 있을때는 enter를한번 더 입력해주시길 바라겠습니다. ^-^\n\n\n\n");

	//1챕터
	while (page == 1) {

		if (ans6 == 1) {

			page++;
			//break; 

			goto page2;
		}



		if (page == 1 || ans1 == 1 || ans4 == 2 || ans3 == 2) {
			ans1 = 0;
			ans5 = 0;
			print("당신은 알수없는 한 집 앞에 와있습니다.");
			print("집 주위에는 거의 다 부서진 울타리로 둘러싸여있습니다.");
			print("집은 2층집이며 차고를 가지고있습니다.");
			print("당신이 타고온 자동차는 전봇대에 박아 고장이 났으며 당신의 핸드폰은 전파가 터지지 않습니다.\n");
			print("1.집으로 들어가기  2.차고 확인하기  3.자동차 확인하기");

			scanf("%d", &ans5);
		}
		if (ans5 == 1 && key == 0) {
			ans1 = 0;
			print("집의 문이 굳게 닫혀있습니다.\n");
			print("1. 돌아가기");
			scanf("%c*%d", &ans1);
		}
		else if (ans5 == 1 && key == 1) {
			ans1 = 0;
			print("당신은 열쇠를 사용해 현관문을 열었습니다.");
			print("집안은 너무 어두워 아무것도 보이지 않습니다.");
			print("집안에서는 벌레가 기어나오며 이상한 냄새도납니다.\n");
			print("1.들어가기  2.돌아가기");

			scanf("%d1", &ans6);
		}


		else if (ans5 == 2) {
			print("당신은 차고에 들어왔습니다.");
			print("자동차는 보이지 않고 여러가지의 공구상자만이 당신을 반깁니다.\n");
			print("1.공구상자 뒤져보기  2.돌아가기");
			scanf("%d", &ans3);
			if (ans3 == 1) {
				ans1 = 0;
				key = 0;
				print("당신은 수많은 공구상자들을 뒤져 현관열쇠를 찾았습니다.");
				print("열쇠는 아주 오래되었으며 녹이 슬어있습니다.\n");
				print("1.돌아가기");

				scanf("%c*%d", &ans1);
				key++;
			}


		}
		else if (ans5 == 3) {
			print("당신의 자동차는 망가져있습니다.... 왜 살피시는 거죠?\n");
			print("1.돌아가기");
		}
		scanf("%c*%d", &ans1);
	}

	//2챕터


page2: if (page == 2) {
	key = 0;

	while (page == 2 || ans3 == 4 || next == 2)
	{
		if (next == 1) {
			page++;
			goto page3;
		}



		ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
		print("당신이 건물에서 움직일때마다 삐걱거리는 소리가 납니다.");
		print("당신은 거실에 도착하자마자 전등을킵니다.");
		print("전등은 몇번 깜빡이다가,이내 온전히 켜집니다.");
		print("당신은 원인모를 한기를 느낍니다.\n");
		print("1. 주방으로 가기  2. 2층으로 올라가기  3.전등끄기");
		scanf("%d", &ans2);

		if (ans1 == 1 || ans2 == 1 || ans5 == 2 || ans4 == 2 || ans6 == 1) {
			ans2 = 0;
			ans5 = 0;

			print("당신이 주방에 들어오자 주방이 반기는듯 온갖 악취를 풍깁니다.");
			print("당신의 눈앞에는 와인저장소와 설거지더미 그리고 편지 한장이 있습니다.\n");
			print("1. 와인저장소 들어가기  2. 설거지하기  3. 편지읽기  4. 돌아가기");
			scanf("%d", &ans3);
			if (ans3 == 1 && key == 0) {
				print("당신은 와인저장소의 문을 힘껏 잡아당겼습니다.");
				print("하지만 와인저장소는 잠겨있는군요.\n");
				print("1.돌아가기");
				scanf("%d", &ans6);
			}
			else if (ans3 == 1 && key == 1) {
				print("당신은 열쇠로 문을 열었습니다.\n");
				print("1. 들어가기  2. 돌아가기");
				scanf("%d", &ans4);
				if (ans4 == 1) {
					print("당신은 수많은 와인들을 보며 감탄합니다.");
					print("그중에는 당신이 아는 로얄드마리아, 펜폴드 암풀레, 구하기힘든 해드식 까지 있습니다.");
					print("당신은 마시고싶은 충동을 참으며 주위를 둘러봅니다.");
					print("와인밖에 없군요.\n");
					print("1. 와인 둘러보기, 2. 돌아가기");
					scanf("%d", &ans5);
					if (ans5 == 1) {
						ans5 = 0;
						print("음 별다른건 없어 보입니다.\n");
						print("1. 와인 둘러보기  2. 돌아가기");
						scanf("%d", &ans5);
						ans5 += 2;
						if (ans5 == 3) {
							ans5 = 0;
							print("당신은 이게 쓸모있는 짓인지 생각합니다.\n");
							print("1. 와인 둘러보기  2. 돌아가기");
							scanf("%d", &ans5);
							ans5 += 3;
							if (ans5 == 4) {
								ans5 = 0;
								print("쓸모없다고 판단할 찰나! 당신은 2층 열쇠를 찾아냅니다.");
								print("여러모로 끈기가 있으시군요.\n");
								print("1. 돌아가기");
								scanf("%d", &ans2);
								key2f++;
							}
						}

					}
				}
			}
			else if (ans3 == 2) {
				print("오! 당신은 운이 좋군요!");
				print("냄비속 안에 있던 와인저장소 열쇠를 찾았습니다.\n");
				print("1. 돌아가기");
				scanf("%d", &ans2);
				key++;
			}
			else if (ans3 == 3) {
				print("편지에는 이렇게 적혀있군요.");
				print("To 안녕");
				print("오랜만이구나. 너가 이걸보고있다면 넌 충분히 와인저장소에 들어갈만한 자격이 있어.");
				print("와인저장소에서는 무엇이든지 끈기있게 관찰하여 분류하도록 하여라.");
				print("라고 적혀있네요\n");
				print("1. 돌아가기");
				scanf("%d", &ans2);
			}
		}

		if (ans2 == 2 && key2f == 0) {
			ans2 = 0;
			print("당신은 2층계단으로 발걸음을 옮깁니다.");
			print("참 아이러니하게도 2층계단에 문이있고 그문에는 자물쇠가 차여 있는군요!");
			print("아무래도 힘으로 열지는 못할것같습니다.\n");
			print("1. 돌아가기");
			scanf("%d", &ans2);

		}
		else if (ans2 == 2 && key2f == 1) {
			print("당신은 열쇠로 2층의 문을 열었습니다.");
			print("여기도 그리 밝지는 않군요.\n");
			print("1. 들어가기  2. 돌아가기");
			scanf("%d", &next);

		}
		else if (ans2 == 3) {
			print("당신은 전등을 끕니다.");
			print("그리고 그다음 그게 얼마나 멍청한 일이었는지 깨닫습니다.");
			print("어두우면 무섭거든요.");
			print("당신은 재빨리 불을 킵니다.\n");
			print("1. 돌아가기");
			scanf("%d", &ans2);

		}
	}







}


//챕터 3

page3: if (page == 3) {
key = 0;
while (page == 3) {

	ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
	print("당신은 2층에 올라왔습니다.");
	print("2층에는 신기하게도 불이 켜져 있습니다.");
	print("ㅏ라라라라라");
}
}
}



/*void page2() {

page2: if (ans1 == 1) {

	while (page == 2)
	{
		key = 0;
		ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
		char sip = "당신이 건물에서 움직일때마다 삐걱거리는 소리가 납니다.\n당신은 거실에 도착하자마자 전등을킵니다.\n전등은 몇번 깜빡이다가,이내 온전히 켜집니다.\n당신은 원인모를 한기를 느낍니다.\n1. 주방으로 가기  2. 2층으로 올라가기  3.전등끄기\n";
		int engti = strlen(sip);
		for (int i = 0; i < engti; i++) {
			printf("%c", sip[i]);
			_sleep(20);
		}scanf("%d", &ans2);

		if (ans2 == 1) {
			char sor = "당신이 주방에 들어오자 주방이 반기는듯 온갖 악취를 풍깁니다.\n당신의 눈앞에는 와인저장소와 설거지더미 그리고 편지 한장이 있습니다.\n1. 와인저장소 들어가기  2. 설거지하기  3. 편지읽기\n";
			int ti = strlen(sor);
			for (int i = 0; i < ti; i++) {
				printf("%c", sor[i]);
				_sleep(20);
			}scanf("%d", &ans3);

			if (ans3 == 1 && key == 0) {
				char z = "당신은 와인저장소의 문을 힘껏 잡아당겼습니다.\n하지만 와인저장소는 잠겨있는군요.\n1.돌아가기";
				int li = strlen(z);
				for (int i = 0; i < li; i++) {
					printf("%c", z[i]);
					_sleep(20);
				}scanf("%d", &ans1);
			}
			else if (ans3 == 1 && key == 1) {

			}
			else if (ans3 == 2) {

			}
			else if (ans3 == 3) {

			}
		}









	}

}
}



	*/


