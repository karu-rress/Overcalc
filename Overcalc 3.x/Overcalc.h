#pragma once

#include <stdio.h>			//printf(), scanf_s(), puts(), getchar()
#include <stdlib.h>			//exit(), system(), rand(), malloc()
#include <conio.h>			//_getch()
#include <string.h>			//strcmp(), strcpy(), strlen(), strcat() 등
#include <time.h>			//time()
#include <windows.h>		//Sleep()

/*숫자 계열 디파인*/
	#define TRUE 1			//숫자 계열 디파인
	#define FALSE 0		//숫자 계열 디파인	
		
/*문자 계열 디파인*/
	#define MENU_BAR	printf("========================================================================================================================\n");//문자 계열 디파인
	#define PRO_BAR 		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);	//문자 계열 디파인
	#define END				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);		//문자 계열 디파인
	#define MENU_TITLE	printf("                      			  Overcalc BASIC Enterare				    	    by Allen Na\n");	//문자 계열 디파인
	#define PRO_TITLE	printf("                      				Overcalc PRO Enterare					   by Allen Na\n");	//문자 계열 디파인
	#define PRE_TITLE		printf("                      			Overcalc PREMIUM Enterare					   by Allen Na\n");	//문자 계열 디파인
	#define ENT_TITLE	printf("                      		  Overcalc ENTERPRISE Enterare					   by Allen Na\n");	//문자 계열 디파인
	#define EASTER_TIT	printf("                      				Easter Egg Enterare				    	    by Allen Na\n");	//문자 계열 디파인
	#define HONOR		printf("													명예 점수 : %d\n", honor);									//문자 계열 디파인
	#define PHONOR		printf("													명예 점수 : %d\n", *phonor);									//문자 계열 디파인

	#define START			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("      %c%c%c        %c        %c    %c%c%c%c%c    %c%c%c%c        %c%c%c       %c        %c             %c%c%c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("    %c      %c      %c        %c    %c            %c      %c    %c           %c  %c      %c           %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("  %c          %c    %c        %c    %c            %c      %c   %c           %c    %c     %c          %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("  %c          %c    %c        %c    %c%c%c%c%c    %c%c%c%c     %c          %c%c%c%c%c    %c          %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("  %c          %c     %c      %c     %c            %c      %c   %c          %c      %c    %c          %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("    %c      %c        %c    %c      %c            %c      %c    %c         %c      %c    %c           %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("      %c%c%c            %c%c        %c%c%c%c%c    %c      %c      %c%c%c   %c      %c    %c%c%c%c%c     %c%c%c \n\n\n\n\n\n\n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("					Beyond the limits of a calculator.\n"); \
		printf("						Beyond your limits.\n\n\n\n\n"); \
		printf("					   	     -Enterare-\n\n\n"); \
		printf("					   	    2017 Allen Na\n\n\n");

	#define	 EASTER		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("      %c%c%c        %c        %c    %c%c%c%c%c    %c%c%c%c        %c%c%c       %c        %c             %c%c%c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("    %c      %c      %c        %c    %c            %c      %c    %c           %c  %c      %c           %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("  %c          %c    %c        %c    %c            %c      %c   %c           %c    %c     %c          %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("  %c          %c    %c        %c    %c%c%c%c%c    %c%c%c%c     %c          %c%c%c%c%c    %c          %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("  %c          %c     %c      %c     %c            %c      %c   %c          %c      %c    %c          %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("    %c      %c        %c    %c      %c            %c      %c    %c         %c      %c    %c           %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("      %c%c%c            %c%c        %c%c%c%c%c    %c      %c      %c%c%c   %c      %c    %c%c%c%c%c     %c%c%c \n\n\n\n\n\n\n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("					Beyond the limits of a calculator.\n"); \
		printf("						Beyond your limits.\n\n\n\n\n"); \
		printf("					       E A S T E R	E G G\n\n\n"); \
		printf("					   	    2017 Allen Na\n\n\n");

#define	 MKMNU		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("      %c%c%c        %c        %c    %c%c%c%c%c    %c%c%c%c        %c%c%c       %c        %c             %c%c%c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("    %c      %c      %c        %c    %c            %c      %c    %c           %c  %c      %c           %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("  %c          %c    %c        %c    %c            %c      %c   %c           %c    %c     %c          %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("  %c          %c    %c        %c    %c%c%c%c%c    %c%c%c%c     %c          %c%c%c%c%c    %c          %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("  %c          %c     %c      %c     %c            %c      %c   %c          %c      %c    %c          %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("    %c      %c        %c    %c      %c            %c      %c    %c         %c      %c    %c           %c \n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("      %c%c%c            %c%c        %c%c%c%c%c    %c      %c      %c%c%c   %c      %c    %c%c%c%c%c     %c%c%c \n\n\n\n\n\n\n", 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128); \
		printf("					Beyond the limits of a calculator.\n"); \
		printf("						Beyond your limits.\n\n\n\n\n"); \
		printf("					       숨겨진 메뉴를 만드는중....\n\n\n"); \
		printf("					   	    2017 Allen Na\n\n\n");

/*Sleep 디파인*/
	#define PS	Sleep(1000);			//Sleep 디파인
	#define PT	Sleep(3000);			//Sleep 디파인
	#define P		Sleep(50);				//Sleep 디파인

/*일시정지 계열 디파인*/
	#define PUS							system("pause");		//일시정지 계열 디파인
	#define ll  /*소문자 엘 두개*/	_getch();					//일시정지 계열 디파인

/*기타 디파인*/
	#define CLS							system("cls");			//화면 지우기 디파인
	#define C_07						system("color 07");	//검정-하얀색 기본 컬러 디파인
	#define C_0C						system("color 0c");	//검정-밝은 빨간색 컬러 디파인
	#define C_0F							system("color 0f");		//검정-밝은 하얀색 컬러 디파인
	#define C_3F							system("color 3f");		//하늘색-밝은 흰색 컬러 디파인
	#define C_60						system("color 60");	//탁한 노랑-검정색 컬러 디파인
	#define C_5F							system("color 5f");		//자주-밝은 흰색의 컬러 디파인
	#define C_8A						system("color 8a");	//회색-형광 녹색의 컬러 디파인
	#define C_A3						system("color a3");	//형광 녹색-남색의 컬러 디파인
	#define C_27						system("color 27");	//진한 녹색-흰색의 컬러 디파인
	#define C_0E							system("color 0e");	//검정-밝은 노란색 컬러 디파인
	#define C_75						system("color 75");	//회색-진한 보라색 컬러 디파인

	/*미세먼지 색상*/
		#define C_C0					system("color c0");	//빨강-검정의 "매우나쁨" 디파인
		#define C_E0						system("color e0");	//노랑-검정의 "나쁨" 디파인
	 //#define C_27						system("color 27"); 은 위에 이미 정의 되어 있으므로 생략		
		#define C_17					system("color 17");	//파랑-흰색의 "좋음" 디파인

	/*이스터 에그 색상*/
		#define GREEN					system("color 0a");	//검은 바탕에 밝은 녹색 디파인
		#define PINK					system("color 0d");	//검은 바탕에 밝은 분홍 디파인
		#define WHITE					system("color 0f");		//검은 바탕에 밝은 흰색 디파인
		#define YELLOW				system("color 0e");	//검은 바탕에 밝은 노랑 디파인
		#define BLUE					system("color 0b");	//검은 바탕에 밝은 파랑 디파인

/*typedef*/
	typedef    int(*CALC)(int, int);   /* CALC형을 정의 */

/*함수 모음*/

	/*예제 계열*/

			//달력 계열
				int get_year(void);	
				int get_day_code(int);
				int get_leap_year(int);
				void print_calendar(int, int, int);	
				void PRINT(const char* msg, int a, int b, int op, CALC *calc);	

			//계산기 계열
				int  Add(int a, int b)	{ return a + b; }		//더하기(+)
				int  Sub(int a, int b)	{ return a - b; }		//빼기(-)
				int  Mul(int a, int b)	{ return a * b; }		//곱하기(*)
				int  Div(int a, int b)	{ return a / b; }		//나누기(/)
				int  Mok(int a, int b)	{ return a % b; }		//몫(%)

	/*기본 계열*/
		void start_overcalc(int*);
		void age_calc(/*나이*/);			void agecalc_pro(/*나이P*/);
		void ramen_calc(/*라면*/);		void ramen_pro(/*라면P*/);		void sinlameon(/*신라면*/);
		void kong_calc(/*콩*/);			void calc_pro(/*계산기*/);
		void bmi(/*BMI*/);				void timer(/*타이머*/);
		void dvlp_overcalc(/*발전*/);	void v_overcalc(/*버전*/);
		void lotto(/*로또*/);				void lotto_pro(/*로또*/);
		void dan_19(/*19단*/);			void Easter_Egg(int*);
		void Easter_EGG(int*);			void EASTER_EGG(int*);

	/*미세먼지 계열*/
		void monji_easy(/*쉬움*/);
		void monji_normal(/*보통*/);
		void monji_hard(/*어려움*/);

	/*숫자맞추기 게임 계열*/
		void sutja_menu(struct sutja*);		//숫자 메뉴
		void howto_sutja();						//게임 방법
		void sutja_easy(struct sutja*);		//쉬움
		void sutja_normal(struct sutja*);	//보통
		void sutja_hard(struct sutja*);		//어려움

	/*인형뽑기 게임 계열*/
		char doll_menu(const struct doll*);	unsigned char menu_doll_pro(int);			//메뉴
		void doll_game(struct doll*);						void dollgame_pro(struct doll*);		//인형뽑기 게임
		void kind_of_doll();									void kind_of_doll_pro();						//인형 종류
		void doll_gmeovr();									void doll_shake(struct doll*);				
		void doll_activ(struct doll*);																				//인증키
		void jibgae();																										//집게
 
	/*가위바위보 게임 계열*/
		void kababo_menu(struct kababo*);			//메뉴
		void kaba_how();										//방법
		int kaba_ka(struct kababo*);						//가위
		int kaba_ba(struct kababo*);						//바위
		int kaba_bo(struct kababo*);						//보

	/*Pro버전의 특수 기능*/
		void boot_pro();					//프로버전 부팅
		void boot_nonpro();				//인증 안된 프로버전 부팅
		void actwarn();						//인증 경고
		void activation();					//인증

	/*이스터 에그*/
		void help_easter();						//이스터 에그 경로 도움말

/*숫자맞추기 게임 구조체*/		struct sutja
{
	int nansu, answ;		//숫자 맞추기 정답 및 입력 값
	int sido;					//숫자맞추기 시도 횟수
	int kum, en, dong;	//숫자 맞추기 메달 개수
	int other;					//메달-명예점수 나머지
};

/*가위바위보 게임 구조체*/		struct kababo
{
	int ina;				//컴퓨터와의 가위바위보 랜덤값
	int jumsu;			//가위바위보의 점수
	char kaba[10];	//가위바위보
};

/*인형뽑기 게임 구조체*/		struct doll
{
	int cctv;						//cctv가리개 갯수
	int keysido, jkeysido;		//인증키 시도 횟수
	int money;					//인형뽑기 잔액	
};

int easter_egg = 0;			//이스터 에그 부팅 화면 반복 횟수