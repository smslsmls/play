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
int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0; // a, b, c, d, e = ������
int key = 0;

int page = 1;
int ans;
int main() {
	system("cls");
	int next = 0;
	int ans6 = 0;
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0; // a, b, c, d, e = ������
	int key = 0;
	int key2f = 0;
	int page = 1;
	int ans;
	char* z = 0;
	char* sd = 0;

	char page1 = 0;
	char* scrip = 0;
	char* script = "������ �����ϰڽ��ϱ�? (y = 1/n = 0)\n";
	int length = strlen(script);
	for (int i = 0; i < length; i++) {
		printf("%c", script[i]);
		_sleep(20);
	}

	scanf("%d", &ans);



	if (ans == 1) {

		char* scrt = "������ ���� �����մϴ�.\n�������� ������ �� ���ڸ� ���� �Է��� �ֽø� �˴ϴ�.\n������ ���� ��ȣ�� �Է½� ������ ������ �� �� ������ ������ �ֽñ� �ٶ��ϴ�.\n ���� ���ڸ� �Է������� ������ ��찡 �������� enter���ѹ� �� �Է����ֽñ� �ٶ�ڽ��ϴ�. ^-^\n\n\n\n\n";
		int lth = strlen(scrt);
		for (int i = 0; i < lth; i++) {
			printf("%c", scrt[i]);
			_sleep(20);
		}

		//1é��
		while (page == 1) {

			if (ans6 == 1) {

				page++;
				//break; 

				goto page2;
			}



			if (page == 1 || ans1 == 1 || ans4 == 2 || ans3 == 2) {
				ans1 = 0;
				ans5 = 0;
				char* page1 = "����� �˼����� �� �� �տ� ���ֽ��ϴ�.\n �� �������� ���� �� �μ��� ��Ÿ���� �ѷ��ο��ֽ��ϴ�.\n���� 2�����̸� ���� �������ֽ��ϴ�.\n����� Ÿ��� �ڵ����� �����뿡 �ھ� ������ ������ ����� �ڵ����� ���İ� ������ �ʽ��ϴ�.\n\n 1.������ ����  2.���� Ȯ���ϱ� 3.�ڵ��� Ȯ���ϱ�\n";
				int leng = strlen(page1);
				for (int i = 0; i < leng; i++) {
					printf("%c", page1[i]);
					_sleep(20);
				}

				scanf("%d", &ans5);
			}
			if (ans5 == 1 && key == 0) {
				ans1 = 0;
				char* s = "���� ���� ���� �����ֽ��ϴ�.\n\n 1. ���ư���\n";
				int lengh = strlen(s);
				for (int i = 0; i < lengh; i++) {
					printf("%c", s[i]);
					_sleep(20);
				}
				scanf("%c*%d", &ans1);
			}
			else if (ans5 == 1 && key == 1) {
				ans1 = 0;
				char* sd = "����� ���踦 ����� �������� �������ϴ�.\n ������ �ʹ� ��ο� �ƹ��͵� ������ �ʽ��ϴ�.\n���ȿ����� ������ ������ �̻��� ���������ϴ�.\n\n1.����  2.���ư���\n";
				int len = strlen(sd);
				for (int i = 0; i < len; i++) {
					printf("%c", sd[i]);
					_sleep(20);
				}

				scanf("%d1", &ans6);
			}


			else if (ans5 == 2) {
				char* z = "����� ���� ���Խ��ϴ�.\n�ڵ����� ������ �ʰ� ���������� �������ڸ��� ����� �ݱ�ϴ�.\n\n1.�������� ��������  2.���ư���\n";
				int lee = strlen(z);
				for (int i = 0; i < lee; i++) {
					printf("%c", z[i]);
					_sleep(20);
				}

				scanf("%d", &ans3);
				if (ans3 == 1) {
					ans1 = 0;
					key = 0;
					char* q = "����� ������ �������ڵ��� ���� �������踦 ã�ҽ��ϴ�.\n����� ���� �����Ǿ����� ���� �����ֽ��ϴ�.\n\n1.���ư���\n";
					int lez = strlen(q);
					for (int i = 0; i < lez; i++) {
						printf("%c", q[i]);
						_sleep(20);
					}

					scanf("%c*%d", &ans1);
					key++;
				}


			}
			else if (ans5 == 3) {
				char* x = "����� �ڵ����� �������ֽ��ϴ�.... �� ���ǽô� ����?\n\n1.���ư���\n";
				int le = strlen(x);
				for (int i = 0; i < le; i++) {
					printf("%c", x[i]);
					_sleep(20);
				}
			}
			scanf("%c*%d", &ans1);



		}

		//2é��


	page2: if (page == 2) {
		key = 0;

		while (page == 2 || ans3 == 4 || next == 2)
		{
			if (next == 1) {
				page++;
				goto page3;
			}



			ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
			char* sip = "����� �ǹ����� �����϶����� �߰ưŸ��� �Ҹ��� ���ϴ�.\n����� �Žǿ� �������ڸ��� ������ŵ�ϴ�.\n������ ��� �����̴ٰ�,�̳� ������ �����ϴ�.\n����� ���θ� �ѱ⸦ �����ϴ�.\n\n1. �ֹ����� ����  2. 2������ �ö󰡱�  3.�������\n";
			int engti = strlen(sip);
			for (int i = 0; i < engti; i++) {
				printf("%c", sip[i]);
				_sleep(20);
			}scanf("%d", &ans2);

			if (ans1 == 1 || ans2 == 1 || ans5 == 2 || ans4 == 2 || ans6 == 1) {
				ans2 = 0;
				ans5 = 0;

				char* sor = "����� �ֹ濡 ������ �ֹ��� �ݱ�µ� �°� ���븦 ǳ��ϴ�.\n����� ���տ��� ��������ҿ� ���������� �׸��� ���� ������ �ֽ��ϴ�.\n\n1. ��������� ����  2. �������ϱ�  3. �����б�  4. ���ư���\n";
				int ti = strlen(sor);
				for (int i = 0; i < ti; i++) {
					printf("%c", sor[i]);
					_sleep(20);
				}scanf("%d", &ans3);
				if (ans3 == 1 && key == 0) {
					char* z = "����� ����������� ���� ���� ��ƴ����ϴ�.\n������ ��������Ҵ� ����ִ±���.\n\n1.���ư���";
					int li = strlen(z);
					for (int i = 0; i < li; i++) {
						printf("%c", z[i]);
						_sleep(20);
					}scanf("%d", &ans6);
				}
				else if (ans3 == 1 && key == 1) {
					char* s = "����� ����� ���� �������ϴ�.\n\n 1. ����  2. ���ư���\n";
					int lengh = strlen(s);
					for (int i = 0; i < lengh; i++) {
						printf("%c", s[i]);
						_sleep(20);
					}scanf("%d", &ans4);
					if (ans4 == 1) {
						char* o = "����� ������ ���ε��� ���� ��ź�մϴ�.\n���߿��� ����� �ƴ� �ξ�帶����, ������ ��Ǯ��, ���ϱ����� �ص�� ���� �ֽ��ϴ�.\n����� ���ð���� �浿�� ������ ������ �ѷ����ϴ�.\n���ιۿ� ������.\n\n 1. ���� �ѷ�����, 2. ���ư���\n";
						int h = strlen(o);
						for (int i = 0; i < h; i++) {
							printf("%c", o[i]);
							_sleep(20);
						}scanf("%d", &ans5);
						if (ans5 == 1) {
							ans5 = 0;
							char* k = "�� ���ٸ��� ���� ���Դϴ�.\n\n 1. ���� �ѷ�����  2. ���ư���\n";
							int g = strlen(k);
							for (int i = 0; i < g; i++) {
								printf("%c", k[i]);
								_sleep(20);
							}scanf("%d", &ans5);
							ans5 += 2;
							if (ans5 == 3) {
								ans5 = 0;
								char* a3 = "����� �̰� �����ִ� ������ �����մϴ�.\n\n 1. ���� �ѷ�����  2. ���ư���\n";
								int a2 = strlen(a3);
								for (int i = 0; i < a2; i++) {
									printf("%c", a3[i]);
									_sleep(20);
								}scanf("%d", &ans5);
								ans5 += 3;
								if (ans5 == 4) {
									ans5 = 0;
									char* t = "������ٰ� �Ǵ��� ����! ����� 2�� ���踦 ã�Ƴ��ϴ�.\n������� ���Ⱑ �����ñ���.\n\n 1. ���ư���\n";
									int t2 = strlen(t);
									for (int i = 0; i < t2; i++) {
										printf("%c", t[i]);
										_sleep(20);
									}scanf("%d", &ans2);
									key2f++;
								}
							}

						}
					}
				}
				else if (ans3 == 2) {
					char* u = "��! ����� ���� ������!\n����� �ȿ� �ִ� ��������� ���踦 ã�ҽ��ϴ�.\n\n 1. ���ư���\n";
					int u2 = strlen(u);
					for (int i = 0; i < u2; i++) {
						printf("%c", u[i]);
						_sleep(20);
					}scanf("%d", &ans2);
					key++;
				}
				else if (ans3 == 3) {
					char* s3 = "�������� �̷��� �����ֱ���.\nTo �ȳ�\n�������̱���. �ʰ� �̰ɺ����ִٸ� �� ����� ��������ҿ� ������ �ڰ��� �־�.\n��������ҿ����� �����̵��� �����ְ� �����Ͽ� �з��ϵ��� �Ͽ���.\n��� �����ֳ׿�\n\n 1. ���ư���\n";
					int s4 = strlen(s3);
					for (int i = 0; i < s4; i++) {
						printf("%c", s3[i]);
						_sleep(20);
					}scanf("%d", &ans2);
				}
			}

			if (ans2 == 2 && key2f == 0) {
				ans2 = 0;
				char* l1 = "����� 2��������� �߰����� �ű�ϴ�.\n�� ���̷����ϰԵ� 2����ܿ� �����ְ� �׹����� �ڹ��谡 ���� �ִ±���!\n�ƹ����� ������ ������ ���ҰͰ����ϴ�.\n\n 1. ���ư���\n";
				int l2 = strlen(l1);
				for (int i = 0; i < l2; i++) {
					printf("%c", l1[i]);
					_sleep(20);
				}scanf("%d", &ans2);

			}
			else if (ans2 == 2 && key2f == 1) {
				char* e1 = "����� ����� 2���� ���� �������ϴ�.\n���⵵ �׸� ������ �ʱ���.\n\n 1. ����  2. ���ư���\n";
				int e2 = strlen(e1);
				for (int i = 0; i < e2; i++) {
					printf("%c", e1[i]);
					_sleep(20);
				}
				scanf("%d", &next);

			}
			else if (ans2 == 3) {
				char* w1 = "����� ������ ���ϴ�.\n�׸��� �״��� �װ� �󸶳� ��û�� ���̾����� ���ݽ��ϴ�.\n��ο�� �����ŵ��.\n����� �绡�� ���� ŵ�ϴ�.\n\n 1. ���ư���\n";
				int w2 = strlen(w1);
				for (int i = 0; i < w2; i++) {
					printf("%c", w1[i]);
					_sleep(20);
				}scanf("%d", &ans2);

			}
		}







	}


	//é�� 3

page3: if (page == 3) {
	key = 0;
	while (page == 3) {

		ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
		char* aa = "����� 2���� �ö�Խ��ϴ�.\n2������ �ű��ϰԵ� ���� ���� �ֽ��ϴ�.\n��������";
		int aaa = strlen(aa);
		for (int i = 0; i < aaa; i++) {
			printf("%c", aa[i]);
			_sleep(20);
		}
	}
}

	}
	else if (ans == 0) {

		char* scrip = "������ �����մϴ�\n";
		int lengti = strlen(scrip);
		for (int i = 0; i < lengti; i++) {
			printf("%c", scrip[i]);
			_sleep(20);
		}
	}
	else printf("Error");
}



/*void page2() {

page2: if (ans1 == 1) {

	while (page == 2)
	{
		key = 0;
		ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
		char* sip = "����� �ǹ����� �����϶����� �߰ưŸ��� �Ҹ��� ���ϴ�.\n����� �Žǿ� �������ڸ��� ������ŵ�ϴ�.\n������ ��� �����̴ٰ�,�̳� ������ �����ϴ�.\n����� ���θ� �ѱ⸦ �����ϴ�.\n1. �ֹ����� ����  2. 2������ �ö󰡱�  3.�������\n";
		int engti = strlen(sip);
		for (int i = 0; i < engti; i++) {
			printf("%c", sip[i]);
			_sleep(20);
		}scanf("%d", &ans2);

		if (ans2 == 1) {
			char* sor = "����� �ֹ濡 ������ �ֹ��� �ݱ�µ� �°� ���븦 ǳ��ϴ�.\n����� ���տ��� ��������ҿ� ���������� �׸��� ���� ������ �ֽ��ϴ�.\n1. ��������� ����  2. �������ϱ�  3. �����б�\n";
			int ti = strlen(sor);
			for (int i = 0; i < ti; i++) {
				printf("%c", sor[i]);
				_sleep(20);
			}scanf("%d", &ans3);

			if (ans3 == 1 && key == 0) {
				char* z = "����� ����������� ���� ���� ��ƴ����ϴ�.\n������ ��������Ҵ� ����ִ±���.\n1.���ư���";
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


