#include <stdio.h> 
#include <string.h> 
#include <time.h> 
#include <stdlib.h> 
#include <windows.h> 
#include <conio.h> 

int main()
{
	char serial[30], dos[20], name[4], ramen[10];
	int i, j, num, year1, year2, chai, age1, age2, kong, monji, chomi;

	printf("\n\n\n\t\t\tAllensoft\n\t\t\t만능계산기 v2.0\n");
	system("pause");
	system("cls");
	printf("\n\n\n\t\t\t언어:한국어\n\t\t\t");
	printf("\n\n\n\t\t\t에디션:Acacu2.0\n\t\t\t");
	printf("\n\n\n\t\t\t아키텍쳐:64비트 운영체제\n\t\t\t");
	printf("\n\n\n\t\t\t모든 설정이 올바릅니다.\n\t\t\t");
	system("pause");
	system("cls");
	printf("\n\n\n\t\t\t제품키를 입력해 주세요.\n나가시려면 exit를 입력하세요.\n");
	while (1)
	{
		scanf("%s", serial);

		if (!strcmp(serial, "exit"))
			return 0;
		else if (!strcmp(serial, "SNCI2-9C0JK-DLFYD-8A9RY-H43JK"))
		{
			printf("인증키가 확인되었습니다. 잠시만 기다려 주세요...\n");
			Sleep(5000);
			system("cls");
			srand(time(NULL));
			for (i = 0; i < 2000; i++) {
				printf("인증을 요청하고 있습니다....%d\n", rand() % 10000);
			}

			for (j = 0; j<30; j++)
			{
				printf("인증중입니다....%d.dll\n", rand() % 10000);
			}
			Sleep(5000);
			system("cls");
			Sleep(5000);
			printf("인증이 완료되었습니다.\n잠시만 기다려 주세요. ");
			Sleep(1000);
			printf(". ");
			Sleep(1000);
			printf(". ");
			Sleep(1000);
			printf(". ");
			Sleep(1000);
			printf(". ");
			Sleep(1000);
			printf(".\n");
			printf("설치중입니다.....잠시만 기다리십시오....");
			Sleep(5000);
			system("cls");
			printf("=\n=");
			printf("\n\nstatus : copying Files.....");
			Sleep(5000);
			system("cls");
			printf("=\n=");
			printf("\n\nstatus : setup Acacu.....");
			Sleep(5000);
			system("cls");
			printf("==\n==\n\n");
			for (int n = 0; n < 30; n++) {
				printf("status : copying %d.sys\n", n);
			}
			Sleep(3000);
			system("cls");
			printf("===\n===");
			printf("\n\nstatus : formatting C:....");
			Sleep(5000);
			system("cls");
			printf("====\n====");
			printf("\n\nstatus : Set personal settings.....");
			Sleep(5000);
			system("cls");
			printf("=====\n=====");
			printf("\n\nstatus : setup.....");
			Sleep(5000);
			system("cls");
			while (1)
			{

				printf("=============================================================\n");
				printf("                            만능 계산기                                  \n");
				printf("=============================================================\n");
				printf("1. 나의 나이는 0000년에 몇 살일까?\n");
				printf("2. 라면 끓이는 시간 계산\n");
				printf("3. 콩 스탬프 X개는 얼마일까?\n");
				printf("4. 미세먼지가 나쁨인가?(간단)\n");
				printf("5. 미세먼지가 나쁨인가?(일반)\n");
				printf("6. 미세먼지가 나쁨인가?(전문가용)\n");
				printf("7. 도움말\n");
				printf("8. 나가기\n");
				printf("9. 제품키 변경 또는 만능계산기 업그레이드\n");
				printf("=============================================================\n");
				printf("번호를 입력하세요 : ");
				scanf("%d", &num);
				switch (num)
				{
				case 1:printf("이름을 입력하세요...\n"); scanf("%s", &name);
					printf("연도를 입력하세요...\n"); scanf("%d", &year1);
					printf("현재 나이를 입력하세요...\n"); scanf("%d", &age1);
					printf("나이를 알고싶은 연도를 입력하세요...\n"); scanf("%d", &year2);
					chai = year2 - year1;
					printf("%d년에 %s님의 나이는 %d살 입니다\n", year2, name, chai + age1); getch(); break;
				case 2: printf("라면의 이름을 입력하세요 : "); scanf("%s", ramen);
					if (!strcmp(ramen, "너구리") || !strcmp(ramen, "진짬뽕")) {
						printf("5분동안 끓이면 됩니다.\n");
					}
					else if (!strcmp(ramen, "안성탕면")) {
						printf("4분 30초동안 끓이면 됩니다.\n");
					}
					else if (!strcmp(ramen, "진라면")) {
						printf("3분동안 끓이면 됩니다.\n");
					}
					else if (!strcmp(ramen, "스낵면")) {
						printf("2분동안 끓이면 됩니다.\n");
					}
					else {
						printf("잘못 입력하셨거나 이 라면은 등록되지 않았습니다.\n");
					}
					getch(); break;
				case 3:printf("콩 스탬프 갯수를 입력하세요...\n"); scanf("%d", &kong);
					printf("콩 스탬프 %d개는 %d원입니다.\n", kong, kong * 20); getch(); break;

				case 4:printf("현재 미세먼지 수치를 입력하세요 : \n"); scanf("%d", &monji);
					printf("현재 초미세먼지 수치를 입력하세요 :  \n"); scanf("%d", &chomi);
					if (monji >= 151 || chomi >= 101)
					{
						printf("공기가 심각하게 오염되었습니다!\n마스크를 꼭 써야 합니다.\n"); getch(); break;
					}
					else if (monji >= 81 || chomi >= 51)
					{
						printf("위험합니다. 마스크를  써야 합니다.\n"); getch(); break;
					}
					else if (monji >= 31 || chomi >= 16)
					{
						printf("나쁘지 않습니다.마스크를  안써도 됩니다.\n"); getch(); break;
					}
					else
					{
						printf("공기가 아주 깨끗합니다. 마스크를 쓸 필요가 없습니다.\n"); getch(); break;
					}

				case 5:printf("현재 미세먼지 수치를 입력하세요 : \n"); scanf("%d", &monji);
					printf("현재 초미세먼지 수치를 입력하세요 :  \n"); scanf("%d", &chomi);
					if (monji >= 151 || chomi >= 101)
					{
						printf("'매우 나쁨'입니다.\n실외에서의 모든 신체활동을 금지하십시오.\n만약 밖으로 나갈땐 마스크를 꼭 써야 합니다.\n"); getch(); break;
					}
					else if (monji >= 81 || chomi >= 51)
					{
						printf("'나쁨'입니다.\n장시간 또는 무리한 실외활동을 자제하십시오.\n마스크를  써야 합니다.\n"); getch(); break;
					}
					else if (monji >= 31 || chomi >= 16)
					{
						printf("'보통'입니다.\n마스크를  안써도 됩니다.\n"); getch(); break;
					}
					else
					{
						printf("'좋음'입니다.\n 마스크를 쓸 필요가 없습니다.\n"); getch(); break;
					}

				case 6:printf("현재 미세먼지 수치를 입력하세요(㎍/㎥) : \n"); scanf("%d", &monji);
					printf("현재 초미세먼지 수치를 입력하세요(㎍/㎥) :  \n"); scanf("%d", &chomi);
					if (monji >= 151 || chomi >= 101)
					{
						printf("현재 미세먼지 혹은 초미세먼지의 농도가 '매우 나쁨'입니다.\n미세먼지의 농도는%d㎍/㎥, 초미세먼지의 농도는 %d㎍/㎥으로, \n", monji, chomi);
						printf("일반인은 실외에서의 모든 신체활동을 금지하고,\n심장질환 혹은 폐질환이있는 사람,노인,어린이 들은\n장시간 또는 무리한활동을 제한하여야 합니다.\n만약 밖으로 나갈땐 마스크를 꼭 써야 합니다.\n"); getch(); break;
					}
					else if (monji >= 81 || chomi >= 51)
					{
						printf("현재 미세먼지 혹은 초미세먼지의 농도가 '나쁨'입니다.\n미세먼지의 농도는%d㎍/㎥, 초미세먼지의 농도는 %d㎍/㎥으로, \n", monji, chomi);
						printf("일반인은 실외에서의 모든 신체활동을 자제하고,\n심장질환 혹은 폐질환이 있는 사람,노인,어린이 들은 장시간 또는 무리한 활동을 제한하여야 합니다.\n만약 밖으로 나갈땐 마스크를 써야 합니다.\n"); getch(); break;
					}
					else if (monji >= 31 || chomi >= 16)
					{
						printf("현재 미세먼지 혹은 초미세먼지의 농도가 '보통'입니다.\n미세먼지의 농도는%d㎍/㎥, 초미세먼지의 농도는 %d㎍/㎥으로, \n", monji, chomi);
						printf("일반인은 실외활동에 문제가 없으나, \n민감군은 장시간 또는 무리한 실외 활동을 자제해야 합니다.\n"); getch(); break;
					}
					else
					{
						printf("현재 미세먼지 혹은 초미세먼지의 농도가 '좋음'입니다.\n실미세먼지의 농도는%d㎍/㎥, 초미세먼지의 농도는 %d㎍/㎥으로, \n", monji, chomi);
						printf("일반인과 민감군 모두 실외활동에 문제가 없습니다.\n"); getch(); break;
					}
				case 7:
					while (1)
					{
						printf("----------------------------------------------\n");
						printf("\t\t\t도움말\n");
						printf("----------------------------------------------\n");
						printf("1. 이 프로그램은 무엇인가요?\n");
						printf("2. 사용 방법\n");
						printf("3. 문제 해결\n");
						printf("4. 도움말 나가기\n");
						printf("----------------------------------------------\n");
						scanf("%d", &num);
						switch (num)
						{
						case 1:printf("나선우가 만든 만능 계산기 입니다.\n꾸준히 업데이트 되고 있으며 미래의 자신의 나이, 라면 끓이는 시간\n등을 알 수 있는 획기적인 프로그램 입니다.\n"); getch(); break;
						case 2: printf("메인화면에서 원하는 것의 숫자를 입력하세요. 프로그램의 지시에 따라 주세요.\n문장이 표시되거나 값을 입력했을 땐 반드시 Enter 키를 눌러 주세요.\n"); getch(); break;
						case 3:
							while (1)
							{
								printf("---------------문제 해결---------------\n");
								printf("1. 커서만 뜨고 아무것도 뜨지 않아요.\n");
								printf("2. 창이 계속 깜빡이고 키보드가 말을 듣지 않아요.\n");
								printf("3. 평소와 다른 말이 뜨고 키 입력이 되지 않아요.\n");
								printf("4. 처음으로 돌아가기\n");
								printf("----------------------------------------------\n");
								scanf("%d", &num);
								switch (num)
								{
								case 1:printf("Enter 키를 눌러보세요.\n"); getch(); break;
								case 2: printf("잘못된 값을 입력 했을 때 나타나는 현상입니다.\n프로그램을 재시작 해 주세요.\n"); getch(); break;
								case 3:printf("오류입니다. 프로그램을 재시작해 주세요.\n"); getch(); break;
								case 4:printf("주의. 커서만 깜박거릴 경우 Enter 키를 여러번 누르세요.\n"); break;
								default:printf("문제 해결에 없는 항목입니다.");
								}
								system("cls");
								break;
							}
							getch(); break;
						case 4: break;
						default:printf("도움말에 없는 항목입니다.\n");
						}
						system("cls");

						break;
					}
					getch(); break;
				case 8: exit(0);
				case 9: printf("현재 가장 최신버전 입니다....업그레이드 하실 수 없습니다.");
				default:printf("잘못된 숫자를 입력하셨습니다.\n1~8중에 선택해 주십시오.\n"); getch();
				}
				system("cls");
			}
		}
		else
			printf("시리얼 번호가 맞지 않습니다. 다시 시도하세요.\n나가시려면 exit를 입력하세요.\n");
	}
}