//
// Source of the COverStd class.
// OverStd.cpp
//
//			Copyright 2017 Allen Na. All rights reserved.
//
//
//

#include "stdafx.h"
#include "OverStd.h"


// 메일을 전송하는 COS의 소멸자!
OverStd::~OverStd()
{
	/*
	using namespace EASendMailObjLib;
	::CoInitialize(NULL);

	IMailPtr mail(nullptr);
	mail.CreateInstance("EASendMailObj.Mail");
	mail->LicenseCode = _T("TryIt");

	// 이메일 주소 설정
	mail->FromAddr = _T("******@*****.***");

	// 수신자 이메일 주소 설정
	mail->AddRecipientEx(_T("******@*****.***"), 0);

	// 이메일 제목 설정
	mail->Subject = _T("Overcalc Test Result");

	// 이메일 몸체
	mail->BodyText = _T("Here's Overcalc Test Result. \n \
A Tester has been operated Overcalc.");

	// 지메일 SMTP 서버 주소
	mail->ServerAddr = _T("smtp.gmail.com");

	// 파일 추가
	mail->AddAttachment("TestLog.log");

	// 포트
	mail->ServerPort = 587;

	// SSL/TLS 자동 감지
	mail->SSL_init();

	// 서버로 사용할 보내는 사람 계정
	mail->UserName = _T("******@*****.***");
	mail->Password = _T("***********");

	if (mail != nullptr)
		mail.Release();
	*/
}

// Overcalc 부팅시에 표시되는 화면
int OverStd::BootScr()
{
	for (int iz = 0; iz < 60; iz++) { Print << CAST(character, 128); } cout << endl << endl;
	_tprintf(STR("      %c%c%c        %c        %c    %c%c%c%c%c    %c%c%c%c        %c%c%c       %c        %c             %c%c%c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("    %c      %c      %c        %c    %c            %c      %c    %c           %c  %c      %c           %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("  %c          %c    %c        %c    %c            %c      %c   %c           %c    %c     %c          %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("  %c          %c    %c        %c    %c%c%c%c%c    %c%c%c%c     %c          %c%c%c%c%c    %c          %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("  %c          %c     %c      %c     %c            %c      %c   %c          %c      %c    %c          %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("    %c      %c        %c    %c      %c            %c      %c    %c         %c      %c    %c           %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("      %c%c%c            %c%c        %c%c%c%c%c    %c      %c      %c%c%c   %c      %c    %c%c%c%c%c     %c%c%c \n\n\n\n\n\n\n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	Print << STR("					Beyond the limits of a calculator.") << endl;
	Print << STR("						Beyond your limits."); for (int i = 0; i < 5; i++) { _tcout << endl; }
	Print << STR("					   	      -%s-", VER); for (int i = 0; i < 3; i++) { _tcout << endl; }
	Print << STR("					   	    2017 Allen Na"); for (int i = 0; i < 3; i++) { _tcout << endl; }
	return 0;
}

// 이스터에그 부팅시에 표시되는 화면
int OverStd::EasterBoot()
{
	for (int iz = 0; iz < 60; iz++) { Print << CAST(character, 128); } cout << endl;
	_tprintf(STR("      %c%c%c        %c        %c    %c%c%c%c%c    %c%c%c%c        %c%c%c       %c        %c             %c%c%c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("    %c      %c      %c        %c    %c            %c      %c    %c           %c  %c      %c           %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("  %c          %c    %c        %c    %c            %c      %c   %c           %c    %c     %c          %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("  %c          %c    %c        %c    %c%c%c%c%c    %c%c%c%c     %c          %c%c%c%c%c    %c          %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("  %c          %c     %c      %c     %c            %c      %c   %c          %c      %c    %c          %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("    %c      %c        %c    %c      %c            %c      %c    %c         %c      %c    %c           %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("      %c%c%c            %c%c        %c%c%c%c%c    %c      %c      %c%c%c   %c      %c    %c%c%c%c%c     %c%c%c \n\n\n\n\n\n\n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	Print << STR("					Beyond the limits of a calculator.") << endl;
	Print << STR("						Beyond your limits."); for (int i = 0; i < 5; i++) { cout << endl; }
	Print << STR("					       E A S T E R	E G G"); for (int i = 0; i < 3; i++) { cout << endl; }
	Print << STR("					   	    2017 Allen Na"); for (int i = 0; i < 3; i++) { cout << endl; }
	return 0;
}

// 이스터에그의 새 메뉴를 만들때 표시되는 화면
int OverStd::MkEasterMenu()
{
	for (int iz = 0; iz < 60; iz++) { Print << CAST(character, 128); } cout << endl;
	_tprintf(STR("      %c%c%c        %c        %c    %c%c%c%c%c    %c%c%c%c        %c%c%c       %c        %c             %c%c%c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("    %c      %c      %c        %c    %c            %c      %c    %c           %c  %c      %c           %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("  %c          %c    %c        %c    %c            %c      %c   %c           %c    %c     %c          %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("  %c          %c    %c        %c    %c%c%c%c%c    %c%c%c%c     %c          %c%c%c%c%c    %c          %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("  %c          %c     %c      %c     %c            %c      %c   %c          %c      %c    %c          %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("    %c      %c        %c    %c      %c            %c      %c    %c         %c      %c    %c           %c \n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	_tprintf(STR("      %c%c%c            %c%c        %c%c%c%c%c    %c      %c      %c%c%c   %c      %c    %c%c%c%c%c     %c%c%c \n\n\n\n\n\n\n"), 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128);
	Print << STR("					Beyond the limits of a calculator.") << endl;
	Print << STR("						Beyond your limits."); for (int i = 0; i < 5; i++) { cout << endl; }
	Print << STR("					       숨겨진 메뉴를 만드는중...."); for (int i = 0; i < 3; i++) { cout << endl; }
	Print << STR("					   	    2017 Allen Na"); for (int i = 0; i < 3; i++) { cout << endl; }
	return 0;
}

// 날짜와 시각을 구해 문자열로 리턴하는 메서드
char *OverStd::Date()
{
	__time64_t now = time(NULL);
	struct tm tstruct;
	char *buf = { 0 };
	localtime_s(&tstruct, &now);
	strftime(buf, sizeof(buf), "%F    %T", &tstruct);
	
	return buf;
}

wchar_t * OverStd::wDate()
{
	__time64_t now = time(NULL);
	struct tm tstruct;
	wchar_t *buf = { 0 };
	localtime_s(&tstruct, &now);
	wcsftime(buf, sizeof(buf), L"%F    %T", &tstruct);

	return buf;
}

// Overcalc Starter
int OverStd::start_overcalc(void)
{
	WriteTestLog("Overcalc Starter", "기능 시작");
	int a, &rlang = this->language;
	cls();
	cur(24, 2);
	std::wcout << STR("Overcalc Starter");
	cur(24, 4);
	wcout << STR("Please select your language.") << endl << endl;
	wcout << L"	1. 한국어" << endl << L"	2.English" << endl
		<< L"	3.한국어-스타터 버전 건너 뛰기" << endl << L"	4.I'm English. Skip Starter version." << endl;
	while (1)
	{
		while (true)
		{
			cin >> a;
			if (a >= 1 && a <= 4) { break; }
			else {
				_tcout << STR("Wrong value. Retry.") << endl;
			}

			if (!cin)
			{
				_tcout << STR("Input \"NUMBER\"") << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
		
		switch (a)
		{
		case 1: rlang = 1; break;
		case 2: rlang = 2; break;
		case 3: rlang = 1; return 1;
		case 4: rlang = 2; return 2;
		default: wcout << L"Wrong Number. Select your language. : "; pus(); continue;
		}
		break;
	}
	if (rlang == 1)
	{
		wcout << L"간단한 설명을 해드리겠습니다." << endl;
		wcout << L"메뉴 화면에서 해당 항목의 번호를 입력한 후 Enter키를 눌러보세요." << endl;
		pus(1);
		wcout << L"1. 메뉴 1" << endl << L" 2. 메뉴 2" << endl;
	}
	WriteTestLog("Overcalc Starter", "종료");
	return 0;
}

// 배경색과 글자색을 개별로 설정해주는 메서드
void OverStd::color(unsigned short text_color, unsigned short back_color)
{
	::SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), 
		text_color | (back_color << 4)
	);
}

// 커서의 위치를 바꾸는 메서드
void OverStd::cur(int width_from_left, int height_from_top)
{
	COORD Cur;
	Cur.X = width_from_left;
	Cur.Y = height_from_top;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 매개변수에 따라 화면을 지우거나 한줄을 지우는 정적 메서드
void OverStd::cls(int line)
{
	// EOF가 인수라면 전체 지움이다.
	if (line == EOF)
		std::system("CLS");
	
	// 아니라면 그 줄만 지움(위에 덮어씀)
	else
		COverStd::cur(0, line); _tcout << STR("                                                                                         ");
}

// 매개변수에 따라 Sleep, getch, system("pause")의 역할을 함
void OverStd::pus(int is_pus /* = 0*/, int Sec /* = 0*/)
{
	// 첫째 매개변수에 값이 있다면
	if (is_pus != 0)
		std::system("PAUSE");				// 콘솔 pauser 실행

	// 아님 초값이 들어왔다면?
	else if (Sec != 0) 
		(Sec > 0) ? ::Sleep(Sec) : Sec = (0 - Sec), ::Sleep(Sec);
	// 0보다 크면 초단위로 중지, 작으면 밀리초 단위로 중지.

	// 값이 아예 없으면 _getch();
	else
		::_getch();
}


// Overcalc의 발전을 출력하는 메서드
int OverStd::dvlp_Overcalc()
{
	character *development_pt1[] {
		_T("Overcalc의 발전"),
		_T("Alpha-년도를 넣으면 그때 몇 살인지 알려주는 프로그램 개발"),
		_T("Beta-라면 시간 계산기 추가"),
		_T("FinalBeta-프로그램의 틀 디자인"),
		_T("v1.0-\"만능 계산기\"라는 이름으로 정식 출시 및 메뉴 1개 추가"),
		_T("v1.2-메뉴 3개 추가"),
		_T("v1.25-알려진 보안 문제 수정"),
		_T("v1.4-인형뽑기 게임 추가"),
		_T("v1.41-주석 추가"),
		_T("v1.5-로또 숫자 출력 프로그램 추가"),
		_T("v1.6-\"만능 프로그램\"으로 이름 변경"),
		_T("v1.7-색상 추가"),
		_T("v1.72-버퍼 오버플로우(BOF)및 메모리 보안 강화"),
		_T("v1.8-19단 추가"),
		_T("v1.9-달력 프로그램 추가"),
		_T("v1.95-메뉴별로 함수를 독립시킴으로서 프로그램 안정성 강화"),
		_T("B2.0-BMI측정기 추가"),
		_T("v2.0-2.0버전 정식 출시 및 숫자 맞히기 게임 추가"),
		_T("v2.1-만능 프로그램에서 Overcalc로 이름 변경"),
		_T("Bluebelt(2.2)-명예점수 추가 및 Pro버전 생성"),
		_T("Firesnake(2.3)-Pro버전의 제품키를 랜덤생성 및 인증되지 않은 버전의 기능 축소"),
		_T("Zaicyan(2.5)-Pro버전의 계산기가 무한 반복되는 현상 수정 및 인형뽑기에서 흔들기 추가"),
		_T("Rakhakimen(2.8)-Pro버전의 쓸데없는 라면 시간 계산기를 라면 분석기로 업그레이드"),
		_T("Losapphire(2.9)-Pro버전의 로또번호가 겹치는 현상 수정 및 오름차순으로 정렬"),
		_T("Losapphire2(2.95)-게임을 끝내고 다시 실행했을때 점수와 돈 등이 그대로인 현상 수정"),
		_T("Losapphire3(2.99)-자잘한 버그 수정 및 프로그램 최적화"),
		_T("Optimijade(3.0)-3.0버전 정식 출시 및 소스코드 단축"),
		_T("Kabaflame(3.1)-가위바위보를 하면 메인으로 돌아가는 현상 수정")
	};
	character *development_pt2[] {
		_T("Overcalc의 발전"),
		_T("Emeralsiker(3.15)-구조체 이용으로 소스 코드 더 단축"),
		_T("Emeralsiker(3.15)-구조체 이용으로 소스 코드 더 단축"),
		_T("Emeralsiker2(3.2)-콩 스탬프 계산기의 기능 강화"),
		_T("Cobaltimer(3.3)-Pro버전에서 타이머 기능 추가"),
		_T("Eastersmalt(3.7)-대규모의 이스터 에그 생성"),
		_T("Enterare(3.8)-Premium버전 생성"),
		_T("Plusplus(3.99)-C프로그램을 C++프로그램으로 재구축"),
		_T("4(Saver)-저장 기능 추가"),
		_T("5(Arrown)-메뉴 선택을 화살표로 하게 만들고 이스터에그 접근방식 변경"),
		_T("6(with OOP)-완전한 객체지향 프로그램으로 만들고 부팅화면 변경")
	};

	// 시작하기에 앞서 화면을 지움
	cls();

	for (auto &n : development_pt1)	
		_tcout << n << endl;
	
	pus(1); cls();

	for (auto &n : development_pt2)
		_tcout << n << endl;

	pus(); cls();
	return 0;
}


// 에디션의 종류를 출력하는 정적 메서드
int OverStd::Editions()
{
	cout << "1. TUTOR" << endl;
	cout << "2. BAISC" << endl;
	cout << "Overcalc를 시작하면 바로 보이는 버전입니다." << endl;
	cout << "주요 기능으로는 인형뽑기, 가위바위보 게임 등이 있습니다." << endl;
	cout << "3. PRO" << endl;
	cout << "BASIC버전을 업그레이드 하면 사용할 수 있는 버전입니다." << endl;
	cout << "주요 기능으로는 로또 번호 출력, 계산기 등이 있습니다." << endl;
	cout << "4. ENTERPRISE" << endl;
	cout << "5. ULTIMATE" << endl;
	cout << "6. PREMIUM" << endl;
	cout << "7. OVERCALC" << endl;
	cout << "8. OVERCALC+" << endl;
	pus(); cls();
	return 0;
}

// 콘솔 창의 제목을 설정하는 정적 메서드
void *OverStd::title(const char * pszTitle)
{
	char *console_title{ NULL, };				// char *형식의 문자열 버퍼를 생성한다.
	int nLength = strlen(pszTitle) + 8;
	strcpy_s(console_title, 7, "title ");				// console_title : "title "
	strcat_s(console_title, nLength, pszTitle);				// console_title : "titile ~"
	system(console_title);								// system("title ~");

	// 문자열 버퍼의 주소를 반환하고 종료
	return console_title;
}
