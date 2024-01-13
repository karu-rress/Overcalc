/*Copyright C 2017 Allen Na
*If there is a problem, please support to
*******@*****.***.
*/

#include "Overhead.h"

int main()
{

	struct sutja SUTJA = { FALSE, FALSE, TRUE, };						//숫자 맞추기	게임	구조체
	struct kababo KABA = { FALSE };										//가위 바위보	게임	구조체
	struct doll DOLL = { FALSE, FALSE, 5000 };							//인형 뽑기	게임	구조체

	int year;																			//달력 년도
	int day_code, leap;															//잘 모르겠음
	unsigned int num, num2;												//각종 while 문의 선택	

	int honor = 50;																	//명예점수
	char asdf, qwer;																//인증키 랜덤생성시 글자 및 숫자생성
	char prokey[35] = { FALSE }, key_real[35] = { FALSE };			//제품키 출력 및 입력
	char actkey[15] = { FALSE }, act_in[15] = { FALSE };				//정품 인증키 출력 및 입력
	int x = FALSE;																	//pro부팅화면 시도 횟수
	int ax = FALSE;																	//인형뽑기 게임에서 goto문 대신 경로 생성
	int zp = 0;																			//nonpro의 인증키 생성시 '-'의 위치 지정 도와줌

	srand((char)time(NULL));													//인증키 랜덤 생성
	asdf = rand(); qwer = rand();												//인증키 섞음

																				/*일반 버전*/
	while (TRUE)
	{
	next: main:																		//goto 문의 도착 지점

		CLS C_3F
			MENU_BAR		MENU_TITLE		HONOR		MENU_BAR
			printf("\n공지-일반 버전의 업데이트가 중단되었습니다.\n업데이트를 받으시려면 게임을 해서 얻은 명예점수로\nPRO버전을 구입하시기 바랍니다.\n\n");
		printf("1. 나의 나이는 0000년에 몇 살일까?\n");				//나이 계산기
		printf("2. 라면 끓이는 시간 계산\n");								//라면 시간 계산기
		printf("3. 콩 스탬프 X개는 얼마일까?\n");							//콩스탬프 전환
		printf("4. 미세먼지가 나쁨인가?(간단)\n");						//미세먼지
		printf("5. 미세먼지가 나쁨인가?(일반)\n");
		printf("6. 미세먼지가 나쁨인가?(전문가용)\n");
		printf("7. 인형 뽑기 게임하기\n");									//인형뽑기
		printf("8. 로또 번호 출력\n");											//로또
		printf("9. 19단\n");															//19단 표 출력
		printf("10. 가위바위보 게임\n");
		printf("11. 달력 출력\n");
		printf("12. BMI 계산하기\n");
		printf("13. 숫자 맞히기\n");
		printf("14. 도움말\n");
		printf("15. 원주율 출력\n");
		printf("16. Overcalc의 역사와 발전\n");
		printf("17. Pro버전 제품키 받기\n");
		printf("18. Pro버전으로 업그레이드\n");
		printf("Q.  나가기\n");
		MENU_BAR
			printf("번호를 입력하세요 : ");
		scanf_s("%d", &num);												//char형 정수는 %hhd

		switch (num)
		{
		case 1: age_calc();			ll break;
		case 2: ramen_calc();		ll break;
		case 3: kong_calc();		ll break;
		case 4: monji_easy();		ll break;
		case 5: monji_normal();	ll break;
		case 6: monji_hard();		ll break;
		case 7:
			DOLL.money = 5000;				//돈은 5000으로 초기화
			DOLL.keysido = FALSE;				//인증키1 시도횟수 초기화
			DOLL.jkeysido = FALSE;				//인증키2 시도횟수도 초기화

			while (DOLL.money > FALSE)
			{
				CLS
					if (DOLL.money >= 50000)
					{
						/*게임 끝*/
						printf("축하합니다! 잔액이 50000원이상입니다.\n게임을 클리어 하셨습니다.\n명예점수 3점이 올라갑니다.\n");
						PUS honor += 3; /*명예점수 3점 추가*/	break;
					}

				num2 = doll_menu(&DOLL);

				switch (num2)
				{

				case 1: doll_game(&DOLL);		break;
				case 2: kind_of_doll(); PUS			break;
				case 3: doll_activ(&DOLL);			break;
				case 4: ax = 1; break;							//goto ax;
				default: printf("도데체 뭘 누른거야?"); ll	break;
				}

				if (ax == 1)											//ax:
					break;
			}

			if (DOLL.money <= FALSE)
			{
				doll_gmeovr(); PUS break;
			}
			break;

		case 8: lotto();			ll break;
		case 9: dan_19();		ll break;
		case 10:
			CLS KABA.jumsu = FALSE;

			while (KABA.jumsu<10 && KABA.jumsu>-3)
			{
				kababo_menu(&KABA);
				scanf_s("%d", &num);

				switch (num)
				{
				case 1:kaba_how(); PUS break;
				case 2:CLS printf("가위, 바위, 보 중에 하나를 입력하세요 : ");
					scanf_s("%s", KABA.kaba, 10);

					if (!strcmp(KABA.kaba, "가위"))			//가위
						kaba_ka(&KABA);

					else if (!strcmp(KABA.kaba, "바위"))	//바위
						kaba_ba(&KABA);

					else if (!strcmp(KABA.kaba, "보"))		//보
						kaba_bo(&KABA);
					else
						printf("아니..가위바위보를 하라니까 뭘 입력한거야?");
					ll break;
				case 3:CLS C_60 printf("자...가위, 바위, 보 중에 하나를 입력하세요 : ");
					scanf_s("%s", KABA.kaba, 10);

					if (!strcmp(KABA.kaba, "가위"))		//가위
					{
						printf("\n당신의 선택은 \"가위\"입니다.");
						PS PS printf("가위...\t");
						PS PS printf("바위...\t");
						PS PS printf("보!\t\n\n");
						PS PS

							srand((int)time(NULL));
						KABA.ina = rand() % 2 + TRUE;

						switch (KABA.ina)
						{
						case 1: printf("당신 : 가위\n컴퓨터 : 보");
							printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
							KABA.jumsu += 10; ll break;

						case 2: printf("당신 : 가위\n컴퓨터 : 가위");
							printf("\n\n이런...비겼습니다. 5점을 잃었습니다...");
							KABA.jumsu -= 5; ll break;

						case 3: printf("당신 : 가위\n컴퓨터 : 보");
							printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
							KABA.jumsu -= 20; ll break;
						}
					}

					else if (!strcmp(KABA.kaba, "바위"))	//바위
					{
						printf("\n당신의 선택은 \"바위\"입니다.");
						PS PS printf("가위...\t");
						PS PS printf("바위...\t\n\n");
						PS PS printf("보!\t"); PS PS

							srand((int)time(NULL));
						KABA.ina = rand() % 2 + 1;

						switch (KABA.ina)
						{
						case 1:
							printf("당신 : 바위\n컴퓨터 : 가위");
							printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
							KABA.jumsu += 10; ll break;

						case 2:
							printf("당신 : 바위\n컴퓨터 : 바위");
							printf("\n\n이런...비겼습니다. 5점을 잃었습니다...");
							KABA.jumsu -= 5; ll break;

						case 3:
							printf("당신 : 바위\n컴퓨터 : 보");
							printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
							KABA.jumsu -= 20; ll break;
						}
					}

					else if (!strcmp(KABA.kaba, "보"))
					{
						printf("\n당신의 선택은 \"보\"입니다.");
						PS PS printf("가위...\t");
						PS PS printf("바위...\t");
						PS PS printf("보!\t\n\n"); PS PS

							srand((int)time(NULL));
						KABA.ina = rand() % 2 + 1;

						switch (KABA.ina)
						{
						case 1:
							printf("당신 : 보\n컴퓨터 : 바위");
							printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
							KABA.jumsu += 10; ll break;

						case 2:
							printf("당신 : 보\n컴퓨터 : 보");
							printf("\n\n이런...비겼습니다. 5점을 잃었습니다...");
							KABA.jumsu -= 5; ll break;

						case 3:
							printf("당신 : 보\n컴퓨터 : 가위");
							printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
							KABA.jumsu -= 20; ll break;
						}
					}

					else {
						printf("아니..가위바위보를 하라니까 뭘 입력한거야?"); PUS
					}
					break;

				case 4: goto main;
				default: printf("똑바로 입력해!!!\n"); ll break;
				}
			}

			if (KABA.jumsu >= 15) {
				CLS printf("당신의 이겼습니다. 축하드립니다. 메인으로 돌아갑니다.\n추가로, 명예점수 2점을 지급해 드립니다.\n");
				PUS honor += 2;
			}

			else if (KABA.jumsu < -2)
			{
				CLS	C_0C

					for (int qa = 0; qa < 2; qa++)
					{
						printf("이런, "); PS
					}

				printf("이런...."); PS
					printf("\n당신의 졌습니다(...). 유감입니다. 메인으로 돌아갑니다.\n");
				PUS C_0F
			}
			break;

		case 11:
			year/*변수*/ = get_year();
			day_code/*변수*/ = get_day_code(year);
			leap/*변수*/ = get_leap_year(year);
			print_calendar(year, day_code, leap); ll break;

		case 12:bmi(); ll break;
		case 13:
			SUTJA.kum = FALSE;			//금메달 초기화
			SUTJA.en = FALSE;			//은매달 초기화
			SUTJA.dong = FALSE;		//동메달 초기화

			while (TRUE)
			{
				sutja_menu(&SUTJA); scanf_s("%d", &num);

				switch (num)
				{
				case 1: howto_sutja();				break;
				case 2: sutja_easy(&SUTJA);		break;
				case 3: sutja_normal(&SUTJA);	break;
				case 4: sutja_hard(&SUTJA);		break;
				case 5:
					srand((unsigned)time(NULL));
					SUTJA.nansu = rand() % 88888 + 11111; CLS

						for (SUTJA.sido = FALSE; SUTJA.sido < 25; SUTJA.sido++)
						{
							printf("11111~99999중 맞을 것 같은 숫자를 입력하세요 : ");
							scanf_s("%d", &SUTJA.answ);

							if (SUTJA.answ == SUTJA.nansu)
							{

								(SUTJA.sido == TRUE) ? printf("한번에 맞히다니! 당신은 신이야!\n어쨌든 금, 은, 동메달 하나씩 획득하셨습니다!\n") :
									printf("%d번의 시도 끝에 정답을 맞혔습니다! \n금, 은, 동메달을 하나씩 획득하셨습니다.\n", SUTJA.sido);

								SUTJA.kum++; SUTJA.en++; SUTJA.dong++; _getch(); break;
							}

							else if (SUTJA.answ > SUTJA.nansu)
								printf("%d보다 작은 수입니다.\n", SUTJA.answ);

							else if (SUTJA.answ < SUTJA.nansu)
								printf("%d보다 큰 수입니다.\n", SUTJA.answ);
						}

					if (SUTJA.sido >= 25) {
						printf("이런...기회를 다 썼습니다.\n"); PUS
					}
					break;

				case 6:

					if (SUTJA.kum < 3)
					{
						printf("교환에 필요한 금메달이 부족합니다. \n금메달은 적어도 3개이상 필요합니다.\n");
						PUS break;
					}

					printf("금메달을 명예점수로 교환합니다. "); PUS
						honor += (SUTJA.kum / 3); SUTJA.other = SUTJA.kum % 3;
					printf("성공적으로 교환하였습니다.\n남은 금메달은 %d개 입니다.\n", SUTJA.other);
					SUTJA.kum = SUTJA.other;
					PUS break;

				case 7:

					if (SUTJA.en< 5) {
						printf("교환에 필요한 은메달이 부족합니다. \n은메달은 적어도 5개이상 필요합니다.\n"); PUS break;
					}

					printf("은메달을 금메달로 교환합니다. "); PUS
						SUTJA.kum += (SUTJA.en / 5); SUTJA.other = SUTJA.en % 5;
					printf("성공적으로 교환하였습니다.\n남은 은메달은 %d개 입니다.\n", SUTJA.other); SUTJA.en = SUTJA.other;
					PUS break;

				case 8:

					if (SUTJA.dong< 10) {
						printf("교환에 필요한 동메달이 부족합니다. \n동메달은 적어도 10개이상 필요합니다.\n"); PUS break;
					}

					printf("동메달을 은메달로 교환합니다. "); PUS
						SUTJA.en += (SUTJA.dong / 10); SUTJA.other = SUTJA.dong % 10;
					printf("성공적으로 교환하였습니다.\n남은 ,동메달은 %d개 입니다.\n", SUTJA.other); SUTJA.dong = SUTJA.other;
					PUS break;

				case 9:goto main;
				default:printf("숫자 모르니?"); ll break;
				}
			}
		case 14:

			while (TRUE)
			{
				CLS
					doum : MENU_BAR
					printf("\t\t\t\t\t\t\t도움말\n");
				MENU_BAR
					printf("1. 이 프로그램은 무엇인가요?\n");
				printf("2. 사용 방법\n");
				printf("3. 문제 해결\n");
				printf("4. 도움말 나가기\n");
				MENU_BAR
					scanf_s("%d", &num);

				switch (num)
				{
				case 1:
					CLS printf("나선우가 만든 일종의 계산기 프로그램 입니다.\n");
					printf("꾸준히 업데이트 되고 있으며 미래의 자신의 나이, 라면 끓이는 시간\n");
					printf("등을 알 수 있는 획기적인 프로그램 입니다.\n");			ll break;

				case 2:
					CLS printf("메인화면에서 원하는 것의 숫자를 입력하세요. 프로그램의 지시에 따라 주세요.\n");
					printf("문장이 표시되거나 값을 입력했을 땐 반드시 Enter 키를 눌러 주세요.\n");	ll break;

				case 3:

					while (TRUE)
					{
						CLS
							MENU_BAR
							printf("\t\t\t\t\t\t\t문제 해결\n");
						MENU_BAR
							printf("1. 커서만 뜨고 아무것도 뜨지 않아요.\n");
						printf("2. 창이 계속 깜빡이고 키보드가 말을 듣지 않아요.\n");
						printf("3. 평소와 다른 말이 뜨고 키 입력이 되지 않아요.\n");
						printf("4. 경고창이 뜨고 프로그램이 멈춰요.\n");
						printf("5. 도움말로 돌아가기\n");
						MENU_BAR
							scanf_s("%d", &num);
						switch (num)
						{
						case 1:CLS printf("Enter 키를 눌러보세요.\n");																					ll break;
						case 2: CLS printf("잘못된 값을 입력 했을 때 나타나는 현상입니다.\n프로그램을 재시작 해 주세요.\n");	ll break;
						case 3:CLS printf("오류입니다. 프로그램을 재시작해 주세요.\n");														ll break;
						case 4:CLS printf("프로그램의 알려지지 않은 버그입니다.\n******@*****.***\n");
							printf("으로 하실려던 작업, 메세지 내용등을 제보해 주십시오.\n");													ll break;

						case 5:CLS goto doum;
						default:printf("문제 해결에 없는 항목입니다.");
						}
					}
					ll break;
				case 4: goto main;
				default: printf("도움말에 없는 항목입니다.\n");
				}
			}
			ll break;

		case 15: CLS
			_getch(); break;
		case 16: dvlp_overcalc(); break;
		case 17:

			CLS
				if (honor < 30)
				{
					printf("\n명예점수가 30점 이상인 경우에만 가능합니다.\n"); PUS break;
				}

			printf("이 키를 복사하시면 PRO버전을 이용하실 수 있습니다.\n");

			for (int z = 0; z < 29; z++)							//z가 0이고, z가 29 미만일 동안 출력 - 총 29개의 문자를 출력
			{
				if ((z + 1) % 6 == 0 && z != 0)				//z가 0이 아니고 z에 1을 더한 값이 6으로 나누어 떨어진다면
				{
					printf("-");											//(숫자 혹은 영문자5개 출력후) '-' 출력;
					prokey[z] = '-';									//제품키의 z부분에 '-' 문자를 삽입
				}

				else if ((z + 1) % 4 != 0)							//아니라면 z에 1을 더한 값이 4로 나누어 떨어지지 않는다면
				{
					asdf = rand() % 26 + 65;					//대문자 A~Z를
					printf("%c", asdf);								//출력
					prokey[z] = asdf;								//z부분에 영문자 삽입
				}

				else if ((z + 1) % 4 == 0)						//그게 또 아니라면 z에 1을 더한 값이 4로 나누어 떨어 진다면
				{
					qwer = rand() % 8 + 49;					//49~57=char 1~9(정수가 아닌 문자)
					printf("%c", qwer);								//를 출력하고
					prokey[z] = qwer;								//z부분에 숫자 삽입
				}
			}
			/*끝났다면 prokey배열이 완성된 것임*/

			printf("\n\n이 키는 비상용 키로, 인증은 되지 않지만 pro버전의 일부를 사용할 수 있습니다.\n");

			char nonkey[10] = "M2JX82MA";					//인증이 안되는 제품키
			printf("%s\n", nonkey);

			ll break;

		case 18:

			while (TRUE)												//그냥 1
			{
				printf("제품키를 입력하세요...");
				scanf_s("%s", key_real, sizeof(key_real));
				if (!strcmp(key_real, prokey))
				{
					activation(); goto pro;
				}

				else if (!strcmp(key_real, "M2JX82MA"))
					goto nonpro;

				else if (!strcmp(key_real, "exit"))
					break;

				else
					printf("제품키를 확인해 주세요. 취소하시려면 exit를 입력하세요.\n");
			}
			break;
		case 'q':
		case 'Q': exit(FALSE);
		default:printf("잘못된 숫자를 입력하셨습니다.\n1~18중에 선택해 주십시오.\n"); ll
		}
	}

	/*Pro버전*/
	while (TRUE)
	{
	pro:

		if (x < TRUE)
		{
			boot_pro(); x = 1;
		}

		CLS C_5F
			PRO_BAR		PRO_TITLE		HONOR		PRO_BAR
			printf("1. 나의 나이는 0000년에 몇 살일까?\n");
		printf("2. 타이머\n");											//나이 계산기
		printf("3. 라면 분석기\n");									//라면 시간 계산기
		printf("4. 진짜 계산기(1회용)\n");
		printf("5. 미세먼지가 나쁨인가?(일반)\n");
		printf("6. 미세먼지가 나쁨인가?(전문가용)\n");
		printf("7. 인형 뽑기 게임하기\n");						//인형뽑기
		printf("8. 로또 번호 출력\n");								//로또
		printf("9. 19단\n");												//19단 표 출력
		printf("10. 가위바위보 게임\n");
		printf("11. 달력 출력\n");
		printf("12. BMI 계산하기\n");
		printf("13. 숫자 맞히기\n");
		printf("14. 도움말\n");
		printf("15. 원주율 출력하기\n");
		printf("16. Overcalc의 역사와 발전\n");
		printf("17. Enterprise 제품키 받기(준비중)\n");
		printf("18. Enterprise로 업그레이드(준비중)\n");
		printf("Q. 나가기\n");
		PRO_BAR
			printf("번호를 입력하세요 : ");
		scanf_s("%d", &num);//char형 정수는 %hhd

		switch (num)
		{
		case 1: agecalc_pro(); ll break;
		case 2: timer(); break;
		case 3: ramen_pro(); ll break;
		case 4: calc_pro(); ll break;
		case 5: monji_normal(); ll break;
		case 6: monji_hard(); ll break;
		case 7:	CLS DOLL.money = 6000;

			while (DOLL.money>FALSE)
			{

				if (DOLL.money >= 100000) {
					printf("축하합니다! 잔액이 100000원이상입니다.\n게임을 클리어 하셨습니다.\n명예점수 5점이 올라갑니다.\n"); PUS honor += 5; break;
				}

				num2 = menu_doll_pro(DOLL.money);

				switch (num2)
				{
				case 1: dollgame_pro(&DOLL);		PUS	break;
				case 2: doll_shake(&DOLL);					break;
				case 3: kind_of_doll_pro();				PUS	break;
				case 4: doll_activ(&DOLL);						break;
				case 5: goto pro;
				default: printf("도데체 뭘 누른거야?"); ll	break;
				}
				C_5F CLS
			}

			(DOLL.money <= FALSE) ? doll_gmeovr(), system("pause") : printf("현재 명예점수는 %d점 입니다.\n", honor), PUS break;

		case 8: lotto_pro();		 ll break;
		case 9: dan_19();			 ll break;
		case 10:
			CLS KABA.jumsu = FALSE;

			while (KABA.jumsu<10 && KABA.jumsu>-3)
			{
				kababo_menu(&KABA); scanf_s("%d", &num);

				switch (num)
				{
				case 1:kaba_how(); PUS break;
				case 2:
					CLS printf("가위, 바위, 보 중에 하나를 입력하세요 : ");
					scanf_s("%s", KABA.kaba, 10);

					if (!strcmp(KABA.kaba, "가위")) {
						kaba_ka(&KABA); ll break;
					}

					else if (!strcmp(KABA.kaba, "바위")) {
						kaba_ba(&KABA); ll break;
					}

					else if (!strcmp(KABA.kaba, "보")) {
						kaba_bo(&KABA); ll break;
					}

					else {
						printf("아니..가위바위보를 하라니까 뭘 입력한거야?"); ll break;
					}

				case 3:
					CLS C_60 printf("자...가위, 바위, 보 중에 하나를 입력하세요 : ");
					scanf_s("%s", KABA.kaba, 10);

					if (!strcmp(KABA.kaba, "가위"))		//가위
					{
						printf("\n당신의 선택은 \"가위\"입니다.\n\n");
						PS PS printf("가위...\t");
						PS PS printf("바위...\t");
						PS PS printf("보!\t");
						PS PS printf("\n\n");

						srand((int)time(NULL));
						KABA.ina = rand() % 2 + TRUE;

						switch (KABA.ina)
						{
						case 1: printf("당신 : 가위\n컴퓨터 : 보");
							printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
							KABA.jumsu += 10;	ll break;

						case 2: printf("당신 : 가위\n컴퓨터 : 가위");
							printf("\n\n이런...비겼습니다. 5점을 잃었습니다...");
							KABA.jumsu -= 5;		ll break;

						case 3: printf("당신 : 가위\n컴퓨터 : 보");
							printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
							KABA.jumsu -= 20;	ll break;
						}
						break;
					}

					else if (!strcmp(KABA.kaba, "바위"))	//바위
					{
						printf("\n당신의 선택은 \"바위\"입니다.");
						PS PS printf("가위...\t");
						PS PS printf("바위...\t");
						PS PS printf("보!\t");
						PS PS printf("\n\n");

						srand((int)time(NULL));
						KABA.ina = rand() % 2 + TRUE;

						switch (KABA.ina)
						{
						case 1: printf("당신 : 바위\n컴퓨터 : 가위");
							printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
							KABA.jumsu += 10;	ll break;

						case 2: printf("당신 : 바위\n컴퓨터 : 바위");
							printf("\n\n이런...비겼습니다. 5점을 잃었습니다...");
							KABA.jumsu -= 5;		ll break;

						case 3: printf("당신 : 바위\n컴퓨터 : 보");
							printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
							KABA.jumsu -= 20;	ll break;
						}
						break;
					}
					else if (!strcmp(KABA.kaba, "보")) {
						printf("\n당신의 선택은 \"보\"입니다.");
						PS PS printf("가위...\t");
						PS PS printf("바위...\t");
						PS PS printf("보!\t");
						PS PS printf("\n\n");

						srand((int)time(NULL));
						KABA.ina = rand() % 2 + 1;

						switch (KABA.ina)
						{
						case 1: printf("당신 : 보\n컴퓨터 : 바위");
							printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
							KABA.jumsu += 10;	ll break;

						case 2: printf("당신 : 보\n컴퓨터 : 보");
							printf("\n\n이런...비겼습니다. 5점을 잃었습니다...");
							KABA.jumsu -= 5;		ll break;

						case 3: printf("당신 : 보\n컴퓨터 : 가위");
							printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
							KABA.jumsu -= 20;	ll break;
						}
						break;
					}

					else
					{
						printf("아니..가위바위보를 하라니까 뭘 입력한거야?"); PUS break;
					}

				case 4:goto main;
				default:printf("똑바로 입력해!!!\n"); _getch(); break;
				}
			}

			if (KABA.jumsu >= 10) {
				CLS printf("당신의 이겼습니다. 축하드립니다. 메인으로 돌아갑니다.\n추가로, 명예점수 2점을 지급해 드립니다.\n");
				PUS honor++; honor++; break;
			}

			else if (KABA.jumsu < -2)
			{
				CLS C_0C
					printf("이런, "); PS printf("이런, "); PS printf("이런...."); PS
					printf("\n당신의 졌습니다. 유감입니다. 메인으로 돌아갑니다.\n"); PUS
					C_0F break;
			}

		case 11:
			year = get_year();
			day_code = get_day_code(year);
			leap = get_leap_year(year);
			print_calendar(year, day_code, leap);
			ll break;

		case 12:bmi();		ll break;
		case 13:
			SUTJA.kum = FALSE;		//
			SUTJA.en = FALSE;		//
			SUTJA.dong = FALSE;	//

			while (TRUE)
			{
				sutja_menu(&SUTJA);
				scanf_s("%d", &num);

				switch (num)
				{
				case 1: howto_sutja();				break;
				case 2: sutja_easy(&SUTJA);		break;
				case 3: sutja_normal(&SUTJA);	break;
				case 4: sutja_hard(&SUTJA);		break;
				case 5:
					srand((unsigned)time(NULL));
					SUTJA.nansu = rand() % 88888 + 11111; CLS

						for (SUTJA.sido = FALSE; SUTJA.sido < 25; SUTJA.sido++) {
							printf("11111~99999중 맞을 것 같은 숫자를 입력하세요 : ");
							scanf_s("%d", &SUTJA.answ);

							if (SUTJA.answ == SUTJA.nansu)
							{
								(SUTJA.sido == TRUE) ? printf("한번에 맞히다니! 당신은 신이야!\n어쨌든 금, 은, 동메달 하나씩 획득하셨습니다!\n") :
									printf("%d번의 시도 끝에 정답을 맞혔습니다! \n금, 은, 동메달을 하나씩 획득하셨습니다.\n", SUTJA.sido);

								SUTJA.kum++; SUTJA.en++; SUTJA.dong++; _getch(); break;
							}

							else if (SUTJA.answ > SUTJA.nansu)
								printf("%d보다 작은 수입니다.\n", SUTJA.answ);

							else if (SUTJA.answ < SUTJA.nansu)
								printf("%d보다 큰 수입니다.\n", SUTJA.answ);
						}

					if (SUTJA.sido >= 25) {
						printf("이런...기회를 다 썼습니다.\n"); PUS
					}
					break;

				case 6:
					if (SUTJA.kum < 3) {
						printf("교환에 필요한 금메달이 부족합니다. \n금메달은 적어도 3개이상 필요합니다.\n"); PUS break;
					}

					printf("금메달을 명예점수로 교환합니다. "); PUS
						honor += (SUTJA.kum / 3);
					SUTJA.other = SUTJA.kum % 3;

					printf("성공적으로 교환하였습니다.\n남은 금메달은 %d개 입니다.\n", SUTJA.other);
					SUTJA.kum = SUTJA.other;
					PUS break;

				case 7:
					if (SUTJA.en< 5)
					{
						printf("교환에 필요한 은메달이 부족합니다. \n은메달은 적어도 5개이상 필요합니다.\n"); PUS break;
					}

					printf("은메달을 금메달로 교환합니다. "); PUS
						SUTJA.kum += (SUTJA.en / 5);
					SUTJA.other = SUTJA.en % 5;
					printf("성공적으로 교환하였습니다.\n남은 은메달은 %d개 입니다.\n", SUTJA.other);
					SUTJA.en = SUTJA.other;
					PUS break;

				case 8:
					if (SUTJA.dong< 10)
					{
						printf("교환에 필요한 동메달이 부족합니다. \n동메달은 적어도 10개이상 필요합니다.\n"); PUS break;
					}

					printf("동메달을 은메달로 교환합니다. "); PUS
						SUTJA.en += (SUTJA.dong / 10);
					SUTJA.other = SUTJA.dong % 10;
					printf("성공적으로 교환하였습니다.\n남은 ,동메달은 %d개 입니다.\n", SUTJA.other);
					SUTJA.dong = SUTJA.other;
					PUS break;

				case 9:goto main;
				default:printf("숫자 모르니?"); ll break;
				}
			}

		case 14:CLS

			while (TRUE)
			{

				PRO_BAR
					printf("\t\t\t도움말\n");
				PRO_BAR
					printf("1. 이 프로그램은 무엇인가요?\n");
				printf("2. 사용 방법\n");
				printf("3. 문제 해결\n");
				printf("4. 도움말 나가기\n");
				PRO_BAR
					scanf_s("%d", &num);
				switch (num)
				{
				case 1:CLS printf("나선우가 만든 일종의 계산기 프로그램 입니다.\n꾸준히 업데이트 되고 있으며 미래의 자신의 나이, 라면 끓이는 시간\n등을 알 수 있는 획기적인 프로그램 입니다.\n"); ll break;
				case 2:CLS printf("메인화면에서 원하는 것의 숫자를 입력하세요. 프로그램의 지시에 따라 주세요.\n문장이 표시되거나 값을 입력했을 땐 반드시 Enter 키를 눌러 주세요.\n"); ll break;
				case 3:CLS

					while (TRUE)
					{
						PRO_BAR
							printf("\t\t\t문제 해결");
						PRO_BAR
							printf("1. 커서만 뜨고 아무것도 뜨지 않아요.\n");
						printf("2. 창이 계속 깜빡이고 키보드가 말을 듣지 않아요.\n");
						printf("3. 평소와 다른 말이 뜨고 키 입력이 되지 않아요.\n");
						printf("4. 도움말로 돌아가기\n");
						PRO_BAR
							scanf_s("%d", &num);
						switch (num)
						{
						case 1:CLS printf("Enter 키를 눌러보세요.\n"); ll break;
						case 2: CLS printf("잘못된 값을 입력 했을 때 나타나는 현상입니다.\n프로그램을 재시작 해 주세요.\n"); ll break;
						case 3:CLS printf("오류입니다. 프로그램을 재시작해 주세요.\n"); ll break;
						case 4:CLS goto doum;
						default:printf("문제 해결에 없는 항목입니다.");
						}
						CLS
							break;
					}
					   ll break;
				case 4: goto main;
				default:printf("도움말에 없는 항목입니다.\n");
				}
				CLS

					break;
			}
				ll break;
		case 15:
		case 16: dvlp_overcalc(); ll break; //16. Overcalc의 역사와 발전
		case 17:
		case 18:printf("메뉴 준비중입니다."); ll break;
		case 'q':
		case 'Q': exit(FALSE);
		default:printf("잘못된 숫자를 입력하셨습니다.\n1~18중에 선택해 주십시오.\n"); ll break;
		}
		CLS
	}

	/*정품인증이 되지않은 프로버전*/
	while (TRUE)
	{
	nonpro:

		if (x < TRUE)
		{
			boot_nonpro(); x++;
		}

		actwarn();											//화면 지움, 색깔 변화, 정품 인증 경고
		PRO_BAR		PRO_TITLE		HONOR		PRO_BAR
			printf("1. 나의 나이는 0000년에 몇 살일까?\n");
		printf("2. 메뉴 준비중\n");									//나이 계산기
		printf("3. 라면 분석기\n");									//라면 시간 계산기
		printf("4. 진짜 계산기(1회용)\n");
		printf("5. 미세먼지가 나쁨인가?(일반)\n");
		printf("6. 미세먼지가 나쁨인가?(전문가용)\n");
		printf("7. 인형 뽑기 게임하기\n");						//인형뽑기
		printf("8. 로또 번호 출력\n");								//로또
		printf("9. 19단\n");												//19단 표 출력
		printf("10. 가위바위보 게임\n");
		printf("11. 달력 출력\n");
		printf("12. BMI 계산하기\n");
		printf("13. 숫자 맞히기\n");
		printf("14. 도움말\n");
		printf("15. 원주율 출력\n");
		printf("16. Overcalc의 업데이트 소식\n");
		printf("17. 정품 인증용 제품키 받기\n");
		printf("18. 정품 인증\n");
		printf("Q. 나가기\n");
		PRO_BAR
			printf("번호를 입력하세요 : ");
		scanf_s("%d", &num);//char형 정수는 %hhd

		switch (num)
		{
		case 1: age_calc();				ll break;
		case 2: printf("아직...");		ll break;
		case 3: ramen_pro();			ll break;
		case 4: calc_pro();				ll break;
		case 5: monji_normal();		ll break;
		case 6: monji_hard();			ll break;
		case 7:	CLS DOLL.money = 6000;

			while (DOLL.money>FALSE)
			{

				if (DOLL.money >= 50000)
				{
					printf("축하합니다! 잔액이 50000원이상입니다.\n게임을 클리어 하셨습니다.\n명예점수 3점이 올라갑니다.\n");
					PUS honor += 3; break;
				}//게임 끝

				num2 = doll_menu(&DOLL);

				switch (num2)
				{
				case 1: doll_game(&DOLL);	PUS			break;
				case 2: kind_of_doll();			PUS			break;
				case 3: doll_activ(&DOLL);						break;
				case 4: goto next;
				default: printf("도데체 뭘 누른거야?"); ll	break;
				}
				C_07 CLS
			}

			if (DOLL.money <= FALSE)										//만약 인형뽑기의 잔액이 0원 이하라면
			{
				doll_gmeovr(); PUS break;										//게임오버 화면을 출력해라
			}

		case 8: lotto();		ll break;
		case 9: dan_19();	ll break;
		case 10: CLS; KABA.jumsu = FALSE;

			while (KABA.jumsu<10 && KABA.jumsu>-3)
			{
				kababo_menu(&KABA);
				scanf_s("%d", &num);

				switch (num)
				{
				case 1:kaba_how(); PUS break;
				case 2:
					CLS printf("가위, 바위, 보 중에 하나를 입력하세요 : ");
					scanf_s("%s", KABA.kaba, 10);

					if (!strcmp(KABA.kaba, "가위"))			//가위
					{
						kaba_ka(&KABA); ll break;
					}

					else if (!strcmp(KABA.kaba, "바위"))	//바위
					{
						kaba_ba(&KABA); ll break;
					}

					else if (!strcmp(KABA.kaba, "보"))
					{
						kaba_bo(&KABA); ll break;
					}

					else
					{
						printf("아니..가위바위보를 하라니까 뭘 입력한거야?"); ll break;
					}

				case 3:
					CLS C_60
						printf("자...가위, 바위, 보 중에 하나를 입력하세요 : ");
					scanf_s("%s", KABA.kaba, 10);

					if (!strcmp(KABA.kaba, "가위"))		//가위
					{
						printf("\n당신의 선택은 \"가위\"입니다."); PS PS
							printf("가위...\t"); PS PS printf("바위...\t"); PS PS printf("보!\t"); PS PS
							printf("\n\n");

						srand((int)time(NULL));

						KABA.ina = rand() % 2 + 1;

						switch (KABA.ina)
						{
						case 1:
							printf("당신 : 가위\n컴퓨터 : 보");
							printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
							KABA.jumsu += 10; ll break;
						case 2:
							printf("당신 : 가위\n컴퓨터 : 가위");
							printf("\n\n이런...비겼습니다. 5점을 잃었습니다..."); KABA.jumsu -= 5; ll break;
						case 3:
							printf("당신 : 가위\n컴퓨터 : 보");
							printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
							KABA.jumsu -= 20; ll break;
						}
						break;
					}

					else if (!strcmp(KABA.kaba, "바위"))	//바위
					{
						printf("\n당신의 선택은 \"바위\"입니다."); Sleep(2000);
						printf("가위...\t"); Sleep(2000); printf("바위...\t"); Sleep(2000); printf("보!\t"); Sleep(2000);
						printf("\n\n");

						srand((int)time(NULL));
						KABA.ina = rand() % 2 + 1;

						if (KABA.ina == 1)
						{
							printf("당신 : 바위\n컴퓨터 : 가위");
							printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
							KABA.jumsu += 10; ll
						}

						else if (KABA.ina == 2)
						{
							printf("당신 : 바위\n컴퓨터 : 바위");
							printf("\n\n이런...비겼습니다. 5점을 잃었습니다..."); KABA.jumsu -= 5; ll
						}

						else if (KABA.ina == 3)
						{
							printf("당신 : 바위\n컴퓨터 : 보");
							printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
							KABA.jumsu -= 20; ll
						}
						break;
					}

					else if (!strcmp(KABA.kaba, "보"))
					{
						printf("\n당신의 선택은 \"보\"입니다."); Sleep(2000);
						printf("가위...\t"); Sleep(2000); printf("바위...\t"); Sleep(2000); printf("보!\t"); Sleep(2000);
						printf("\n\n");

						srand((int)time(NULL));
						KABA.ina = rand() % 2 + 1;

						if (KABA.ina == 1)
						{
							printf("당신 : 보\n컴퓨터 : 바위");
							printf("\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!");
							KABA.jumsu += 10; ll
						}

						else if (KABA.ina == 2)
						{
							printf("당신 : 보\n컴퓨터 : 보");
							printf("\n\n이런...비겼습니다. 5점을 잃었습니다..."); KABA.jumsu -= 5; ll
						}

						else if (KABA.ina == 3)
						{
							printf("당신 : 보\n컴퓨터 : 가위");
							printf("\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...");
							KABA.jumsu -= 20; ll
						}
						break;
					}

					else
					{
						printf("아니..가위바위보를 하라니까 뭘 입력한거야?");
						PUS break;
					}
				case 4:goto main;
				default:printf("똑바로 입력해!!!\n"); ll
					break;
				}

			}

			if (KABA.jumsu >= 10)
			{
				CLS
					printf("당신의 이겼습니다. 축하드립니다. 메인으로 돌아갑니다.\n추가로, 명예점수 2점을 지급해 드립니다.\n"); PUS
					honor++; honor++; break;
			}

			else if (KABA.jumsu < -2)
			{
				CLS
					C_0C
					printf("이런, "); Sleep(900); printf("이런, "); Sleep(900); printf("이런...."); Sleep(900);
				printf("\n당신의 졌습니다. 유감입니다. 메인으로 돌아갑니다.\n"); PUS
					C_0F break;
			}

		case 11:
			year = get_year();
			day_code = get_day_code(year);
			leap = get_leap_year(year);
			print_calendar(year, day_code, leap);
			ll break;

		case 12:bmi(); ll break;
		case 13:SUTJA.kum = FALSE; SUTJA.en = FALSE; SUTJA.dong = FALSE;

			while (TRUE)
			{
				sutja_menu(&SUTJA); scanf_s("%d", &num);

				switch (num)
				{
				case 1: howto_sutja(); break;
				case 2: sutja_easy(&SUTJA); break;
				case 3: sutja_normal(&SUTJA); break;
				case 4: sutja_hard(&SUTJA); break;
				case 5:srand((unsigned)time(NULL));
					SUTJA.nansu = rand() % 88888 + 11111; CLS
						for (SUTJA.sido = FALSE; SUTJA.sido < 25; SUTJA.sido++) {
							printf("11111~99999중 맞을 것 같은 숫자를 입력하세요 : ");
							scanf_s("%d", &SUTJA.answ);
							if (SUTJA.answ == SUTJA.nansu) {
								(SUTJA.sido == TRUE) ? printf("한번에 맞히다니! 당신은 신이야!\n어쨌든 금, 은, 동메달 하나씩 획득하셨습니다!\n") :
									printf("%d번의 시도 끝에 정답을 맞혔습니다! \n금, 은, 동메달을 하나씩 획득하셨습니다.\n", SUTJA.sido);
								SUTJA.kum++; SUTJA.en++; SUTJA.dong++; _getch(); break;
							}
							else if (SUTJA.answ > SUTJA.nansu)
								printf("%d보다 작은 수입니다.\n", SUTJA.answ);
							else if (SUTJA.answ < SUTJA.nansu)
								printf("%d보다 큰 수입니다.\n", SUTJA.answ);
						}
					if (SUTJA.sido >= 25) {
						printf("이런...기회를 다 썼습니다.\n"); PUS break;
					}
				case 6:
					if (SUTJA.kum < 3) {
						printf("교환에 필요한 금메달이 부족합니다. \n금메달은 적어도 3개이상 필요합니다.\n"); PUS break;
					}
					printf("금메달을 명예점수로 교환합니다. "); PUS honor += (SUTJA.kum / 3); SUTJA.other = SUTJA.kum % 3;
					printf("성공적으로 교환하였습니다.\n남은 금메달은 %d개 입니다.\n", SUTJA.other); SUTJA.kum = SUTJA.other;
					PUS break;
				case 7:
					if (SUTJA.en< 5) {
						printf("교환에 필요한 은메달이 부족합니다. \n은메달은 적어도 5개이상 필요합니다.\n"); PUS break;
					}
					printf("은메달을 금메달로 교환합니다. "); PUS SUTJA.kum += (SUTJA.en / 5); SUTJA.other = SUTJA.en % 5;
					printf("성공적으로 교환하였습니다.\n남은 은메달은 %d개 입니다.\n", SUTJA.other); SUTJA.en = SUTJA.other;
					PUS break;
				case 8:
					if (SUTJA.dong< 10) {
						printf("교환에 필요한 동메달이 부족합니다. \n동메달은 적어도 10개이상 필요합니다.\n"); PUS break;
					}
					printf("동메달을 은메달로 교환합니다. "); PUS SUTJA.en += (SUTJA.dong / 10); SUTJA.other = SUTJA.dong % 10;
					printf("성공적으로 교환하였습니다.\n남은 ,동메달은 %d개 입니다.\n", SUTJA.other); SUTJA.dong = SUTJA.other;
					PUS break;
				case 9:goto main;
				default:printf("숫자 모르니?"); ll break;
				}
			}
		case 14:CLS
			while (TRUE)
			{
				PRO_BAR
					printf("\t\t\t도움말\n");
				PRO_BAR
					printf("1. 이 프로그램은 무엇인가요?\n");
				printf("2. 사용 방법\n");
				printf("3. 문제 해결\n");
				printf("4. 도움말 나가기\n");
				PRO_BAR
					scanf_s("%d", &num);
				switch (num)
				{
				case 1:CLS printf("나선우가 만든 일종의 계산기 프로그램 입니다.\n꾸준히 업데이트 되고 있으며 미래의 자신의 나이, 라면 끓이는 시간\n등을 알 수 있는 획기적인 프로그램 입니다.\n"); ll break;
				case 2:CLS printf("메인화면에서 원하는 것의 숫자를 입력하세요. 프로그램의 지시에 따라 주세요.\n문장이 표시되거나 값을 입력했을 땐 반드시 Enter 키를 눌러 주세요.\n"); ll break;
				case 3:CLS
					while (TRUE)
					{
						PRO_BAR
							printf("\t\t\t문제 해결\n");
						PRO_BAR
							printf("1. 커서만 뜨고 아무것도 뜨지 않아요.\n");
						printf("2. 창이 계속 깜빡이고 키보드가 말을 듣지 않아요.\n");
						printf("3. 평소와 다른 말이 뜨고 키 입력이 되지 않아요.\n");
						printf("4. 도움말로 돌아가기\n");
						PRO_BAR
							scanf_s("%d", &num);
						switch (num)
						{
						case 1:CLS printf("Enter 키를 눌러보세요.\n"); ll break;
						case 2: CLS printf("잘못된 값을 입력 했을 때 나타나는 현상입니다.\n프로그램을 재시작 해 주세요.\n"); ll break;
						case 3:CLS printf("오류입니다. 프로그램을 재시작해 주세요.\n"); ll break;
						case 4:CLS goto doum;
						default:printf("문제 해결에 없는 항목입니다.");
						}
						CLS
							break;
					}
					   ll break;
				case 4: goto main;
				default:printf("도움말에 없는 항목입니다.\n");
				}
				CLS break;
			}
				ll break;
		case 15:
		case 16: dvlp_overcalc(); ll break;
		case 17:
			CLS
				if (honor < 12)
				{
					printf("\n명예점수가 12점 이상인 경우에만 가능합니다.\n"); PUS break;
				}

			printf("이 키를 복사하시면 PRO버전을 인증하실 수 있습니다.\n");
			printf("그동안 인증 메세지 때문에 많이 힘드셨죠?\n");

			for (int zl = 0; zl < 13; zl++)
			{
				if ((zl + 1) % 4 == 0 && zl != 0 && (zp == 0))			//zl이 0이 아니고 zl에 1을 더한 값이 4로 나누어 떨어지고 zp가 0이라면
				{
					printf("-");																	//(숫자 혹은 영문자3개 출력후) '-' 출력
					actkey[zl] = '-';															//제품키의 zl부분에 '-' 문자를 삽입
					++zp;																		//zp는 1이 되어 이 if 문에 접근이 불가
				}

				else if (zl != 0 && zp == 1 && (zl + 1) % 11 == 0)	//zl이 0이 아니고 zl에 1을 더한 값이 11로 나누어 떨어지고 zp가 0이라면
				{
					printf("-");																	//(숫자 혹은 영문자 6개 추가 출력후) 두번째 '-' 출력
					actkey[zl] = '-';															//제품키의 zl부분에 '-' 문자를 삽입
					++zp;																		//zp는 2가되어 이 else if 문에 접근이 불가
				}

				else if ((zl + 1) % 3 != 0)											//아니라면 zl에 1을 더한 값이 3으로 나누어 떨어지지 않는다면
				{
					asdf = rand() % 26 + 65;											//대문자 A~Z를
					printf("%c", asdf);														//출력
					actkey[zl] = asdf;														//zl부분에 영문자 삽입
				}

				else if ((zl + 1) % 3 == 0)											//그게 또 아니라면 zl에 1을 더한 값이 4로 나누어 떨어 진다면
				{
					qwer = rand() % 8 + 49;											//49~57 = char 1~9(정수가 아닌 문자)
					printf("%c", qwer);														//를 출력하고
					actkey[zl] = qwer;														//zl부분에 숫자 삽입
				}
			}
			ll break;

		case 18:
			while (TRUE)
			{
				CLS printf("제품키를 입력하세요...");
				scanf_s("%s", act_in, sizeof(act_in));

				if (!strcmp(act_in, actkey))
				{
					activation(); goto pro;
				}
				else if (!strcmp(key_real, "exit"))
					break;

				else
					printf("제품키를 확인해 주세요. 취소하시려면 exit를 입력하세요.\n"); ll
			}
			break;
		case 'q':
		case 'Q': exit(FALSE);
		default:printf("잘못된 숫자를 입력하셨습니다.\n1~18중에 선택해 주십시오.\n"); ll
		}
		CLS
	}

	/*이제 끝*/return 0;
}

int get_year()
{
	int year = -TRUE;
	printf("년도를 입력하세요 : ");
	scanf_s("%d", &year);
	return year;
}

int get_day_code(int year)
{
	int day_code;
	double x1, x2, x3;
	x1 = (year - 1.) / 4.0;
	x2 = (year - 1.) / 100.;
	x3 = (year - 1.) / 400.;
	day_code = (year + (int)x1 - (int)x2 + (int)x3) % 7;
	return day_code;
}

/*윤년을 가림*/				int get_leap_year(int year)
{
	/*윤년은 4의 배수이자 100의 배수이면 안되고, 400의 배수여야 한다.*/
	if (((year % 4 == FALSE) && (year % 100 != FALSE)) || (year % 400 == FALSE))
		return TRUE;

	else
		return FALSE;
}

void print_calendar(int year, int day_code, int leap) //function header
{
	int days_in_month;		//그 달에 있는 날짜의 수
	int day;							/* counter for day of month */
	int month;					// month = 1은 1월, 2는 2월 등
	printf("\t\t\t\t%d", year);
	for (month = 1; month <= 12; month++)
	{
		switch (month)
		{
			/* print name and set days_in_month */
		case 1:		printf("\n\n1월, January");			days_in_month = 31;						break;
		case 2:		printf("\n\n2월, February");		days_in_month = leap ? 29 : 28;	break;
		case 3:		printf("\n\n3월, March");			days_in_month = 31;						break;
		case 4:		printf("\n\n4월, April");				days_in_month = 30;						break;
		case 5:		printf("\n\n5월, May");				days_in_month = 31;						break;
		case 6:		printf("\n\n6월, June");				days_in_month = 30;						break;
		case 7:		printf("\n\n7월, July");				days_in_month = 31;						break;
		case 8:		printf("\n\n8월, August");			days_in_month = 31;						break;
		case 9:		printf("\n\n9월, September");	days_in_month = 30;						break;
		case 10:	printf("\n\n10원, October");		days_in_month = 31;						break;
		case 11:	printf("\n\n11월, November");	days_in_month = 30;						break;
		case 12:	printf("\n\n12월, December");	days_in_month = 31;						break;
		}
		printf("\n\n일(Sun)\t월(Mon)\t화(Tue)\t수(Wed)\t목(Thu)\t금(Fri)\t토(Sat)\n");

		for (day = 1; day < day_code + 1; day++)
			printf("\t");

		for (day = 1; day <= days_in_month; day++)
		{
			printf("%2d", day);
			if ((day + day_code) % 7 > FALSE)
				printf("\t");
			else if (day != days_in_month)
				printf("\n");
		}

		day_code = (day_code + days_in_month) % 7;
	}
}

void PRINT(const char* msg, int a, int b, int op, CALC *calc)
{
	// op가 0이면 Add함수, 1(Sub), 2(Mul), 3(Div), 4(Mok) 함수 호출
	printf(msg, a, b, (calc[op])(a, b));
}

/*나이 계산기*/				void age_calc()
{
	int year1 = FALSE;//현재 년도
	int year2 = FALSE;//두 번째 년도
	int chai = FALSE;//year1과 year2의 차이
	int age1 = FALSE;//나이
	char nam[10];//이름
	CLS C_8A printf("이름을 입력하세요...\n"); scanf_s("%s", &nam, sizeof(nam));
	printf("현재 년도를 입력하세요...\n"); scanf_s("%d", &year1);
	printf("현재 나이를 입력하세요...\n"); scanf_s("%d", &age1);
	printf("나이를 알고싶은 연도를 입력하세요...\n"); scanf_s("%d", &year2);
	chai = year2 - year1;
	printf("%d년에 %s님의 나이는 %d살 입니다\n", year2, nam, chai + age1);
}

/*라면 시간 계산기*/		void ramen_calc()
{
	char ramen[10];//라면 이름
	CLS C_A3 printf("라면의 이름을 입력하세요 : "); scanf_s("%s", ramen, sizeof(ramen));
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
	ll
}

/*콩 스탬프 계산기*/		void kong_calc()
{
	int kong;//콩스템프 개수
	CLS C_27 printf("콩 스탬프 갯수를 입력하세요...\n"); scanf_s("%d", &kong);
	if (kong % 5 == 0) {
		printf("콩 스탬프 %d개로 교환할 수 있는 돈은 %d원입니다.\n", kong, kong * 20);
	}
	else
	{
		int asdf = kong / 5;
		int qwer = kong % 5;
		printf("콩 스탬프 %d개로 교환할 수 있는 돈은 %d원입니다.\n남는 콩은 %d개입니다.", kong, asdf * 100, qwer);
	}
}

/*미세먼지 계산1*/			void monji_easy()
{
	int monji;//미세먼지 수치
	int chomi;//초미세 먼지 수치
	CLS printf("현재 미세먼지 수치를 입력하세요 : \n"); scanf_s("%d", &monji);
	printf("현재 초미세먼지 수치를 입력하세요 :  \n"); scanf_s("%d", &chomi);
	if (monji >= 151 || chomi >= 101) {
		C_C0 printf("공기가 심각하게 오염되었습니다!\n마스크를 꼭 써야 합니다.\n");
	}
	else if (monji >= 81 || chomi >= 51) {
		C_E0 printf("위험합니다. 마스크를  써야 합니다.\n");
	}
	else if (monji >= 31 || chomi >= 16) {
		C_27 printf("나쁘지 않습니다.마스크를  안써도 됩니다.\n");
	}
	else {
		C_17 printf("공기가 아주 깨끗합니다. 마스크를 쓸 필요가 없습니다.\n");
	}
}

/*미세먼지 계산2*/			void monji_normal()
{
	int monji;//미세먼지 수치
	int chomi;//초미세 먼지 수치
	CLS printf("현재 미세먼지 수치를 입력하세요 : \n"); scanf_s("%d", &monji);
	printf("현재 초미세먼지 수치를 입력하세요 :  \n"); scanf_s("%d", &chomi);
	if (monji >= 151 || chomi >= 101) {
		C_C0 printf("'매우 나쁨'입니다.\n실외에서의 모든 신체활동을 금지하십시오.\n만약 밖으로 나갈땐 마스크를 꼭 써야 합니다.\n");
	}
	else if (monji >= 81 || chomi >= 51) {
		C_E0 printf("'나쁨'입니다.\n장시간 또는 무리한 실외활동을 자제하십시오.\n마스크를  써야 합니다.\n");
	}
	else if (monji >= 31 || chomi >= 16) {
		C_27 printf("'보통'입니다.\n마스크를  안써도 됩니다.\n");
	}
	else {
		C_17 printf("'좋음'입니다.\n 마스크를 쓸 필요가 없습니다.\n");
	}
}

/*미세먼지 계산3*/			void monji_hard()
{
	int monji;//미세먼지 수치
	int chomi;//초미세 먼지 수치
	CLS printf("현재 미세먼지 수치를 입력하세요(㎍/㎥) : \n"); scanf_s("%d", &monji);
	printf("현재 초미세먼지 수치를 입력하세요(㎍/㎥) :  \n"); scanf_s("%d", &chomi);
	if (monji >= 151 || chomi >= 101) {
		C_C0
			printf("현재 미세먼지 혹은 초미세먼지의 농도가 '매우 나쁨'입니다.\n미세먼지의 농도는%d㎍/㎥, 초미세먼지의 농도는 %d㎍/㎥으로, \n", monji, chomi);
		printf("일반인은 실외에서의 모든 신체활동을 금지하고,\n심장질환 혹은 폐질환이있는 사람,노인,어린이 들은\n장시간 또는 무리한활동을 제한하여야 합니다.\n만약 밖으로 나갈땐 마스크를 꼭 써야 합니다.\n");
	}
	else if (monji >= 81 || chomi >= 51) {
		C_E0
			printf("현재 미세먼지 혹은 초미세먼지의 농도가 '나쁨'입니다.\n미세먼지의 농도는%d㎍/㎥, 초미세먼지의 농도는 %d㎍/㎥으로, \n", monji, chomi);
		printf("일반인은 실외에서의 모든 신체활동을 자제하고,\n심장질환 혹은 폐질환이 있는 사람,노인,어린이 들은 장시간 또는 무리한 활동을 제한하여야 합니다.\n만약 밖으로 나갈땐 마스크를 써야 합니다.\n");
	}
	else if (monji >= 31 || chomi >= 16) {
		C_27
			printf("현재 미세먼지 혹은 초미세먼지의 농도가 '보통'입니다.\n미세먼지의 농도는%d㎍/㎥, 초미세먼지의 농도는 %d㎍/㎥으로, \n", monji, chomi);
		printf("일반인은 실외활동에 문제가 없으나, \n민감군은 장시간 또는 무리한 실외 활동을 자제해야 합니다.\n");
	}
	else {
		C_17
			printf("현재 미세먼지 혹은 초미세먼지의 농도가 '좋음'입니다.\n실미세먼지의 농도는%d㎍/㎥, 초미세먼지의 농도는 %d㎍/㎥으로, \n", monji, chomi);
		printf("일반인과 민감군 모두 실외활동에 문제가 없습니다.\n");
	}
}

/*인형 종류*/					void kind_of_doll()
{
	printf("1. 곰인형 : 잔액을 1000원 추가합니다.\n"); printf("2. 라바 인형 : 잔액을 2000원 추가합니다.\n");
	printf("3. 지방이 인형 : 잔액을 3000원 추가합니다.\n"); printf("4.심슨 인형 : 잔액을 5000원 추가합니다.\n");
	printf("5. 왕 곰인형 : 잔액을 2배로 증가시킵니다.\n"); printf("6. ????? : 잔액을 10배로 증가시킵니다.\n");
	printf("7. 똥 인형 : 잔액을 3000원 감소시킵니다.\n"); printf("8. 사탄의 인형 : 잔액을 0으로 만듭니다.\n");
}

/*인형 종류 Pro*/			void kind_of_doll_pro()
{
	printf("1. 곰인형 : 잔액을 1000원 추가합니다.\n");			printf("2. 라바 인형 : 잔액을 2000원 추가합니다.\n");
	printf("3. 지방이 인형 : 잔액을 3000원 추가합니다.\n");	printf("4.심슨 인형 : 잔액을 5000원 추가합니다.\n");
	printf("5. 왕 곰인형 : 잔액을 2배로 증가시킵니다.\n");	printf("6. ????? : 잔액을 10배로 증가시킵니다.\n");
	printf("7. 똥 인형 : 잔액을 3000원 감소시킵니다.\n");	printf("8. 사탄의 인형 : 잔액을 0으로 만듭니다.\n");
	printf("9. CCTV가리개 : 기계를 흔들어 뽑을수 있게 합니다.\n");
}

/*인형 뽑기 메뉴*/			char doll_menu(const struct doll* pDOLL)
{
	char num;
	MENU_BAR
		printf("\t\t\t\t\t\t\t인형 뽑기\n");
	MENU_BAR
		printf("1. 인형뽑기 게임하기\t\t현재 잔액=%d원\n", pDOLL->money);
	printf("2. 인형종류 확인하기\n");
	printf("3. 인증키 입력\n");
	printf("4. 나가기\n");
	printf("> ");
	scanf_s("%hhd", &num);
	return num;
}

/*인형뽑기 게임오버*/	void doll_gmeovr()
{
	CLS C_0C
		printf("당"); Sleep(200); printf("신"); Sleep(200); printf("은 "); Sleep(200); printf("그"); Sleep(200); printf("렇"); Sleep(200);
	printf("게"); Sleep(200); printf("."); Sleep(200); printf("."); Sleep(200); printf("."); Sleep(200); printf(".\n"); Sleep(2000);
	printf("\'"); Sleep(200); printf("거"); Sleep(200); printf("지"); Sleep(200); printf("\'"); Sleep(200); printf("가 "); Sleep(200);
	printf("되"); Sleep(200); printf("고 "); Sleep(200); printf("말"); Sleep(200); printf("았"); Sleep(200); printf("다"); Sleep(200);
	printf("."); Sleep(200); printf("."); Sleep(200); printf("."); Sleep(200); printf(".\n"); PS PS
}

/*로또 번호 출력*/			void lotto()
{
	int m;//for 반복문
	CLS srand((int)time(NULL));
	for (m = TRUE; m < 7; m++) {
		C_0E printf("%d번 숫자 : %d\n", m, rand() % 45 + TRUE);
	}
	printf("중복되는 숫자가 있다면 다시 실행해 주세요.\n메뉴로 돌아가려면 엔터키를 누르세요.");
}

/*십구단*/						void dan_19()
{
	int i;//19단 반복문
	int l;//19단 식
	CLS
		for (i = TRUE; i <= 19; i++)
		{
			switch (i)
			{
			case 1: system("color 07"); break;
			case 2: system("color 17"); break;
			case 3: system("color 27"); break;
			case 4: system("color 37"); break;
			case 5: system("color 47"); break;
			case 6: system("color 57"); break;
			case 7: system("color 67"); break;
			case 8: system("color 70"); break;
			case 9: system("color 87"); break;
			case 10: system("color 97"); break;
			case 11: system("color a0"); break;
			case 12: system("color b0"); break;
			case 13: system("color c0"); break;
			case 14: system("color d0"); break;
			case 15: C_E0 break;
			case 16: system("color f0"); break;
			case 17: C_07 break;
			case 18: C_17 break;
			case 19: C_27 break;
			}
			printf("%d단 :\n", i);
			for (l = TRUE; l <= 19; l++)
				printf("%2d * X %2d = %3d\n", i, l, i*l);
			printf("Enter키를 누르면 다음 단이 출력 됩니다...");
			ll CLS
		}
	printf("Enter 키를 누르세요...");
}

/*가위바위보 게임 메뉴*/void kababo_menu(struct kababo* pKABA)
{
	C_0F
		CLS
		MENU_BAR
		printf("\t\t\t\t\t    가위바위보 게임(현재 점수=%d)\n", pKABA->jumsu);
	MENU_BAR
		printf("1. 가장 먼저 읽으세요-게임 방법\n");
	printf("2. 가위바위보 게임하기\n");
	printf("3. 인생역전 가위바위보\n");
	printf("4. 메인으로 돌아가기\n");
	MENU_BAR
		printf("선택\\> ");
}

/*가위바위보 도움말*/	void kaba_how()
{
	C_75
		printf("\t\t게임 방법\n");
	printf("게임을 시작하시면 가위, 바위, 보 중에 하나를 선택합니다.\n");
	printf("이기거나 지면 각각 1점을 얻거나 잃습니다.\n");
	printf("인생 역전은 승리시 10점을 얻지만 패배시 점수를 다 잃습니다.\n");
	printf("점수가 -3이 되면 당신의 패배로 게임이 끝납니다.\n");
	printf("점수가 10이 되면 당신이 이깁니다.\n");
	printf("메인으로 돌아가기를 누르시면 메인으로 갑니다.\n");
	printf("준비가 되셨다면 엔터키를 눌러주세요.\n");
	printf("행운을 빕니다!\n");
}

/*가위바위보-가위*/		int kaba_ka(struct kababo* pKABA)
{
	int ina;//가위바위보 랜덤값
	printf("\n당신의 선택은 \"가위\"입니다.\n"); PS PS
		printf("가위,\t"); PS printf("바위,\t"); PS printf("보!\t"); PS printf("\n\n");
	srand((int)time(NULL)); ina = rand() % 2 + TRUE;
	switch (ina) {
	case 1:printf("당신 : 가위\n컴퓨터 : 보"); printf("\n\n당신이 이겼습니다. 1점을 획득하셨습니다."); pKABA->jumsu++; break;
	case 2:printf("당신 : 가위\n컴퓨터 : 가위"); printf("\n\n이런...비겼습니다."); break;
	case 3: printf("당신 : 가위\n컴퓨터 : 보"); printf("\n\n운이 없었나?.... 졌습니다. 1점을 잃었습니다."); pKABA->jumsu--; break;
	}
	return pKABA->jumsu;
}

/*가위바위보-바위*/		int kaba_ba(struct kababo* pKABA)
{
	int ina;//가위바위보 랜덤값
	printf("\n당신의 선택은 \"바위\"입니다.\n"); PS PS
		printf("가위,\t"); PS printf("바위,\t"); PS printf("보!\t"); PS printf("\n\n");
	srand((int)time(NULL)); ina = rand() % 2 + TRUE;
	switch (ina)
	{
	case 1: printf("당신 : 바위\n컴퓨터 : 가위"); printf("\n\n당신이 이겼습니다. 1점을 획득하셨습니다."); pKABA->jumsu++; break;
	case 2: printf("당신 : 바위\n컴퓨터 : 바위"); printf("\n\n이런...비겼습니다."); break;
	case 3: printf("당신 : 바위\n컴퓨터 : 보"); printf("\n\n운이 없었나?.... 졌습니다. 1점을 잃었습니다."); pKABA->jumsu--; break;
	}
	return pKABA->jumsu;
}

/*가위바위보-보*/			int kaba_bo(struct kababo* pKABA)
{
	int ina;//가위바위보 랜덤값
	printf("\n당신의 선택은 \"보\"입니다.\n"); PS PS
		printf("가위,\t"); PS printf("바위,\t"); PS printf("보!\t"); PS printf("\n\n");
	srand((int)time(NULL)); ina = rand() % 2 + 1;
	switch (ina)
	{
	case 1:printf("당신 : 보\n컴퓨터 : 바위"); printf("\n\n당신이 이겼습니다. 1점을 획득하셨습니다."); pKABA->jumsu++; break;
	case 2:printf("당신 : 보\n컴퓨터 : 보"); printf("\n\n이런...비겼습니다."); break;
	case 3: printf("당신 : 보\n컴퓨터 : 가위"); printf("\n\n운이 없었나?.... 졌습니다. 1점을 잃었습니다."); pKABA->jumsu--; break;
	}
	return pKABA->jumsu;
}

/*Overcalc의 발전*/		void dvlp_overcalc()
{
	CLS printf("Overcalc의 발전\n");
	printf("Alpha-년도를 넣으면 그때 몇 살인지 알려주는 프로그램 개발\n");
	printf("Beta-라면 시간 계산기 추가\n");
	printf("FinalBeta-프로그램의 틀 디자인\n");
	printf("v1.0-\"만능 계산기\"라는 이름으로 정식 출시 및 메뉴 1개 추가\n");
	printf("v1.2-메뉴 3개 추가\n");
	printf("v1.25-알려진 보안 문제 수정\n");
	printf("v1.4-인형뽑기 게임 추가\n");
	printf("v1.41-주석 추가\n");
	printf("v1.5-로또 숫자 출력 프로그램 추가\n");
	printf("v1.6-\"만능 프로그램\"으로 이름 변경\n");
	printf("v1.7-색상 추가\n");
	printf("v1.72-버퍼 오버플로우(BOF)및 메모리에 대한 보안 강화\n");
	printf("v1.73-C++소스에서 C로 전환\n");
	printf("v1.8-19단 추가\n");
	printf("v1.9-달력 프로그램 추가\n");
	printf("v1.95-메뉴별로 함수를 독립시킴으로서 프로그램 안정성 강화\n");
	printf("B2.0-BMI측정기 추가\n");
	printf("v2.0-2.0버전 정식 출시 및 숫자 맞히기 게임 추가\n");
	printf("v2.1-만능 프로그램에서 Overcalc로 이름 변경\n");
	printf("Bluebelt(2.2)-명예점수 추가 및 Pro버전 생성\n");
	printf("Firesnake(2.3)-Pro버전의 제품키를 랜덤생성 및 인증되지 않은 버전의 기능 축소\n");
	printf("Zacyan(2.5)-Pro버전의 계산기가 무한 반복되는 현상 수정 및 인형뽑기에서 흔들기 추가\n");
	printf("Rakhakimen(2.8)-Pro버전의 쓸데없는 라면 시간 계산기를 라면 분석기로 업그레이드\n");
	printf("Losapphire(2.9)-Pro버전의 로또번호가 겹치는 현상 수정 및 오름차순으로 정렬\n");
	printf("Losapphire2(2.95)-게임을 끝내고 다시 실행했을때 점수와 돈 등이 그대로인 현상 수정\n");
	printf("Losapphire3(2.99)-자잘한 버그 수정 및 프로그램 최적화\n");
	printf("Optimijade(3.0)-3.0버전 정식 출시 및 소스코드 단축\n");
	printf("Kabaflame(3.1)-가위바위보를 하면 메인으로 돌아가는 현상 수정\n");
	PUS CLS
		printf("Overcalc의 발전\n");
	printf("Emeralsiker(3.15)-구조체 이용으로 소스 코드 더 단축\n");
	printf("Emeralsiker2(3.2)-콩 스탬프 계산기의 기능 강화\n");
	printf("Cobaltimer(3.3)-Pro버전에서 타이머 기능 추가\n");
	ll
}

/*Bmi지수*/					void bmi()
{
	CLS
		float wei = 70.0f;//몸무게
	float hei = 1.77f;//키
	float bmir = 0.0f;//BMI
	printf("몸무게를 입력해 주세요(kg) : "); scanf_s("%f", &wei);
	printf("키를 입력해 주세요(cm)"); scanf_s("%f", &hei);
	bmir = wei / (hei*hei / 10000.f);
	printf("당신의 BMI지수는 %.2f입니다.\n", bmir);
	printf("10~18.4 = 저체중\n18.5~24.9 = 정상\n25~29.9 = 과체중\n30이상 = 비만\n");
}

/*숫자맞추기 게임 방법*/void howto_sutja()
{
	CLS
		printf("이"); P printf("지"); P printf("모"); P printf("드"); P printf("에"); P printf("서"); P printf("는"); P printf(" "); P printf("1"); P
		printf("~"); P printf("9"); P printf("사"); P printf("이"); P printf("의"); P printf(" "); P printf("숫"); P printf("자"); P printf("를"); P
		printf(" "); P printf("맞"); P printf("히"); P printf("면\n"); P printf("이"); P printf("기"); P printf("게"); P printf(" "); P printf("되");
	P printf("며"); P printf(","); P printf(" "); P printf("동"); P printf("메"); P printf("달"); P printf(" "); P printf("하"); P printf("나"); P
		printf("를"); P printf(" 얻"); P printf("습"); P printf("니"); P printf("다"); P printf(".\n"); P printf("숫"); P printf("자"); P printf("를");
	P printf(" "); P printf("맞"); P printf("히"); P printf("는"); P printf("횟"); P printf("수"); P printf("엔"); P printf(" "); P printf("제"); P
		printf("한"); P printf("이"); P printf(" "); P printf("없"); P printf("습"); P printf("니"); P printf("다"); P printf(".\n"); P ll
		printf("노멀모드에서는 11~99의 숫자를 맞히면 이기게 되며,\n");
	printf("은메달 하나를 얻습니다.\n 숫자를 맞히는 횟수는 100번 제한이 있습니다.\n"); ll
		printf("하드모드에서는 111~999의 숫자를 맞히면 이기게 되며,\n");
	printf("금메달 하나를 얻습니다.\n 숫자를 맞히는 횟수는 50번 제한이 있습니다.\n"); ll
		printf("임파서블모드에서는 11111~99999의 숫자를 맞히면 이기게 되며,\n");
	printf("금, 은, 동메달 각각 하나씩을 얻습니다.\n 숫자를 맞히는 횟수는 25번 제한이 있습니다.\n"); ll
}

/*숫자맞추기 게임 메뉴*/void sutja_menu(struct sutja* pSUTJA)
{
	CLS MENU_BAR
		printf("\t\t숫자 맞히기\n");
	printf("금메달 개수 : %d 은메달 개수 : %d 동메달 개수 : %d\n", pSUTJA->kum, pSUTJA->en, pSUTJA->dong);
	MENU_BAR
		printf("1. 플레이 방법\n");
	printf("2. 게임하기-난이도 쉬움(EASY)\n");
	printf("3. 게임하기-난이도 보통(NORMAL)\n");
	printf("4. 게임하기-난이도 어려움(HARD)\n");
	printf("5. 게임하기-클리어 불가능(IMPOSSIBLE)\n");
	printf("6. 금메달을 명예점수로 교환\n");
	printf("7. 은메달을 금메달로 교환\n");
	printf("8. 동메달을 은메달로 교환\n");
	printf("9. 메인으로 가기\n");
	MENU_BAR
		printf(">");
}

/*Pro버전 부팅 화면*/		void boot_pro()
{
	CLS C_5F
		START
		printf("					   	       준비중.\n\n");
	END PS CLS
		START
		printf("					   	       준비중..\n\n");
	END	PS CLS
		START
		printf("					   	       준비중...\n\n");
	END	PS CLS
		START
		printf("					   	       준비중....\n\n");
	END	PS CLS
		START
		printf("					   	       준비중.....\n\n");
	END	PS CLS
		START
		printf("					   	    완료되었습니다\n\n");
	END	PS PS
}

/*NPro 부팅 화면*/		void boot_nonpro()
{
	CLS C_07
		START
		printf("					   	       준비중.\n\n");
	END PS CLS
		START
		printf("					   	       준비중..\n\n");
	END PS CLS
		START
		printf("					   	       준비중...\n\n");
	END PS CLS
		START
		printf("					   	       준비중....\n\n");
	END PS CLS
		START
		printf("					   	       준비중.....\n\n");
	END PS CLS
		START
		printf("					   	    완료되었습니다\n\n");
	END PS PS
}

/*인증 경고*/					void actwarn()
{
	CLS
		printf("		경고\nOvercalc가 정품 인증되지 않았습니다.\n");
	printf("정품인증이 되지 않은 제품을 사용하면 바이러스에 취약해질 수 있습니다.\n");
	PUS CLS
}

/*인증 과정*/					void activation()
{
	CLS printf("현재  1/5완료\n");
	printf("인증키의 효율성을 검증하는 중입니다\n");
	PS CLS; printf("현재 1/5완료\n");
	printf("인증키의 효율성을 검증하는 중입니다.\n");
	PS CLS printf("현재 1/5완료\n");
	printf("인증키의 효율성을 검증하는 중입니다..\n");
	PS CLS printf("현재 1/5완료\n");
	printf("인증키의 효율성을 검증하는 중입니다...\n");
	PS CLS printf("현재 1/5완료\n");
	printf("인증키의 효율성 검증에 성공했습니다.\n");
	PS PS CLS printf("현재 2/5완료\n");
	printf("인증키를 보내는 중입니다\n");
	PS CLS printf("현재 3/5완료\n");
	printf("기능을 추가하는 중입니다\n");
	PS CLS printf("현재 3/5완료\n");
	printf("기능을 추가하는 중입니다.\n");
	PS CLS printf("현재 4/5완료\n");
	printf("거의 완료되었습니다.\n");
	PT CLS printf("완료\n");
	printf("완료되었습니다.\n"); PS
}

/*나이 계산기 Pro*/		void agecalc_pro()
{
	int year1 = FALSE;//현재 년도
	int year2 = FALSE;//두 번째 년도
	int chai = FALSE;//year1과 year2의 차이
	int age1 = FALSE;//나이
	char name[10];//이름
	CLS C_8A printf("당신의 이름을 입력하세요...\n"); scanf_s("%s", &name, sizeof(name));
	printf("현재 년도를 입력하세요...\n"); scanf_s("%d", &year1);
	printf("현재 나이를 입력하세요...\n"); scanf_s("%d", &age1);
	printf("나이를 알고싶은 연도를 입력하세요...\n"); scanf_s("%d", &year2);
	chai = year2 - year1;
	printf("%d년에 %s님의 나이는 %d살 입니다\n", year2, name, chai + age1);
}

/*인형뽑기 메뉴 Pro*/		unsigned char menu_doll_pro(int money)
{
	unsigned char num2;
	MENU_BAR
		printf("\t\t인형 뽑기 Pro\n");
	MENU_BAR
		printf("1. 인형뽑기 게임하기\t\t현재 잔액=%d원\n", money);
	printf("2. 기계 흔들기 (위험!)\n");
	printf("3. 인형종류 확인하기\n");
	printf("4. 인증키 입력\n");
	printf("5. 나가기\n");
	printf("> ");
	scanf_s("%hhd", &num2);
	return num2;
}

/*인형뽑기 게임*/			void doll_game(struct doll* pDOLL)
{
	CLS system("color 2f"); printf("인형을 뽑습니다...1000원이 소비됩니다...\n"); pDOLL->money -= 1000;
	printf("현재 잔액은 %d원입니다.\n", pDOLL->money); jibgae();
	int in;//인형뽑기 랜덤값
	srand((int)time(NULL));
	in = rand() % 35 + 1;//1부터 36까지의 값을 출력
	switch (in)
	{
	case 1:
	case 7: printf("곰인형을 뽑았습니다.\n1000원을 벌었습니다.\n"); pDOLL->money += 1000; PUS break;
	case 2:
	case 10: printf("라바 인형을 뽑았습니다.\n2000원을 벌었습니다.\n"); pDOLL->money += 2000; PUS break;
	case 22:
	case 20: printf("지방이 인형을 뽑았습니다.\n3000원을 벌었습니다.\n"); pDOLL->money += 3000; PUS break;
	case 19: printf("심슨 인형을 뽑았습니다.\n5000원을 벌었습니다.\n"); pDOLL->money += 5000; PUS break;
	case 12: printf("왕 곰인형을 뽑았습니다.\n현재 잔액이 두배로 증가됩니다.\n"); pDOLL->money *= 2; PUS break;
	case 6: printf("축하합니다!\n복권을 뽑았습니다.\n현재 잔액이 10배로 증가합니다!\n"); pDOLL->money *= 10; PUS break;
	case 31: printf("똥 인형을 뽑았습니다.\n3000원을 잃었습니다.\n"); pDOLL->money -= 3000; PUS break;
	case 4:system("color 0c"); printf("사탄의 인형을 뽑았습니다.\n모든 재산을 잃었습니다!!\n"); pDOLL->money = FALSE; PUS break;
	default:printf("이런.....\n아무것도 뽑지 못했습니다......\n"); PUS break;
	}
}

/*계산기*/						void calc_pro()
{
	CALC calc[5] = { Add, Sub, Mul, Div, Mok };  /* 함수 포인터 배열의 초기화 */
	char* msg[5] = /* 포인터 배열 */
	{
		"덧셈 연산 %d + %d = %d 입니다. \nEnter 키를 누르세요.",
		"뺄셈 연산 %d - %d = %d 입니다. \nEnter 키를 누르세요.",
		"곱셈 연산 %d * %d = %d 입니다. \nEnter 키를 누르세요.",
		"나눗셈 연산 %d / %d = %d 입니다. \nEnter 키를 누르세요.",
		"몫 연산 %d %% %d = %d 입니다. \nEnter 키를 누르세요."
	};
	printf("(숫자) +, -, *, /, %% (숫자) 처럼 입력한 후 Enter를 치세요.\n"); printf("종료하시려면 0.\n");

	int while_ = FALSE;

	while (while_<2)
	{
		while_++;
		char string[50] = { FALSE };
		char *token = "+-*/%";
		unsigned int  pos;
		int op;
		fgets(string, sizeof(string), stdin);
		pos = strcspn(string, token);
		if (string == FALSE)
			break;
		else if (pos == strlen(string)) {
			printf("+, -, *, /, %% 중 하나가 없습니다. \n");/*%를 출력하려면 %%*/continue;
		}
		// 연산자 검색
		for (op = FALSE; op<5; op++) {
			if (strchr(string, token[op])) break;  // 연산자 위치를 op가 기억
		}
		string[pos] = '\0';   // 연산자를 기준으로 문자열 분리. 생략 가능
		{   //  지역 변수를 사용하기 위해서 블록({}) 사용
			int a, b;
			a = atoi(string);          // 첫 번째 값
			b = atoi(&string[pos + TRUE]);  //두 번째 값
			PRINT(msg[op], a, b, op, calc);
		}
	}
}

/*인형뽑기 Pro*/			void dollgame_pro(struct doll* pDOLL)
{
	CLS system("color 2f"); printf("인형을 뽑습니다...1000원이 소비됩니다...\n"); pDOLL->money -= 1000;
	printf("현재 잔액은 %d원입니다.\n", pDOLL->money); jibgae();
	int in;//인형뽑기 랜덤값
	srand((int)time(NULL));
	in = rand() % 31 + TRUE;//1부터 36까지의 값을 출력
	switch (in)
	{
	case 1 || 7: printf("곰인형을 뽑았습니다.\n1000원을 벌었습니다.\n"); pDOLL->money += 1000; break;
	case 2:
	case 10: printf("라바 인형을 뽑았습니다.\n2000원을 벌었습니다.\n"); pDOLL->money += 2000; break;
	case 22:
	case 20: printf("지방이 인형을 뽑았습니다.\n3000원을 벌었습니다.\n"); pDOLL->money += 3000; break;
	case 19: printf("심슨 인형을 뽑았습니다.\n5000원을 벌었습니다.\n"); pDOLL->money += 5000; break;
	case 12: printf("왕 곰인형을 뽑았습니다.\n현재 잔액이 두배로 증가됩니다.\n"); pDOLL->money *= 2; break;
	case 6: printf("축하합니다!\n복권을 뽑았습니다.\n현재 잔액이 10배로 증가합니다!\n"); pDOLL->money *= 10; break;
	case 31: printf("똥 인형을 뽑았습니다.\n3000원을 잃었습니다.\n"); pDOLL->money -= 3000; PUS break;
	case 4:system("color 0c"); printf("사탄의 인형을 뽑았습니다.\n모든 재산을 잃었습니다!!\n"); pDOLL->money = FALSE; break;
	case 17: printf("CCTV가리개를 뽑았습니다.\n이제 주인 아줌마 몰래 기계를 흔들 수 있습니다!\n"); pDOLL->cctv += 1; break;
	default:printf("이런.....\n아무것도 뽑지 못했습니다......\n"); break;
	}
}

/*인형뽑기 키인증*/		void doll_activ(struct doll* pDOLL)
{
	int k, j;
	if (pDOLL->keysido == FALSE)
		k = FALSE;
	if (pDOLL->jkeysido == FALSE)
		j = FALSE;
	char key[10];
	printf("인증키를 입력하세요 : "); scanf_s("%s", key, 10);
	if (!strcmp(key, "CO39GJ"))
	{
		(j == FALSE) ?/*if*/ (printf("인증키가 확인되었습니다. 현재 잔액이 늘어납니다.\n"),
			pDOLL->money += 7000, pDOLL->jkeysido = 1) :
			/*else*/printf("아니 이것이 어디서 인증키를 한번 더쓰려고!!!\n");
		PUS;  j++;
	}
	else if (!strcmp(key, "AllenNa"))
	{
		(k == FALSE) ?/*if*/ (printf("인증키가 확인되었습니다. 현재 잔액이 늘어납니다.\n"),
			pDOLL->money += 20000, k++, pDOLL->keysido += 1) :
			/*else*/printf("아니 이것이 어디서 인증키를 한번 더쓰려고!!!\n");
		k++; PUS;
	}
	else {
		printf("얘! 그런 인증키는 없단다..."); PUS
	}
}

/*인형기계 흔들기*/		void doll_shake(struct doll* pDOLL)
{
	if (pDOLL->cctv < TRUE)
	{
		printf("CCTV가리개가 있어야 기계를 흔들 수 있습니다.\n안그러면 감옥가요.\n");
		printf("현재 당신의 CCTV가리개 개수 : %d\n", pDOLL->cctv); PUS
	}
	else
	{
		CLS
			printf("CCTV가리개가 1회용이라....하나 차감됩니다.\n");
		pDOLL->cctv -= 1;
		printf("현재 당신의 CCTV가리개 개수 : %d\n", pDOLL->cctv);
		printf("경고! 기계를 흔들면 경고음이 울리며 상품이 나오지 않을 수 있습니다.\n");
		PUS printf("기계를 흔드는 중입니다....."); PT int in; srand((int)time(NULL)); in = rand() % 41 + TRUE;
		switch (in)
		{
		case 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9:
		case 10: printf("\n\n곰 인형이 나왔습니다.\n1000원을 벌었습니다.\n"); pDOLL->money += 1000; break;
		case 22:
		case 20: printf("\n\n지방이 인형이 나왔습니다.\n3000원을 벌었습니다.\n"); pDOLL->money += 3000; break;
		case 19: printf("\n\n심슨 인형을 뽑았습니다.\n5000원을 벌었습니다.\n"); pDOLL->money += 5000; break;
		case 12: printf("\n\n왕 곰인형과 심슨 인형이 나왔습니다.\n현재 잔액이 5000원 증가되고 두배로 불어납니다.\n");
			pDOLL->money += 5000; pDOLL->money *= 2; break;
		case 17: printf("\n\n대박!\n복권, 왕 곰인형, 심슨, 지방이, 라바, 곰인형 모두가 나왔습니다!\n11000원이 추가되고 현재 잔액이 20배로 증가합니다!\n");
			pDOLL->money += 11000; pDOLL->money *= 20; break;
		default: printf("\n\n\a젠장! 아줌마한테 들켰다!\n모든 돈을 빼앗겼어......\n"); pDOLL->money = FALSE; break;
		}
		PUS
	}
}

/*라면계산기 Pro*/			void ramen_pro()
{
	char k;
	char ramen[10];//라면 이름
	CLS
		while (TRUE)
		{
			printf("라면의 이름을 공백 없이, 매운맛 순한맛 구분없이 입력하세요. 나가실 땐 exit를 입력하세요.\n");
			printf("일반적인 면과 스프의 성분을 알고 싶으면 \"성분\"을 입력하세요.\n");
			printf("용어에 대해 자세히 알고 싶으시면 \"용어사전\"을 입력하세요 : ");
			scanf_s("%s", ramen, sizeof(ramen)); printf("\n");
			if (!strcmp(ramen, "신라면"))
				sinlameon();
			else if (!strcmp(ramen, "성분")) {
				printf("면 : \n");
				printf("소맥분, 팜유, 감자 전분, 변성 전분, 감이유S, 글루텐, 야채풍미액,\n");
				printf("정제염, 씨즈닝엑기스, 면류첨가 알칼리제, 구아검, 산도 조절제, 증점제, 비타민B2,\n");
				printf("올레오레진로즈메리, d-토코페롤 등\n");
				printf("스프 : \n");
				printf("정제염, 볶음짬뽕분, 설탕, L - 글루타민산나트륨(향미증진제), 맛나베이스,\n");
				printf("오징어 조미 분말, 볶음고추분말, 조미분에이, 간장분말, 건파, 전분, 다대기양념분말,\n");
				printf("조미 마늘분, 새우분말, 매운조미고추맛분, 풍미조미료, 생강분말, 파프리카 추출색소,\n");
				printf("고추씨맛기름, 향미증진제, 산도 조절제, 참기름, 건오징어, 건양배추, 새우모양 후레이크,\n");
				printf("계란말이 후레이크, 건미역, 건 다시마 등\n");
			}
			else if (!strcmp(ramen, "용어사전")) {
				printf("용어사전\n");
				printf("소맥분: 밀가루의 한자어.\n");
				printf("정제염: 불순물과 중금속 등을 제거하고 얻어낸 순도 높은 소금.\n");
				printf("팜유: 기름야자의 열매로 얻는 기름.\n");
				printf("글루텐: 보리, 밀 등의 곡류에 존재하는 불용성 단백질.\n");
				printf("야채풍미액: 야채냄새를 나게 하는 물질.\n");
				printf("씨즈닝엑기스: 추출액을 양념으로 구성한 것\n");
				printf("면류첨가알칼리제: 면에 첨가할 수 있는 살충제(...).\n");
				printf("구아검: 식품의 점도를 증가시키고 불이 붙지 않는 안전성을 높이며 식품의 촉감을 높이는 물질.\n");
				printf("산도조절제: 산도를 조절하여 미생물 생장을 억제 시킬수 있는 첨가물.\n");
				printf("올레오레진로즈메리: 로즈마리에서 추출한 향신료.\n");
				printf("d-토코페롤(혼합형): 비타민D.\n");
				printf("L-글루타민산나트륨: 향미증진제. 감칠맛을 내기 위한 화학 조미료.\n");
				printf("풍미조미료: 음식을 만드는 주재료인 식품에 첨가해 음식의 맛을 돋우며 조절하는 물질.\n");
				printf("파프리카추출색소: 파프리카라는 열매로 만든 색소.\n");
				printf("향미증진제: 말 그대로 맛있게 하는 물질.\n");
			}
			else if (!strcmp(ramen, "진라면"))
			{
				while (TRUE)
				{
					CLS
						printf("1.순한맛\n");
					printf("2.매운맛\n");
					printf("선택 > ");
					scanf_s("%hhd", &k);
					switch (k)
					{
					case 1:CLS
						printf("라면의 이름을 공백 없이, 매운맛 순한맛 구분없이 입력하세요. 나가실 땐 exit를 입력하세요.\n");
						printf("일반적인 면과 스프의 성분을 알고 싶으면 \"성분\"을 입력하세요.\n");
						printf("용어에 대해 자세히 알고 싶으시면 \"용어사전\"을 입력하세요 : 진라면\n\n");
						printf("오뚜기 진라면 순한맛\n\n");
						printf("제조원 : 오뚜기\n");
						printf("중량 : 120g\n");
						printf("권장 소비자 가격 : 750원\n");
						printf("\n면 성분 :\n");
						printf("소맥분(미국산, 호주산), 팜유(말레이지아산), 변성전분, 글루텐, 감자전분, 정제소금, 유화유지,\n");
						printf("육수추출농축액, 마늘 시즈닝, 이스트엑기스, 면류 첨가 알칼리제(산도 조절제), 구아검, 비타민B2,\n");
						printf("녹차풍미유, 난각분말\n");
						printf("\n스프 성분 : \n");
						printf("정제소금, 정백당, 참맛사골양념분말, 사골양념분말, 참맛양지분말, 조미육수분말, 비프베이스분말,\n");
						printf("육수추출농축분말, 맛베이스, 간장양념베이스, 간장분말, 감칠맛베이스, 진한감칠맛분, 오뚜기참치간장분말,\n");
						printf("참맛볶음장분말, 쇠고기육수분말, 향미증진제, 복합양념분말, 볶음향미분말, 홍고추분말, 포도당,\n");
						printf("오뚜기비프시즈닝, 육수맛조미분, 조미야채분말, 볶음마늘분말, 고추맛베이스, 후추분말, 마늘농축조미분,\n");
						printf("숙성마늘맛분, 감칠맛조미분, 로스팅조미분말, 유지혼합분말, 전분, 이스트추출물분말, 참맛효모조미분말,\n");
						printf("매운고추양념분말, 영양강화제, 칠리혼합추출물, 조미쇠고기맛후레이크, 건파, 건당근, 건표고버섯,\n");
						printf("건조청경채, 건미역\n");
						PUS CLS
							printf("라면의 이름을 공백 없이, 매운맛 순한맛 구분없이 입력하세요. 나가실 땐 exit를 입력하세요.\n");
						printf("일반적인 면과 스프의 성분을 알고 싶으면 \"성분\"을 입력하세요.\n");
						printf("용어에 대해 자세히 알고 싶으시면 \"용어사전\"을 입력하세요 : 진라면\n\n");
						printf("영양성분\n");
						printf("열량	500 kcal\n");
						printf("탄수화물	79g	24%%\n");
						printf("당류	4g\n");
						printf("단백질	12g	22%%\n");
						printf("지방	15g	29%%\n");
						printf("포화지방	8g	53%%\n");
						printf("트랜스지방	0g	0%%\n");
						printf("콜레스테롤	0mg	0%%\n");
						printf("나트륨	1880mg	94%%\n");
						printf("칼슘	163mg	23%%\n");
						printf("\n조리법\n");
						printf("물 550ml에 건더기 스프를 넣고 물을 끓인 후,\n");
						printf("분말스프를 넣고 면을 넣은 후 4분간 더 끓입니다.\n"); break;
					case 2:CLS
						printf("라면의 이름을 공백 없이, 매운맛 순한맛 구분없이 입력하세요. 나가실 땐 exit를 입력하세요.\n");
						printf("일반적인 면과 스프의 성분을 알고 싶으면 \"성분\"을 입력하세요.\n");
						printf("용어에 대해 자세히 알고 싶으시면 \"용어사전\"을 입력하세요 : 진라면\n\n");
						printf("오뚜기 진라면 매운맛\n\n");
						printf("제조원 : 오뚜기\n");
						printf("중량 : 120g\n");
						printf("권장 소비자 가격 : 750원\n");
						printf("\n면 성분 :\n");
						printf("소맥분(미국산, 호주산), 팜유(말레이지아산), 변성전분, 글루텐, 감자전분, 정제소금, 유화유지,\n");
						printf("육수추출농축액, 마늘 시즈닝, 이스트엑기스, 면류 첨가 알칼리제(산도 조절제), 구아검, 비타민B2,\n");
						printf("녹차풍미유\n");
						printf("\n스프 성분 : \n");
						printf("정제소금, 정백당, 포도당, 복합양념분말, 숙성마늘맛분, 간장분말, 볶음양념분말, 육수맛분말,\n");
						printf("마늘 농축 조미분, 고추맛베이스, 로스팅맛분말, 쇠고기육수분말, 조미육수분말, 참맛양념분말,\n");
						printf("5\'-리보뉴클레오티드이나트륨, 복합양념분말, 칠리맛풍미분, 동골조미분말, 매운맛조미분, 호박산이나트륨,\n");
						printf("발효복합분, 진한감칠맛분, 후추분말, 칠리맛분말, 고춧가루, 감칠맛분말, 참맛버섯양념분말,\n");
						printf("버섯야채조미분말, 오뚜기참치간장분말, 감칠맛베이스, 로스팅조미분말, 맛베이스, 향미증진제,\n");
						printf("볶음마늘분, 육수맛조미분, 육수추출농축분말, 참맛효모조미분말, 숙성양념분말, 칠리추출물, 구아검,\n");
						printf("칠리혼합추출물. 산도조절제, 고추농축소스, 조미쇠고기맛후레이크, 건당근, 건조청경채, 건파,\n");
						printf("건표고 버섯, 건고추 입자\n");
						PUS CLS
							printf("라면의 이름을 공백 없이, 매운맛 순한맛 구분없이 입력하세요. 나가실 땐 exit를 입력하세요.\n");
						printf("일반적인 면과 스프의 성분을 알고 싶으면 \"성분\"을 입력하세요.\n");
						printf("용어에 대해 자세히 알고 싶으시면 \"용어사전\"을 입력하세요 : 진라면\n\n");
						printf("영양성분\n");
						printf("열량	500 kcal\n");
						printf("탄수화물	80g	24%%\n");
						printf("당류	4.6g\n");
						printf("단백질	11g	20%%\n");
						printf("지방	15g	29%%\n");
						printf("포화지방	8g	53%%\n");
						printf("트랜스지방	0g	0%%\n");
						printf("콜레스테롤	0mg	0%%\n");
						printf("나트륨	1860mg	93%%\n");
						printf("칼슘	161mg	23%%\n");
						printf("\n조리법\n");
						printf("물 550ml에 건더기 스프를 넣고 물을 끓인 후,\n");
						printf("분말스프를 넣고 면을 넣은 후 4분간 더 끓입니다.\n"); break;
					default:printf("아니...1~2중에서 선택해달라니까..."); ll continue;
					}
					break;
				}
			}
			else if (!strcmp(ramen, "삼양라면")) {
				printf("삼양식품 삼양라면\n\n");
				printf("제조원 : 삼양식품\n");
				printf("중량 : 120g\n");
				printf("권장 소비자 가격 : 760원\n");
				printf("\n면 성분 :\n");
				printf("소맥분(미국산, 호주산), 팜유(말레이지아산), 정제염(국내산), 변성전분, 미감에스유, 양파엑기스,\n");
				printf("면류 첨가 알칼리제(산도 조절제), 구아검, 비타민B2, 구연산, 녹차풍미유\n");
				printf("\n분말 스프 성분 : \n");
				printf("부대찌개베이스, 정제염, 정백당, 양념간장분, 양지맛무국베이스, 햄맛분말, 식물성간장분말, 베이컨향분말, 맛베이스에스,\n");
				printf("지미맛분말, 김치조미분말, 볶음양념분말, 부대찌개분말, 후추분, 돈육풍미분말, 아미노산혼합제(영양강화제, 향미증진제),\n");
				printf("쇠고기양념분말, 혼합전지분유, 지미강화베이스분말, 향미증진제, 매운조미고추맛분, 호화미분, 팜유, 고추분,\n");
				printf("이스트엑기스분말, 혼합양념분말, 파프리카추출물, 김치찌개풍미분말, 마늘맛오일, 무분\n");
				printf("\n건더기 스프 성분 : \n");
				printf("사과산, 분말카라멜(카라멜색소, 말토덱스트린), 청경채, 실당근, 햄맛후레이크, 건양배추, 건파\n");
				PUS CLS
					printf("라면의 이름을 공백 없이, 매운맛 순한맛 구분없이 입력하세요. 나가실 땐 exit를 입력하세요.\n");
				printf("일반적인 면과 스프의 성분을 알고 싶으면 \"성분\"을 입력하세요.\n");
				printf("용어에 대해 자세히 알고 싶으시면 \"용어사전\"을 입력하세요 : 삼양라면\n\n");
				printf("영양성분\n");
				printf("열량	500 kcal\n");
				printf("탄수화물	79g	24%%\n");
				printf("당류	4g\n");
				printf("단백질	10g	18%%\n");
				printf("지방	16g	31%%\n");
				printf("포화지방	8g	53%%\n");
				printf("트랜스지방	0g	0%%\n");
				printf("콜레스테롤	0mg	0%%\n");
				printf("나트륨	1790mg	90%%\n");
				printf("\n조리법\n");
				printf("끓는물 550ml정도에 면과 스프, 후레이크를 넣고 4분간 더 끓여줍니다.\n");
			}
			else if (!strcmp(ramen, "스낵면")) {
				printf("오뚜기 스낵면\n\n");
				printf("제조원 : 오뚜기\n");
				printf("중량 : 108g\n");
				printf("권장 소비자 가격 : ???원\n");
				printf("\n면 성분 :\n");
				printf("소맥분(미국산, 호주산), 팜유(말레이지아산), 변성전분,감자전분(수입산), 글루텐, 정제소금, 이스트엑기스,\n");
				printf("유화유지, 야채추출물, 면류첨가알칼리제(산도조절제), 난각분말, 비타민B2, 녹차풍미유\n");
				printf("\n스프 성분 : \n");
				printf("쇠고기육수분말, 쇠고기조림분말, 정제소금, 감칠맛베이스, 고춧가루, 표고버섯볶음분말, 참맛미역국분말, 치킨추출농축분말,\n");
				printf("간장분말, 정백당, 간장베이스, 진한감칠맛분, 포도당, 참맛쇠고기양념분말, 로스팅고추분말, 로스팅양파분말, 불활성건조효모,\n");
				printf("향미증진제, 전분, 쇠고기추출물분말, 구운쇠고기분말, 후추분말, 순한간장분말, 볶음마늘분말, 지미맛분말, 조미분말,\n");
				printf("산도조절제, 생강분말, 칠리추출물, 조미쇠고기맛후레이크, 건당근, 건미역\n"); PUS CLS
					printf("라면의 이름을 공백 없이, 매운맛 순한맛 구분없이 입력하세요. 나가실 땐 exit를 입력하세요.\n");
				printf("일반적인 면과 스프의 성분을 알고 싶으면 \"성분\"을 입력하세요.\n");
				printf("용어에 대해 자세히 알고 싶으시면 \"용어사전\"을 입력하세요 : 스낵면\n\n");
				printf("영양성분\n");
				printf("열량	475 kcal\n");
				printf("탄수화물	70g	21%%\n");
				printf("당류	4g\n");
				printf("단백질	10g	18%%\n");
				printf("지방	17g	33%%\n");
				printf("포화지방	9g	60%%\n");
				printf("트랜스지방	0g	0%%\n");
				printf("콜레스테롤	0mg	0%%\n");
				printf("나트륨	1710mg	86%%\n");
				printf("칼슘	71.3mg	10%%\n");
				printf("\n조리법\n");
				printf("끓는물 500ml에 면과 스프를 넣고 2분간 더 끓여줍니다.\n");
			}
			else if (!strcmp(ramen, "짜파게티")) {
				printf("농심 짜파게티\n\n");
				printf("제조원 : 농심\n");
				printf("중량 : 140g\n");
				printf("권장 소비자 가격 : 900원\n");
				printf("\n면 성분 :\n");
				printf("소맥분(미국산, 호주산), 팜유(말레이지아산), 감자전분, 변성전분, 식물성풍미유, 난각칼슘, 정제염,\n");
				printf("면류첨가알칼리제(산도조절제), 혼합제제(산도조절제), 올리고녹차풍미액, 비타민B2\n");
				printf("\n스프 성분 : \n");
				printf("분말짜장, 정백당, 분말카라멜2호, (카라멜색소, 물엿분말), 짜장베이스, 짜장베이스분말, 볶음조미소맥분,\n");
				printf("분말카라멜3호(카라멜색소, 물엿분말, 효소처리스테비아), 야채오일분말, 볶음조미옥수수분, 볶음조미감자분,\n");
				printf("조미짜장분말, 물엿분말, 육수맛조미베이스, 5'-리보뉴클레오티드이나트륨, 정제염, 대두단백, 건양배추, \n");
				printf("튀김감자다이스, 조미건양파, 건당근, 양파풍미유, 짜장풍미유, 혼합올리브유, 양파조미유.\n"); PUS CLS
					printf("라면의 이름을 공백 없이, 매운맛 순한맛 구분없이 입력하세요. 나가실 땐 exit를 입력하세요.\n");
				printf("일반적인 면과 스프의 성분을 알고 싶으면 \"성분\"을 입력하세요.\n");
				printf("용어에 대해 자세히 알고 싶으시면 \"용어사전\"을 입력하세요 : 짜파게티\n\n");
				printf("영양성분\n");
				printf("열량	610 kcal\n");
				printf("탄수화물	97g	29%%\n");
				printf("당류	6g\n");
				printf("단백질	11g	20%%\n");
				printf("지방	20g	39%%\n");
				printf("포화지방	8g	53%%\n");
				printf("트랜스지방	0g	0%%\n");
				printf("콜레스테롤	0mg	0%%\n");
				printf("나트륨	1180mg	59%%\n");
				printf("칼슘	164mg	23%%\n");
				printf("\n조리법\n");
				printf("물 600ml정도를 끓인 후 면과 후레이크를 넣고 5분간 더 끓입니다.\n");
				printf("물 8스푼정도만 남기고 따라버린후 과립스프와 올리브조미유를 잘 비벼드시면 됩니다.\n");
			}
			else if (!strcmp(ramen, "exit")) {
				break;
			}
			else {
				printf("잘못 입력하셨거나 이 라면은 등록되지 않았습니다.\n");
			}
			ll CLS
		}
}

/*로또번호출력 Pro*/		void lotto_pro()
{
	int lot[6];
	int k, i;
	int tmp;
	int count = FALSE;
	int ran;
	int flag = TRUE;
	srand((int)time(NULL));
	while (count != 6) {
		flag = TRUE;
		while (flag) {
			ran = rand() % 45 + TRUE;
			flag = FALSE;
			for (k = FALSE; k<count; k++) {
				if (ran == lot[k]) {
					flag = TRUE; break;
				}
			}
		}
		lot[count] = ran; count++;
	}
	for (i = FALSE; i < 5; i++) {
		for (int j = i + TRUE; j<6; j++)
			if (lot[i] > lot[j]) {
				tmp = lot[i]; lot[i] = lot[j]; lot[j] = tmp;
			}
	}
	for (i = FALSE; i<6; i++) {
		printf("%d번 번호 : %d\n", i + TRUE, lot[i]);
	}
}

/*인형뽑기 집게*/			void jibgae()
{
	PT printf("\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n");
	printf("    =========\n    ||      ||\n    ||      ||\n"); P P P P P P CLS
		printf("\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n");
	printf("    =========\n    ||      ||\n    ||      ||\n"); P P P P P P CLS
		printf("\t||\n\t||\n\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n");
	printf("    =========\n    ||      ||\n    ||      ||\n"); P P P P P P CLS
		printf("\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n");
	printf("\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P

		//집게바가 내려감
		PS PS//2초 쉼
		CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P CLS
		printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("\t||\n"); printf("\t||\n"); printf("\t||\n"); printf("\t||\n");
	printf("    =========\n"); printf("    ||      ||\n"); printf("    ||      ||\n"); P P P P P P
}

/*타이머*/						void timer()
{
	int num;
	int num2;
	printf("분을 입력하세요 : ");
	scanf_s("%d", &num);
	num *= 60;
	printf("초를 입력하세요 : ");
	scanf_s("%d", &num2);
	num += num2;
	while (1)
	{
		system("cls");
		num -= 1;

		if (num <= 0)
			break;

		printf("남은 시간 = %d분 %d초", num / 60, num % 60);
		Sleep(1000);
	}
	system("cls");
	printf("\a"); printf("시간이 다 되었습니다."); Sleep(700); system("cls");
	printf("\a"); printf("시간이 다 되었습니다."); Sleep(700); system("cls"); printf("\a"); printf("시간이 다 되었습니다.\n"); Sleep(700);
	system("pause");
}

/*숫자맞추기-쉬움*/		void sutja_easy(struct sutja* pSUTJA)
{
	srand((unsigned)time(NULL));
	pSUTJA->nansu = rand() % 8 + TRUE; CLS
		for (pSUTJA->sido = TRUE; pSUTJA->sido < 9999; pSUTJA->sido++)
		{
			printf("1~9중 맞을 것 같은 숫자를 입력하세요 : ");
			scanf_s("%d", &pSUTJA->answ);
			if (pSUTJA->answ == pSUTJA->nansu)
			{
				(pSUTJA->sido == TRUE) ? printf("한번에 맞히다니! 사람이야?\n어쨌든 동메달 한개를 획득하셨습니다!\n") :
					printf("%d번의 시도 끝에 정답을 맞혔습니다! \n동메달 한개를 획득하셨습니다.\n", pSUTJA->sido);
				pSUTJA->dong++, ll break;
			}
			else if (pSUTJA->answ > pSUTJA->nansu)
				printf("%d보다 작은 수입니다.\n", pSUTJA->answ);
			else if (pSUTJA->answ < pSUTJA->nansu)
				printf("%d보다 큰 수입니다.\n", pSUTJA->answ);
		}
}

/*숫자맞추기-보통*/		void sutja_normal(struct sutja* pSUTJA)
{
	srand((unsigned)time(NULL));
	pSUTJA->nansu = rand() % 88 + 11; CLS
		for (pSUTJA->sido = TRUE; pSUTJA->sido < 100; pSUTJA->sido++) {
			printf("11~99중 맞을 것 같은 숫자를 입력하세요 : ");
			scanf_s("%d", &pSUTJA->answ);
			if (pSUTJA->answ == pSUTJA->nansu) {
				(pSUTJA->sido == TRUE) ? printf("한번에 맞히다니! 사람이야?\n어쨌든 은메달 한개를 획득하셨습니다!\n") :
					printf("%d번의 시도 끝에 정답을 맞혔습니다! \n은메달 한개를 획득하셨습니다.\n", pSUTJA->sido);
				pSUTJA->en++, ll break;
			}
			else if (pSUTJA->answ > pSUTJA->nansu)
				printf("%d보다 작은 수입니다.\n", pSUTJA->answ);
			else if (pSUTJA->answ < pSUTJA->nansu)
				printf("%d보다 큰 수입니다.\n", pSUTJA->answ);
		}
	if (pSUTJA->sido >= 100) {
		printf("이런...기회를 다 썼습니다.\n"); PUS
	}
}

/*숫자맞추기-어려움*/	void sutja_hard(struct sutja* pSUTJA)
{
	srand((unsigned)time(NULL));
	pSUTJA->nansu = rand() % 888 + 111;
	CLS
		for (pSUTJA->sido = FALSE; pSUTJA->sido < 50; pSUTJA->sido++)
		{
			printf("111~999중 맞을 것 같은 숫자를 입력하세요 : ");
			scanf_s("%d", &pSUTJA->answ);
			if (pSUTJA->answ == pSUTJA->nansu)
			{
				(pSUTJA->sido == TRUE) ? printf("한번에 맞히다니! 사람이야?\n어쨌든 금메달 한개를 획득하셨습니다!\n") :
					printf("%d번의 시도 끝에 정답을 맞혔습니다! \n금메달 1개를 획득하셨습니다.\n", pSUTJA->sido);
				pSUTJA->kum++, ll break;
			}
			else if (pSUTJA->answ > pSUTJA->nansu)
				printf("%d보다 작은 수입니다.\n", pSUTJA->answ);
			else if (pSUTJA->answ < pSUTJA->nansu)
				printf("%d보다 큰 수입니다.\n", pSUTJA->answ);
		}
	if (pSUTJA->sido >= 50)
	{
		printf("이런...기회를 다 썼습니다.\n"); PUS
	}
}

/*신라면*/						void sinlameon()
{
	printf("농심 신라면\n\n");
	printf("제조원 : 농심\n");
	printf("중량 : 120g\n");
	printf("권장 소비자 가격 : 780원\n");
	printf("면 성분 :\n");
	printf("소맥분(미국산, 호주산), 팜유(말레이지아산), 감자전분, 변성전분, 난각칼슘, 정제염, 야채조미추출물,\n");
	printf("면류 첨가 알칼리제(산도 조절제), 혼합제재(산도 조절제), 올리고 녹차 풍미액, 비타민B2\n");
	printf("스프 성분 : \n");
	printf("정제염, 소고기맛 베이스, 정백당, 육수맛 조미 베이스, 볶음 양념분, 조미 소고기 분말, 조미아미노산간장분말,\n");
	printf("마늘 발효 조미분, 분말된장, 마늘베이스, 간장분말, 조미양념분, 조미홍고추 분말, 후추가루,\n");
	printf("5\'-리보뉴클레오티드이나트륨, 복합양념분말, 칠리맛풍미분, 동골조미분말, 매운맛조미분, 호박산이나트륨,\n");
	printf("후추풍미분말, 우골마늘조미분, 조미효모분말, 양파 풍미분, 발효표고조미분, 분말카라멜(카라멜색소, 물엿분말),\n");
	printf("생강추출분말, 표고버섯분말, 이스트조미분, 건파, 건청경채, 건표고버섯, 건당근, 건고추\n");
	PUS CLS
		printf("라면의 이름을 공백 없이, 매운맛 순한맛 구분없이 입력하세요. 나가실 땐 exit를 입력하세요.\n");
	printf("일반적인 면과 스프의 성분을 알고 싶으면 \"성분\"을 입력하세요.\n");
	printf("용어에 대해 자세히 알고 싶으시면 \"용어사전\"을 입력하세요 : 신라면\n\n");
	printf("영양성분\n");
	printf("열량	505 kcal\n");
	printf("탄수화물	80g	24%%\n");
	printf("당류	4g\n");
	printf("단백질	10g	18%%\n");
	printf("지방	16g	31%%\n");
	printf("포화지방	8g	53%%\n");
	printf("트랜스지방	0g	0%%\n");
	printf("콜레스테롤	0mg	0%%\n");
	printf("나트륨	1790mg	90%%\n");
	printf("칼슘	144mg	21%%\n");
	printf("\n조리법\n");
	printf("물 550ml를 끓인 후, 면과 분말스프, 후레이크를 같이 넣고\n");
	printf("4분 30초간 더 끓이면 얼큰한 소고기 국물 맛의 신라면이 됩니다.\n");
}