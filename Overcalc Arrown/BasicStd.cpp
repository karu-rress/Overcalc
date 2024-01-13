#include "stdafx.h"
#include "BasicStd.h"

M	CBasicStd::menu1("나의 나이는 0000년에 몇 살일까?                                                                                         \n");
M	CBasicStd::menu2("인형 뽑기 게임하기                                                                                                      \n");
M	CBasicStd::menu3("로또 번호 출력                                                                                                          \n");
M	CBasicStd::menu4("19단                                                                                                                    \n");
M	CBasicStd::menu5("가위바위보 게임                                                                                                         \n");
M	CBasicStd::menu6("달력 출력                                                                                                               \n");
M	CBasicStd::menu7("BMI 계산하기                                                                                                            \n");
M	CBasicStd::menu8("숫자 맞히기                                                                                                             \n");
M	CBasicStd::menu9("Overcalc의 역사와 발전                                                                                                  \n");
M	CBasicStd::menu10("Overcalc의 에디션                                                                                                       \n");
M	CBasicStd::menu11("Pro버전으로 업그레이드                                                                                                  \n");
M CBasicStd::help1("이 프로그램은 무엇인가요?                                                                                               \n");
M CBasicStd::help2("사용 방법                                                                                                               \n");
M CBasicStd::help3("문제 해결                                                                                                               \n");
M CBasicStd::help4("도움말 나가기                                                                                                           \n");
M CBasicStd::error1("커서만 뜨고 아무것도 뜨지 않아요.                                                                                       \n");
M CBasicStd::error2("창이 계속 깜빡이고 키보드가 말을 듣지 않아요.                                                                           \n");
M CBasicStd::error3("평소와 다른 말이 뜨고 키 입력이 되지 않아요.                                                                            \n");
M CBasicStd::error4("경고창이 뜨고 프로그램이 멈춰요.                                                                                        \n");
M CBasicStd::error5("도움말로 돌아가기                                                                                                       \n");

CBasicStd::CBasicStd() : Min(1), Max(11), BM(1), is_first_print(0), lotto{ 0, }
{
}


CBasicStd::~CBasicStd()
{
}



// Basic 버전의 메뉴를 출력하는 메서드
int CBasicStd::PrintMenu()
{
	(this->is_first_print == 0) ? cls(), ++is_first_print : COverStd::cur(0, 0); C_3F;
	std::wcout << BP_BAR << endl;
	MENU_TITLE; HONOR; std::wcout << BP_BAR << endl;
	switch (this->BM)
	{
	case 1: COverStd::color(3, 15); std::cout << menu1;
		COverStd::color(15, 3);
		std::cout << menu2 << menu3 << menu4 << menu5 << menu6 << menu7 << menu8 << menu9
			<< menu10 << menu11;
		B_UNMENU;

	case 2: color(15, 3); std::cout << menu1;
		color(3, 15); std::cout << menu2;
		color(15, 3);
		std::cout << menu3 << menu4 << menu5 << menu6 << menu7 << menu8 << menu9
			<< menu10 << menu11;
		B_UNMENU;

	case 3: color(15, 3);
		std::cout << menu1 << menu2;
		color(3, 15);
		std::cout << menu3;
		color(15, 3);
		std::cout << menu4 << menu5 << menu6 << menu7 << menu8 << menu9
			<< menu10 << menu11;
		B_UNMENU;

	case 4:color(15, 3);
		std::cout << menu1 << menu2 << menu3;
		color(3, 15);
		std::cout << menu4;
		color(15, 3);
		std::cout << menu5 << menu6 << menu7 << menu8 << menu9
			<< menu10 << menu11;
		B_UNMENU;

	case 5: color(15, 3);
		std::cout << menu1 << menu2 << menu3 << menu4;
		color(3, 15);
		std::cout << menu5;
		color(15, 3);
		std::cout << menu6 << menu7 << menu8 << menu9
			<< menu10 << menu11;
		B_UNMENU;

	case 6: color(15, 3);
		std::cout << menu1 << menu2 << menu3 << menu4 << menu5;
		color(3, 15);
		std::cout << menu6;
		color(15, 3);
		std::cout << menu7 << menu8 << menu9
			<< menu10 << menu11;
		B_UNMENU;

	case 7: color(15, 3);
		std::cout << menu1 << menu2 << menu3 << menu4 << menu5 << menu6;
		color(3, 15);
		std::cout << menu7;
		color(15, 3);
		std::cout << menu8 << menu9 << menu10 << menu11;
		B_UNMENU;

	case 8: color(15, 3);
		std::cout << menu1 << menu2 << menu3 << menu4 << menu5 << menu6 << menu7;
		color(3, 15);
		std::cout << menu8;
		color(15, 3);
		std::cout << menu9 << menu10 << menu11;
		B_UNMENU;

	case 9: color(15, 3);
		std::cout << menu1 << menu2 << menu3 << menu4 << menu5 << menu6 << menu7 << menu8;
		color(3, 15);
		std::cout << menu9;
		color(15, 3);
		std::cout << menu10 << menu11;
		B_UNMENU;

	case 10: color(15, 3);
		std::cout << menu1 << menu2 << menu3 << menu4 << menu5 << menu6 << menu7 << menu8 << menu9;
		color(3, 15);
		std::cout << menu10;
		color(15, 3);
		std::cout << menu11;
		B_UNMENU;

	case 11: color(15, 3);
		std::cout << menu1 << menu2 << menu3 << menu4 << menu5 << menu6 << menu7
			<< menu8 << menu9 << menu10;
		color(3, 15);
		std::cout << menu11;
		color(15, 3);
		B_UNMENU;
	}
	return 1;
}


// Basic 버전의 메뉴를 선택할 수 있게 하는 메서드, 메뉴는 정수, 
int CBasicStd::SelectMenu(int &rmenu)
{
	input = _getch();

	if (input == 13)													//엔터키를 눌렀다면
	{
		if (easteregg == 2)											//잠만. 이스터에그로 접근한다면
			return 0;														//우선 0을 반환하고

		else																	//아니라면
		{
			rmenu = BM;
			if (rmenu == BM)			
				return 1;
			
			else		
				return EOF;
			
		}
	}

	else if (input == 27) { rmenu = ESCAPE; return ESCAPE; }						//ESC는 ESCAPE을 리턴한다. 종료하라는 뜻

	else if (input == 224 || input == 0)
	{
		input = _getch();

		switch (input)
		{
		case 59: return 0xf1;										//f1키를 눌러서 f1리턴(...)
		case 72: if (BM == Min) { std::cout << arm; break; } --BM; break;
		case 75: if (easteregg == -1) { std::cout << arm; break; }--easteregg; break;
		case 77: if (easteregg == 2) { std::cout << arm; break; }++easteregg; break;
		case 80: if (BM == Max) { std::cout << arm; break; } ++BM; break;
		default: break;
		}
	}
	else { return EOF; }
	return 0;
}

// Baisc의 1번 기능. 나이계산기
size_t CBasicStd::age_calc()
{
	String name;
	short a = 0;
	cls(); C_8A;
	_tcout << STR("이름을 입력 하세요...") << endl;
	_tcin.clear();

	while (true)
	{
		getline(_tcin, name, L'\n');
		WriteTestLog("나이계산기", name + L"입력");
		for (auto &word : COverStd::badwords)
		{
			if (name.find(word) != string::npos)
			{
				_tcout << STR("나쁜말은 쓰지 맙시다!!!") << endl;
				name.clear();
				break;
			}
			else
			{
				a = 1; break;
			}
		}
		if (a == 1) { break; }
	}

	// 이름의 길이를 저장
	size_t nameLength = name.length();

	_tcout << STR("현재 년도를 입력하세요...") << endl;
	_tcin >> now_year;

	while (!_tcin)
	{
		_tcout << STR("숫자로 입력해 주세요.") << endl;
		_tcin.clear();
		_tcin.ignore(INT64_MAX, L'\n');
		cls(4);
		_tcin >> now_year; continue;
	}

	WriteTestLog<string, unsigned int>("나이계산기 년도", now_year);

	_tcout << STR("현재 나이를 입력하세요...") << endl;
	_tcin >> age;

	while (!_tcin)
	{
		_tcout << STR("숫자로 입력해 주세요.") << endl;
		_tcin.clear();
		_tcin.ignore(INT64_MAX, L'\n');
		cls(6);
		_tcin >> age; continue;
	}



	_tcout << STR("나이를 알고싶은 연도를 입력하세요...") << endl;
	_tcin >> future_year;

	// R-value
	int &&futureage(future_year - now_year + age);
	_tcout << future_year << STR(" 년에 ") + name + STR("님의 나이는 ")
		<< futureage << STR("살 입니다") << endl;
	pus(); cls();

	if (futureage < 100) {
		nameLength *= 10000;
		return nameLength + futureage;
	}

	else if (futureage < 10) {
		nameLength *= 1000;
		return nameLength + futureage;
	}

	else
		return EOF;
}


// 로또 번호를 출력하는 메서드
int CBasicStd::print_lotto()
{
	cls(); C_0E;
	::srand(CAST(unsigned int, time(NULL)));

	for (auto &lottos : lotto)
		lottos = ::rand() % 45 + 1;

	auto C(1);
	for (auto &PrintLotto : lotto) {
		cout << C << "번 숫자 : " << PrintLotto << endl;
		C++;
	}

	if (lotto[0] == lotto[1] == lotto[2] == lotto[3] == lotto[4] == lotto[5]) {
		cout << "이런. 숫자가 중복되는 군요." << endl << "다시 실행해 주세요." << endl;
		pus(); cls();
		return EOF;
	}
	cout << "메뉴로 돌아가려면 엔터키를 누르세요.";
	pus(); cls();
	return 1;
}


// 19단을 출력하는 메서드
int CBasicStd::Print_19dan()
{
	cls();
	for (int i = T; i <= 19; i++)
	{
		switch (i)
		{
		case 1: C_07; break;
		case 2: C_17; break;
		case 3: C_27; break;
		case 4: system("color 37"); break;
		case 5: system("color 47"); break;
		case 6: system("color 57"); break;
		case 7: system("color 67"); break;
		case 8: system("color 70"); break;
		case 9: system("color 87"); break;
		case 10: system("color 97"); break;
		case 11: system("color a0"); break;
		case 12: system("color b0"); break;
		case 13: C_C0; break;
		case 14: system("color d0"); break;
		case 15: C_E0; break;
		case 16: system("color f0"); break;
		case 17: C_07; break;
		case 18: C_17; break;
		case 19: C_27; break;
		}
		cout << i << "단 :" << endl;
		for (int l = T; l <= 19; l++)
			cout << i << " X " << l << " = " << i * l << endl;
		cout << "Enter키를 누르면 다음 단이 출력 됩니다...";
		pus(); cls();
	}
	cout << "Enter 키를 누르세요...";
	pus(); cls();
	return 1913;
}

// BMI지수를 계산하는 메서드
void CBasicStd::BMI()
{
	cls();

	_tcout << STR("키를 입력해 주세요(cm) : ");
	_tcin >> hei;

	_tcout << STR("몸무게를 입력해 주세요(kg) : ");
	_tcin >> wei;

	bmir = wei / (hei*hei / 10000.f);
	_tcout << fixed; _tcout.precision(2);

	_tcout << STR("당신의 BMI지수는 ") << bmir << "입니다." << endl;
	_tcout << STR("10~18.4 = 저체중") << endl << STR("18.5~24.9 = 정상") << endl
		<< STR("25~29.9 = 과체중") << endl << STR("30이상 = 비만") << endl;
	pus(); cls();
}


// Pro버전으로 업그레이드 시키는 메서드
int CBasicStd::To_Pro()
{
	cls();
	if (honor < 10)
	{
		std::cout << endl << "명예점수가 10점 이상인 경우에만 가능합니다." << endl;
		pus(1);  return 1;
	}

	for (short i = 0; i < 2; i++)
	{
		for (auto &la : load)
		{
			cls();
			std::cout << "							잠시만 기다리세요" << endl;
			std::cout << "							" << la; pus(0, 2);
		}
	}
	return 0;
}
