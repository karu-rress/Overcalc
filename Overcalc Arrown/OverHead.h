//
// First Header of the Overcalc.
// OverHead.h
//
//			Copyright 2017 Allen Na. All rights reserved.
//
//		this header :
//		TYPEDEFs
//     variables
//		const char* array variables
//		defines
//

#pragma once
#include "stdafx.h"

[[deprecated]] constexpr char arm{'\a'};

constexpr char* BP_BAR{"========================================================================================================================"};

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//   Macro for Menu Designs - Titles, Boot Screens
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

constexpr auto SUCCESS{1}, FAILURE{0}, ESCAPE{-9};
#define MENU_TITLE	Print << STR("                      			     Overcalc BASIC Arrown			    	    by Allen Na") << endl				// Title Macro
#define HONOR			Print << STR("													명예 점수 : ") << honor << endl											// Title Macro
#define PRO_BAR 		for (int iz = 0; iz < 60; iz++) { std::cout << CAST(unsigned char, 128); } NLINE															// Title Macro
#define END				for (int iz = 0; iz < 60; iz++) { std::cout << CAST(unsigned char, 128); }																	// Boot Macro
#define PRO_TITLE		Print << STR("                      				   Overcalc PRO Arrown					   by Allen Na") << endl					// Title Macro
#define PRE_TITLE		Print << STR("                      			  Overcalc PREMIUM Arrown					   by Allen Na") << endl				// 문자 계열 디파인
#define ENT_TITLE		Print << STR("                      		    Overcalc ENTERPRISE Arrown					   by Allen Na") << endl				// 문자 계열 디파인
#define EASTER_TIT		Print << STR("                      				Easter Egg Plusplus				    	    by Allen Na") << endl					// 문자 계열 디파인
#define PHONOR		Print << STR("													명예 점수 : ") << *phonor << endl											// 문자 계열 디파인
#define B_UNMENU	Print << STR("========================================================================================================================") << endl;\
		COverStd::cur(18, 21); Print << STR("ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말") << endl; break
#define P_UNMENU	Print << STR("========================================================================================================================") << endl;\
		COverStd::cur(3, 22); Print << STR("ESC - 나가기		방향키 - 이동		엔터 - 실행		F1키 - 도움말	   F10키 - 저장 후 종료") << endl; break


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//   Macro for Programming - Sleeps, Pauses, Colors
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// Sleeps
/*
#define PT							::Sleep(3000)											// Sleep 디파인   
#define PS2							::Sleep(2000)											// Sleep 디파인
#define PS							::Sleep(1000)											// Sleep 디파인
#define P5							::Sleep(500)												// Sleep 디파인
#define P2							::Sleep(200)												// Sleep 디파인
#define P								::Sleep(50)												// Sleep 디파인
*/

// Colors
#define C_07						::system("COLOR 07")								// 검정-하얀색 기본 컬러 디파인
#define C_0C						::system("COLOR 0c")								// 검정-밝은 빨간색 컬러 디파인
#define C_0F						::system("COLOR 0f")								// 검정-밝은 하얀색 컬러 디파인
#define C_3F						::system("COLOR 3f")								// 하늘색-밝은 흰색 컬러 디파인
#define C_60						::system("COLOR 60")								// 탁한 노랑-검정색 컬러 디파인
#define C_5F						::system("COLOR 5f")								// 자주-밝은 흰색의 컬러 디파인
#define C_8A						::system("COLOR 8a")								// 회색-형광 녹색의 컬러 디파인
#define C_A3						::system("COLOR a3")								// 형광 녹색-남색의 컬러 디파인
#define C_27						::system("COLOR 27")								// 진한 녹색-흰색의 컬러 디파인
#define C_0E						::system("COLOR 0e")								// 검정-밝은 노란색 컬러 디파인
#define C_75						::system("COLOR 75")								// 회색-진한 보라색 컬러 디파인					

/*미세먼지 색상*/
#define C_C0						::system("COLOR c0")								// 빨강-검정의 "매우나쁨" 디파인
#define C_E0						::system("COLOR e0")								// 노랑-검정의 "나쁨" 디파인
//#define C_27						::system("COLOR 27")								// 은 위에 이미 정의 되어 있으므로 생략		
#define C_17						::system("COLOR 17")								// 파랑-흰색의 "좋음" 디파인

/*이스터 에그 색상*/
#define GREEN					::system("COLOR 0a")								// 검은 바탕에 밝은 녹색 디파인
#define PINK						::system("COLOR 0d")								// 검은 바탕에 밝은 분홍 디파인
#define WHITE					::system("COLOR 0f")								// 검은 바탕에 밝은 흰색 디파인
#define YELLOW					::system("COLOR 0e")								// 검은 바탕에 밝은 노랑 디파인
#define BLUE						::system("COLOR 0b")								// 검은 바탕에 밝은 파랑 디파인

#define flush						 std::cin.ignore(128, '\n')

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//   Macro for Others
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


#define BASIC while(true)
#define PRO while(true)

#if IS_DEBUG == 1									
//1이라면 이 스위치가 켜지면서
#define DEBUG										
//DEBUG가 디파인 되고
#pragma message("사용자 DEBUG매크로가 활성화 되어 있습니다.")
#else
// 0이라면 DEBUG가 디파인 되지 않고
#ifdef DEBUG
#undef DEBUG
#endif  

#endif															// IS_DEBUG == 1

#ifdef DEBUG
// DEBUG가 디파인 되면 이 스위치가 켜지며
#define msgout(x) Print This STR(#x) and NextLine;
// msgout매크로가 동작한다
#else
// 그러므로 msgout매크로가 아무런 역할도 하지 않는다.
#define msgout(x)
#endif																// DEBUG

#if IS_TEST == 1
#define TEST
#pragma message("사용자 TEST매크로가 활성화 되어 있습니다.")
#endif // IS_TEST == 1
