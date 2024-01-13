#pragma once
#include "OverStd.h"

typedef const char* M;

class CBasicStd : public COverStd
{
	friend class CBDoll;
	// 메뉴의 최소값을 담고 있는 상수형 인스턴스
	const int Min;

	// 메뉴의 최대값을 담고 있는 상수형 인스턴스
	const int Max;

	// 메뉴를 처음 출력하니?
	int is_first_print;

	// 이스터에그 접근가능 여부를 담고있는 인스턴스. 
	// 다시말해 BM의 이스터버전
	int easteregg;

	unsigned int now_year;							// 나이계산기의 현재 년도 입력	
	unsigned int future_year;						// 나이계산기의 미래 년도 입력
	unsigned int age;										// 나이계산기의 나이

	int lotto[6];

	//easter egg
	int EE;
	int num;
	int menu[5] = { 0 };
	int mk;
	int cho;
	char choo;
	char okay;

	float wei;													// 몸무게
	float hei;													// 키
	float bmir;												// BMI

protected:

	// 메뉴를 읽을때 스캔코드 값을 읽는 인스턴스로, 
	// 상속된 B_HelpError클래스에서도 사용할 수 있음
	int input;

	// Basic 버전의 메뉴를 담고있는 인스턴스
	// 도움말에서도 사용 하여야 하기 때문에, 
	// 상속된 B_HelpError클래스에서도 사용할 수 있음
	int BM;

public:

	static M menu1, menu2, menu3, menu4, menu5, menu6, menu7, menu8, menu9,
		menu10, menu11, help1, help2, help3, help4, error1, error2, error3, error4, error5;

	CBasicStd();
	~CBasicStd();

	// Basic 버전의 메뉴를 출력하는 메서드
	int PrintMenu();

	// Basic 버전의 메뉴를 선택할 수 있게 하는 메서드
	int SelectMenu(int & rmenu);

	// Baisc의 1번 기능. 나이계산기
	size_t age_calc();

	// 로또 번호를 출력하는 메서드
	int print_lotto();

	// 19단을 출력하는 메서드
	int Print_19dan();

	// BMI지수를 계산하는 메서드
	void BMI();


	// Pro버전으로 업그레이드 시키는 메서드
	int To_Pro();
};

