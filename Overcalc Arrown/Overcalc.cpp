//
// the Source Code of the Overcalc
//		Overcalc.cpp
//
//			Copyright 2017 Allen Na. All rights reserved.
//If there is a problem, please support to
//******@*****.***.
//
//에디션
//BASIC				기본 버전
//PRO					프로 버전
//PREMIUM			프미 버전
//ENTERPRISE		엔터 버전
//ULTIMATE			얼티 버전
//OVERCALC		오버 컬크
//OVERCALC+		오버 컬크 +


//♠ U+2660 Black Spade Suit
//♡ U + 2661 White Heart Suit
//♢ U + 2662 White Diamond Suit
//♣ U + 2663 Black Club Suit
//♤ U + 2664 White Spade Suit
//♥ U + 2665 Black Heart Suit
//♦ U + 2666 Black Diamond Suit
//♧ U + 2667 White Club Suit
//
//예제 코드 및 결과화면.
//#include <iostream>
//#include <clocale>
//const wchar_t heart[] = L"\u2665"; // L 은 Literal String을 의미함


//Errors
//01-저장된 파일 읽기 실패
//02-
//03
//04
//05
//06

// 콘솔 창 - 60*30
//이것의 값이..

// Honor, IS_DEBUG, IS_TEST 등의 값은 StdAfx.h에서 해결하도록.
#include "stdafx.h"


/* 전역변수로 생성된 클래스다. 이 클래스들의 생성자가 _tmain()함수보다 먼저 호출된다! */
#pragma message("전역클래스 생성자 호출")


namespace B
{
	integer money(5000);
	String kaba; integer jumsu(0);
}

#pragma message("_tmain() 함수가 시작되었습니다.")
int _tmain(int argc, _TCHAR* argv[])
{

	WriteTestLog("미확인", "Overcalc 시작");

	CBasicStd BS;
	// CB_HelpError CB_HE;
	CBDoll BD(B::money);

	CBkababo BK(B::kaba, B::jumsu);

	CBSutja BSU;

	CBCal BC;

	if (MF.Read == EOF)
		OS.start_overcalc();

	BASIC
	{
		WriteTestLog(STR("Overcalc Basic"), STR("시작"));
	BS.PrintMenu();
	int menu;
	BS.SelectMenu(menu);
	flush;
	switch (menu)
	{
	case 0: break;
	case 1: BS.age_calc(); break;
	case 2:

		while (B::money > 0)
		{
			int dollmenu;
			S::cls();
			cout << endl;
			if (B::money >= 20000)
			{
				// 게임이 끝난다.
				std::cout << "축하합니다! 잔액이 20000원이상입니다." << endl <<
					"게임을 클리어 하셨습니다." << endl << "명예점수 4점이 올라갑니다." << endl;
				S::pus(1);

				// 명예점수 4점을 추가한다.
				OS.honor += 4;

				// "Basic"버전의 "인형뽑기"게임에서, true (이겼다)했다!
				MF.WriteGameLog("Basic", "인형뽑기", true);
				break;
			}

			BD.doll_menu(dollmenu);

			switch (dollmenu)
			{
			case 1: BD.Doll_Game();						break;
			case 2: BD.kind_of_dolls(); 					break;
			case 3: BD.Doll_key();							break;
			case 4: BD.go_to = true;						break;							// -------|-------
			default: std::cout << "도데체 뭘 누른거야?"; S::pus(); S::cls(); break;			//           |
			}																									//           |
																												//           |
			if (BD.go_to == true) { BD.go_to = false; BD.Release(); break; }					// break로 탈출!
		}

		if (B::money <= F) {
			BD.gameover(); BD.Release(); S::pus(1); break;
		}
		break;

	case 3: BS.print_lotto();								break;
	case 4: BS.Print_19dan();							break;
	case 5:
		while (B::jumsu < 10 && B::jumsu > -3)
		{
			BK.Print_Menu();
			int ch = BK.Call_menu();
			if (ch == ESCAPE)
				break;
			S::cls();
		}
		if (B::jumsu >= 10) {
			S::cls();
			cout << "당신의 이겼습니다. 축하드립니다. 메인으로 돌아갑니다.\n" << "추가로, 명예점수 2점을 지급해 드립니다." << endl;
			S::pus(1); OS.honor += 2;
			MF.WriteGameLog("Basic", "가위바위보", true);
		}

		else if (B::jumsu < -2)
		{
			S::cls();	C_0C;
			MF.WriteGameLog("Basic", "가위바위보", false);
			for (integer qa = 0; qa < 2; qa++)
				cout << "이런, "; S::pus(0, 1);

			cout << "이런...."; S::pus(0, 1);
			cout << "\n당신의 졌습니다.... 유감입니다. 메인으로 돌아갑니다.";
			MF.WriteGameLog("Basic", "숫자맞추기", false);
			S::pus(1); C_0F;
		}

		S::cls(); B::jumsu = 0; break;
	case 6:
		int year, day_code, leap;
		year = BC.get_year();
		day_code = BC.get_day_code(year);
		leap = BC.get_leap_year(year);
		BC.print_calendar(year, day_code, leap); S::pus(); break;

	case 7: BS.BMI(); break;
	case 8:
		while (true)
		{
			BSU.PrintMenu();
			int Reval = BSU.CallMenu();

			if (Reval == ESCAPE)
				break;
		}
		S::cls(); BSU.Release(); break;
	case 9: S::dvlp_Overcalc(); break;
	case 10: S::Editions();   break;
	case 11: int Did;
		Did = BS.To_Pro();

		//	if (Did == 0)			
		// goto pro;
		break;
	case 0xf1: // CB_HE.PrintHelp();
	case EOF: break;
	case ESCAPE:
		return 0;
	}
	}

	PRO
	{

	}
	return 0;
#pragma message("0이 반환되었고 _tmain() 함수가 종료되었습니다.")
}

