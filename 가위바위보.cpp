#include <stdio.h>		//printf(), scanf()
#include <stdlib.h>		//exit(), system(), rand()
#include <conio.h>		//getch()
#include <string.h>		//strcmp() 등
#include <time.h>		//time()
#include <windows.h>	//Sleep()

int main()
{
	main:
	int jumsu, ina, num;
	char kaba[20];
	while ( jumsu<10 && jumsu>-3)
	{
		system("color 0f");
		system("cls");
		printf("--------------------------------------------------\n");
		printf("\t\t가위바위보 게임(현재 점수=%d)\n", jumsu);
		printf("--------------------------------------------------\n");
		printf("1. 가장 먼저 읽으세요-게임 방법\n");
		printf("2. 가위바위보 게임하기\n");
		printf("3. 인생역전 가위바위보\n");
		printf("4. 메인으로 돌아가기\n");
		printf("--------------------------------------------------\n");
		printf("선택\\> ");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:system("color 75");
			printf("\t\t게임 방법\n");
			printf("게임을 시작하시면 가위, 바위, 보 중에 하나를 선택합니다.\n");
			printf("이기거나 지면 각각 1점을 얻거나 잃습니다.\n");
			printf("인생 역전은 승리시 10점을 얻지만 패배시 점수를 다 잃습니다.\n");
			printf("점수가 -3이 되면 당신의 패배로 게임이 끝납니다.\n");
			printf("점수가 10이 되면 당신이 이깁니다.\n");
			printf("메인으로 돌아가기를 누르시면 메인으로 갑니다.\n");
			printf("준비가 되셨다면 엔터키를 눌러주세요.\n");
			printf("행운을 빕니다!\n");
			system("pause"); break;
		case 2:system("cls"); printf("가위, 바위, 보 중에 하나를 입력하세요 : ");
			scanf_s("%s", kaba, 4);
			if (!strcmp(kaba, "가위"))		//가위
			{
				printf("\n당신의 선택은 \"가위\"입니다."); Sleep(2000);
				printf("가위,\t"); Sleep(1000); printf("바위,\t"); Sleep(1000); printf("보!\t"); Sleep(1000);
				printf("\n\n");
				srand((int)time(NULL));
				ina = rand() % 2 + 1;
				if (ina == 1)
				{
					printf("당신 : 가위\n컴퓨터 : 보");
					printf("\n\n당신이 이겼습니다. 1점을 획득하셨습니다.");
					jumsu++; _getch();
				}
				else if (ina == 2)
				{
					printf("당신 : 가위\n컴퓨터 : 가위");
					printf("\n\n이런...비겼습니다."); _getch();
				}
				else if (ina == 3)
				{
					printf("당신 : 가위\n컴퓨터 : 보");
					printf("\n\n운이 없었나?.... 졌습니다. 1점을 잃었습니다.");
					jumsu--; _getch();
				}
				break;
			}
			else if (!strcmp(kaba, "바위"))	//바위
			{
				printf("\n당신의 선택은 \"바위\"입니다."); Sleep(2000);
				printf("가위,\t"); Sleep(1000); printf("바위,\t"); Sleep(1000); printf("보!\t"); Sleep(1000);
				printf("\n\n");
				srand((int)time(NULL));
				ina = rand() % 2 + 1;
				if (ina == 1)
				{
					printf("당신 : 바위\n컴퓨터 : 가위");
					printf("\n\n당신이 이겼습니다. 1점을 획득하셨습니다.");
					jumsu++; _getch();
				}
				else if (ina == 2)
				{
					printf("당신 : 바위\n컴퓨터 : 바위");
					printf("\n\n이런...비겼습니다."); _getch();
				}
				else if (ina == 3)
				{
					printf("당신 : 바위\n컴퓨터 : 보");
					printf("\n\n운이 없었나?.... 졌습니다. 1점을 잃었습니다.");
					jumsu--; _getch();
				}
				break;
			}
			else if (!strcmp(kaba, "보"))
			{
				printf("\n당신의 선택은 \"보\"입니다."); Sleep(2000);
				printf("가위,\t"); Sleep(1000); printf("바위,\t"); Sleep(1000); printf("보!\t"); Sleep(1000);
				printf("\n\n");
				srand((int)time(NULL));
				ina = rand() % 2 + 1;
				if (ina == 1)
				{
					printf("당신 : 보\n컴퓨터 : 바위");
					printf("\n\n당신이 이겼습니다. 1점을 획득하셨습니다.");
					jumsu++; _getch();
				}
				else if (ina == 2)
				{
					printf("당신 : 보\n컴퓨터 : 보");
					printf("\n\n이런...비겼습니다."); _getch();
				}
				else if (ina == 3)
				{
					printf("당신 : 보\n컴퓨터 : 가위");
					printf("\n\n운이 없었나?.... 졌습니다. 1점을 잃었습니다.");
					jumsu--; _getch();
				}
				break;
			}
			else
			{
				printf("아니..가위바위보를 하라니까 뭘 입력한거야?"); _getch; break;
			}
			//케이스 3
		case 3:system("cls"); system("color 60"); printf("자...가위, 바위, 보 중에 하나를 입력하세요 : ");
			scanf_s("%s", kaba, 10);
			if (!strcmp(kaba, "가위"))		//가위
			{
				printf("\n당신의 선택은 \"가위\"입니다."); Sleep(2000);
				printf("가위...\t"); Sleep(2000); printf("바위...\t"); Sleep(2000); printf("보!\t"); Sleep(2000);
				printf("\n\n");
				srand((int)time(NULL));
				ina = rand() % 2 + 1;
				if (ina == 1)
				{
					printf("당신 : 가위\n컴퓨터 : 보");
					printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
					jumsu += 10; _getch(); break;
				}
				else if (ina == 2)
				{
					printf("당신 : 가위\n컴퓨터 : 가위");
					printf("\n\n이런...비겼습니다. 5점을 잃었습니다..."); jumsu -= 5; _getch(); break;
				}
				else if (ina == 3)
				{
					printf("당신 : 가위\n컴퓨터 : 보");
					printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
					jumsu -= 20; _getch(); break;
				}

			}
			else if (!strcmp(kaba, "바위"))	//바위
			{
				printf("\n당신의 선택은 \"바위\"입니다."); Sleep(2000);
				printf("가위...\t"); Sleep(2000); printf("바위...\t"); Sleep(2000); printf("보!\t"); Sleep(2000);
				printf("\n\n");
				srand((int)time(NULL));
				ina = rand() % 2 + 1;
				if (ina == 1)
				{
					printf("당신 : 바위\n컴퓨터 : 가위");
					printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
					jumsu += 10; _getch();
				}
				else if (ina == 2)
				{
					printf("당신 : 바위\n컴퓨터 : 바위");
					printf("\n\n이런...비겼습니다. 5점을 잃었습니다..."); jumsu -= 5; _getch();
				}
				else if (ina == 3)
				{
					printf("당신 : 바위\n컴퓨터 : 보");
					printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
					jumsu -= 20; _getch();
				}
				break;
			}
			else if (!strcmp(kaba, "보"))
			{
				printf("\n당신의 선택은 \"보\"입니다."); Sleep(2000);
				printf("가위...\t"); Sleep(2000); printf("바위...\t"); Sleep(2000); printf("보!\t"); Sleep(2000);
				printf("\n\n");
				srand((int)time(NULL));
				ina = rand() % 2 + 1;
				if (ina == 1)
				{
					printf("당신 : 보\n컴퓨터 : 바위");
					printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
					jumsu += 10; _getch();
				}
				else if (ina == 2)
				{
					printf("당신 : 보\n컴퓨터 : 보");
					printf("\n\n이런...비겼습니다. 5점을 잃었습니다..."); jumsu -= 5; _getch();
				}
				else if (ina == 3)
				{
					printf("당신 : 보\n컴퓨터 : 가위");
					printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
					jumsu -= 20; _getch();
				}
				break;
			}
			else
			{
				printf("아니..가위바위보를 하라니까 뭘 입력한거야?"); system("pause"); break;
			}
		case 4:goto main;
		default:printf("똑바로 입력해!!!\n"); _getch;
			break;
		}

	}
	if (jumsu >= 10) {
		printf("당신의 이겼습니다. 축하드립니다. 메인으로 돌아갑니다.\n"); system("pause");
	}
	else if (jumsu < -2)
	{
		system("color 0c");
		printf("당신의 졌습니다. 유감입니다. 메인으로 돌아갑니다.\n"); system("pause");
		system("color 0f");
	}
}