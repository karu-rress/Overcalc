#include "stdafx.h"
#include "Basic"

void Overcalc::CBMenu1::PrintMenu(void) const noexcept print_only
{
	IOsys.Color(COLORS::AQUA, COLORS::BRIGHT_WHITE);

	std::wcout << L"나의 나이는 0000년에 몇 살일까?                                                                                         " << std::endl;

	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"인형 뽑기 게임하기                                                                                                      " << std::endl
		<< L"로또 번호 출력                                                                                                          " << std::endl
		<< L"19단                                                                                                                    " << std::endl
		<< L"가위바위보 게임                                                                                                         " << std::endl
		<< L"달력 출력                                                                                                               " << std::endl
		<< L"BMI 계산하기                                                                                                            " << std::endl
		<< L"숫자 맞히기                                                                                                             " << std::endl
		<< L"Overcalc의 역사와 발전                                                                                                  " << std::endl
		<< L"Overcalc의 에디션                                                                                                       " << std::endl
		<< L"Pro버전으로 업그레이드                                                                                                  " << std::endl;
	IOsys.PrintBar();
	IOsys.Cur(18, 21);

	std::wcout << L"ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말" << std::endl;
}

void Overcalc::CBMenu1::PlayMenu(void) const
{
	Var std::wstring strName;

	IOsys.Clear();
	IOsys.SetBG(COLORS::GRAY, COLORS::LIGHT_GREEN);

	std::wcout << L"이름을 입력 하세요..." << std::endl;
	IOsys.Flush_In();																		// 입력 버퍼 비우기

	try
	{
		while (true)
		{
			getline(std::wcin, strName, L'\n');
			IOsys << Add_Log(L"나이계산기", strName + L"입력");

			for (auto &word : badwords)
			{
				if (strName.find(word) != std::wstring::npos)
				{
					std::wcout << L"나쁜말은 쓰지 맙시다!!!";
					strName.clear();
					break;
				} // if (strName.find(word) != std::wstring::npos)

				else
					throw 0;
			} // for (auto &word : COverStd::badwords)
		} // while (true)
	} // try
	catch (...) {   }

	Var int nNow_Year(0), nFuture_Year(0), nAge(0);

	std::wcout << L"현재 년도를 입력하세요..." << std::endl;
	std::wcin >> nNow_Year;

	while (!std::wcin)
	{
		std::wcout << L"숫자로 입력해 주세요." << std::endl;
		std::wcin.clear();
		std::wcin.ignore(INT_MAX, L'\n');
		IOsys.Clearline(4);
		std::wcin >> nNow_Year; continue;
	} // while (!std::wcin)

	IOsys << Add_Log(L"나이계산기 년도", nNow_Year);

	std::wcout << L"현재 나이를 입력하세요..." << std::endl;
	std::wcin >> nAge;

	while (!std::wcin)
	{
		std::wcout << L"숫자로 입력해 주세요." << std::endl;
		std::wcin.clear();
		std::wcin.ignore(INT_MAX, L'\n');
		IOsys.Clearline(6);
		std::wcin >> nAge; continue;
	} // while (!std::wcin)

	std::wcout << L"나이를 알고싶은 연도를 입력하세요..." << std::endl;
	std::wcin >> nFuture_Year;

	// R-value
	Var int &&nFutureAge(nFuture_Year - nNow_Year + nAge);
	std::wcout << nFuture_Year << L" 년에 " + strName + L"님의 나이는 "
		<< nFutureAge << L"살 입니다" << std::endl;
	IOsys.Pause().Clear();
}

void Overcalc::CBMenu2::DollGame(void) const
{
	IOsys.Clear();
	IOsys.SetBG(COLORS::GREEN, COLORS::BRIGHT_WHITE);

	IOsys.WriteLine(L"인형을 뽑습니다...1000원이 소비됩니다...");
	OData.Money -= 1'000;
	std::wcout << L"현재 잔액은 " << OData.getMoney() << L"원입니다." << std::endl;

	for (auto n : OData.pszJibgaeDown)
	{
		IOsys.Clear();
		IOsys.WriteLine(n);
		IOsys.WriteLine(OData.pszJibgaeHand);
		IOsys.Sleep_Mil(300);
	} // for (auto n : OData.pszJibgaeDown)

	IOsys.Sleep(2);

	for (auto n : OData.pszJibgaeUp)
	{
		IOsys.Clear();
		IOsys.WriteLine(n);
		IOsys.WriteLine(OData.pszJibgaeHand);
		IOsys.Sleep_Mil(300);
	} // for (auto n : OData.pszJibgaeUp)
}

void Overcalc::CBMenu2::PrintMenu() const noexcept
{
	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"나의 나이는 0000년에 몇 살일까?                                                                                         " << std::endl;

	IOsys.Color(COLORS::AQUA, COLORS::BRIGHT_WHITE);
	std::wcout << L"인형 뽑기 게임하기                                                                                                      " << std::endl;

	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"로또 번호 출력                                                                                                          " << std::endl
		<< L"19단                                                                                                                    " << std::endl
		<< L"가위바위보 게임                                                                                                         " << std::endl
		<< L"달력 출력                                                                                                               " << std::endl
		<< L"BMI 계산하기                                                                                                            " << std::endl
		<< L"숫자 맞히기                                                                                                             " << std::endl
		<< L"Overcalc의 역사와 발전                                                                                                  " << std::endl
		<< L"Overcalc의 에디션                                                                                                       " << std::endl
		<< L"Pro버전으로 업그레이드                                                                                                  " << std::endl;
	IOsys.PrintBar(), IOsys.Cur(18, 21);
	std::wcout << L"ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말" << std::endl;
}

void Overcalc::CBMenu2::PlayMenu() const
{
	auto KindOfDoll = [](void) -> void
	{
		std::wcout << L"1. 곰인형 : 잔액을 1000원 추가합니다.\n" << L"2. 라바 인형 : 잔액을 2000원 추가합니다." << std::endl;
		std::wcout << L"3. 지방이 인형 : 잔액을 3000원 추가합니다.\n" << L"4.심슨 인형 : 잔액을 5000원 추가합니다." << std::endl;
		std::wcout << L"5. 왕 곰인형 : 잔액을 2배로 증가시킵니다.\n" << L"6. ????? : 잔액을 10배로 증가시킵니다." << std::endl;
		std::wcout << L"7. 똥 인형 : 잔액을 3000원 감소시킵니다.\n" << L"8. 사탄의 인형 : 잔액을 0으로 만듭니다." << std::endl;
		IOsys.PauseMsg(); IOsys.Clear();
	};

	try {
		while (OData.getMoney() > 0)
		{
			Var int nMenu;
			IOsys.Clear();
			IOsys.NextLine();

			if (OData.getMoney() >= 20'000)
			{
				// 게임이 끝난다.
				std::wcout << L"축하합니다! 잔액이 20000원이상입니다." << std::endl <<
					L"게임을 클리어 하셨습니다." << std::endl << L"명예점수 4점이 올라갑니다." << std::endl;
				IOsys.PauseMsg(); Release();

				// topin 4점을 추가한다.
				OData.Topin += 4;

				// "Basic"버전의 "인형뽑기"게임에서, true (이겼다)했다!
				IOsys->WriteGameLog(L"Basic", L"인형뽑기", true);
				break;
			}

			DollMenu(nMenu);

			switch (nMenu)
			{
			case 1: DollGame();						break;
			case 2: KindOfDoll(); 					break;
			case 3: throw true;
			default: std::wcout << L"도데체 뭘 누른거야?";
				IOsys.Pause().Clear(); break;
			} // switch (iMenu)
		}// while (COberStd::money > 0)
	} // try
	catch (bool) { Release(); }

	if (OData.getMoney() <= 0)
	{
		GameOver(); Release(); IOsys.PauseMsg();
	} // if (money <= 0)
}

void Overcalc::CBMenu2::DollMenu(int & rnParam) const
{
	Var int iNum;
	IOsys.PrintBar();
	std::wcout << L"\t\t\t\t\t\t\t인형 뽑기" << std::endl;
	IOsys.PrintBar();
	std::wcout << L"1. 인형뽑기 게임하기		현재 잔액=" << OData.getMoney() << L"원" << std::endl;
	std::wcout << L"2. 인형종류 확인하기" << std::endl;
	std::wcout << L"3. 나가기\n" << L"> " << std::endl;
	std::wcin >> iNum;
	rnParam = iNum;
}

void Overcalc::CBMenu2::GameOver() const
{
	IOsys.Clear();
	IOsys.Color(COLORS::BLACK, COLORS::LIGHT_RED);

	for (auto _tch : OData.dolgm_ovr)
	{
		std::wcout << _tch;
		IOsys.Sleep(1);
	} // for (auto _tch : dolgm_ovr)

	  // "Basic"버전의 "인형뽑기"게임에서, false (졌다)했다!
	IOsys->WriteGameLog(L"Basic", L"인형뽑기", false);
}

void Overcalc::CBMenu3::PrintMenu() const noexcept
{
	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"나의 나이는 0000년에 몇 살일까?                                                                                         " << std::endl;
	std::wcout << L"인형 뽑기 게임하기                                                                                                      " << std::endl;

	IOsys.Color(COLORS::AQUA, COLORS::BRIGHT_WHITE);
	std::wcout << L"로또 번호 출력                                                                                                          " << std::endl;

	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"19단                                                                                                                    " << std::endl
		<< L"가위바위보 게임                                                                                                         " << std::endl
		<< L"달력 출력                                                                                                               " << std::endl
		<< L"BMI 계산하기                                                                                                            " << std::endl
		<< L"숫자 맞히기                                                                                                             " << std::endl
		<< L"Overcalc의 역사와 발전                                                                                                  " << std::endl
		<< L"Overcalc의 에디션                                                                                                       " << std::endl
		<< L"Pro버전으로 업그레이드                                                                                                  " << std::endl;
	IOsys.PrintBar();
	IOsys.Cur(18, 21);
	std::wcout << L"ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말" << std::endl;
}

void Overcalc::CBMenu3::PlayMenu() const
{
	IOsys.Clear();
	IOsys.Color(COLORS::LIGHT_YELLOW, COLORS::BLACK);

	Var std::random_device rd;
	Var std::default_random_engine rng(rd());

	Var std::uniform_int_distribution<int> lottoval(1, 44);

	Var std::vector<int> lotto(6);

	for (auto &n : lotto)
		n = lottoval(rng);

	Var int nCount(1);

	for (auto &n : lotto)
	{
		std::wcout << nCount << "번 숫자 : " << n << std::endl;
		nCount++;
	} // for (auto &n : lotto)

	std::wcout << "Basic 버전의 로또는 숫자가 겹칠 수 있습니다." << std::endl
		<< "숫자가 겹치는걸 원하지 않으시면 Pro버전으로 업그레이드 해 주세요." << std::endl << std::endl
		<< "메뉴로 돌아가려면 엔터키를 누르세요.";
}

void Overcalc::CBMenu4::PrintMenu() const noexcept
{
	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"나의 나이는 0000년에 몇 살일까?                                                                                         " << std::endl;
	std::wcout << L"인형 뽑기 게임하기                                                                                                      " << std::endl;
	std::wcout << L"로또 번호 출력                                                                                                          " << std::endl;

	IOsys.Color(COLORS::AQUA, COLORS::BRIGHT_WHITE);
	std::wcout << L"19단                                                                                                                    " << std::endl;

	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"가위바위보 게임                                                                                                         " << std::endl
		<< L"달력 출력                                                                                                               " << std::endl
		<< L"BMI 계산하기                                                                                                            " << std::endl
		<< L"숫자 맞히기                                                                                                             " << std::endl
		<< L"Overcalc의 역사와 발전                                                                                                  " << std::endl
		<< L"Overcalc의 에디션                                                                                                       " << std::endl
		<< L"Pro버전으로 업그레이드                                                                                                  " << std::endl;
	IOsys.PrintBar();
	IOsys.Cur(18, 21);
	std::wcout << L"ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말" << std::endl;
}


void Overcalc::CBMenu4::PlayMenu() const
{
	IOsys.Clear();

	Var const auto color = std::make_unique<std::wstring>(L"color ");
	Var int nCount(1);
	Var const std::vector<const wchar_t*> colors
	{
		L"07", L"17", L"27", L"37", L"47", L"57", L"67", L"70", L"87", L"97",
		L"A0", L"B0", L"C0", L"D0", L"E0", L"F0", L"07", L"17", L"27"
	};

	for (auto n : colors)
	{
		// 이 단 한줄의 코드가 기존의 19가지의 case 문에 대응한다!
		IOsys.Command(*color + n);

		std::wcout << nCount << L"단" << std::endl;

		for (int i(1); i < 19; ++i)
			std::wcout << nCount << L" X " << i << L" = " << nCount * i << std::endl;

		std::wcout << L"Enter 키를 누르면 다음 단이 출력 됩니다...";
		IOsys.Pause().Clear();
	} // for (auto n : colors)

	std::wcout << "메인으로 돌아가려면 아무키나 누르세요...";
	IOsys.Pause().Clear();
}

void Overcalc::CBMenu5::PrintMenu() const noexcept
{
	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"나의 나이는 0000년에 몇 살일까?                                                                                         " << std::endl;
	std::wcout << L"인형 뽑기 게임하기                                                                                                      " << std::endl;
	std::wcout << L"로또 번호 출력                                                                                                          " << std::endl;
	std::wcout << L"19단                                                                                                                    " << std::endl;

	IOsys.Color(COLORS::AQUA, COLORS::BRIGHT_WHITE);
	std::wcout << L"가위바위보 게임                                                                                                         " << std::endl;

	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"달력 출력                                                                                                               " << std::endl
		<< L"BMI 계산하기                                                                                                            " << std::endl
		<< L"숫자 맞히기                                                                                                             " << std::endl
		<< L"Overcalc의 역사와 발전                                                                                                  " << std::endl
		<< L"Overcalc의 에디션                                                                                                       " << std::endl
		<< L"Pro버전으로 업그레이드                                                                                                  " << std::endl;
	IOsys.PrintBar();
	IOsys.Cur(18, 21);
	std::wcout << L"ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말" << std::endl;
}
void Overcalc::CBMenu5::PlayMenu() const
{
	int menu;
	while (OData.Jumsu < 10 && OData.Jumsu > -3)
	{
		menu = KababoMenu();
		int &&Rv{PlayRSP(menu)};
		if (Rv == 4)
		{

		}
	}
}

int Overcalc::CBMenu5::KababoMenu() const
{
	int menu;
	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::BLACK);
	IOsys.Clear();
	IOsys.PrintBar();
	std::wcout << L"\t\t\t\t\t    가위바위보 게임(현재 점수=" << OData.Jumsu << L')' << std::endl;
	IOsys.PrintBar();
	IOsys.WriteLine(L"1. 가장 먼저 읽으세요-게임 방법");
	IOsys.WriteLine(L"2. 가위바위보 게임하기");
	IOsys.WriteLine(L"3. 인생역전 가위바위보");
	IOsys.WriteLine(L"4. 메인으로 돌아가기");
	IOsys.PrintBar();
	IOsys.Write(L"선택\\> ");
	std::wcin >> menu;
	return menu;
}

int Overcalc::CBMenu5::PlayRSP(const int &rParam) const
{
	std::vector<std::function<int()> > Games
	{
		[this] { this->How(); return 1; },
		[this] { this->RSP(); return 2; },
		[this] { this->LifeRSP(); return 3; },
		[ ] { return 4; }
	};
	return Games[rParam - 1]();
}

void Overcalc::CBMenu6::PrintMenu() const noexcept
{
	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"나의 나이는 0000년에 몇 살일까?                                                                                         " << std::endl
		<< L"인형 뽑기 게임하기                                                                                                      " << std::endl
		<< L"로또 번호 출력                                                                                                          " << std::endl
		<< L"19단                                                                                                                    " << std::endl
		<< L"가위바위보 게임                                                                                                         " << std::endl;

	IOsys.Color(COLORS::AQUA, COLORS::BRIGHT_WHITE);

	std::wcout << L"달력 출력                                                                                                               " << std::endl;

	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
		std::wcout << L"BMI 계산하기                                                                                                            " << std::endl
		<< L"숫자 맞히기                                                                                                             " << std::endl
		<< L"Overcalc의 역사와 발전                                                                                                  " << std::endl
		<< L"Overcalc의 에디션                                                                                                       " << std::endl
		<< L"Pro버전으로 업그레이드                                                                                                  " << std::endl;
		IOsys.PrintBar();
		IOsys.Cur(18, 21);
	std::wcout << L"ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말" << std::endl;
}

void Overcalc::CBMenu6::PlayMenu() const
{

}

void Overcalc::CBMenu7::PrintMenu() const noexcept
{
	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"나의 나이는 0000년에 몇 살일까?                                                                                         " << std::endl
		<< L"인형 뽑기 게임하기                                                                                                      " << std::endl
		<< L"로또 번호 출력                                                                                                          " << std::endl
		<< L"19단                                                                                                                    " << std::endl
		<< L"가위바위보 게임                                                                                                         " << std::endl
		<< L"달력 출력                                                                                                               " << std::endl;

	IOsys.Color(COLORS::AQUA, COLORS::BRIGHT_WHITE);
	std::wcout << L"BMI 계산하기                                                                                                            " << std::endl;

	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
		std::wcout << L"숫자 맞히기                                                                                                             " << std::endl
		<< L"Overcalc의 역사와 발전                                                                                                  " << std::endl
		<< L"Overcalc의 에디션                                                                                                       " << std::endl
		<< L"Pro버전으로 업그레이드                                                                                                  " << std::endl;
		IOsys.PrintBar();
		IOsys.Cur(18, 21);
	std::wcout << L"ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말" << std::endl;
}

void Overcalc::CBMenu7::PlayMenu() const
{
}

void Overcalc::CBMenu8::PrintMenu() const noexcept
{
	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"나의 나이는 0000년에 몇 살일까?                                                                                         " << std::endl
		<< L"인형 뽑기 게임하기                                                                                                      " << std::endl
		<< L"로또 번호 출력                                                                                                          " << std::endl
		<< L"19단                                                                                                                    " << std::endl
		<< L"가위바위보 게임                                                                                                         " << std::endl
		<< L"달력 출력                                                                                                               " << std::endl;

	IOsys.Color(COLORS::AQUA, COLORS::BRIGHT_WHITE);
	std::wcout << L"BMI 계산하기                                                                                                            " << std::endl;

	IOsys.Color(COLORS::BRIGHT_WHITE, COLORS::AQUA);
	std::wcout << L"숫자 맞히기                                                                                                             " << std::endl
		<< L"Overcalc의 역사와 발전                                                                                                  " << std::endl
		<< L"Overcalc의 에디션                                                                                                       " << std::endl
		<< L"Pro버전으로 업그레이드                                                                                                  " << std::endl;
	IOsys.PrintBar();
	IOsys.Cur(18, 21);
	std::wcout << L"ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말" << std::endl;
}

void Overcalc::CBMenu8::PlayMenu() const
{
}

void Overcalc::CBMenu9::PrintMenu() const noexcept
{
}

void Overcalc::CBMenu9::PlayMenu() const
{
}

void Overcalc::CBMenu10::PrintMenu() const noexcept
{
}

void Overcalc::CBMenu10::PlayMenu() const
{
}

void Overcalc::CBMenu11::PrintMenu() const noexcept
{
}

void Overcalc::CBMenu11::PlayMenu() const
{
}
