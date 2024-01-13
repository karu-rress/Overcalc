//
// Header of the COverStd class.
// OverStd.h
//
//			Copyright 2019 Allen Na. All rights reserved.
//
//
//

#pragma once
#include "stdafx.h"

class OverStd
{
	friend class CHelpError;

protected:
	// Overcalc 부팅시에 표시되는 화면
	int BootScr();

	// 이스터에그 부팅시에 표시되는 화면
	int EasterBoot();

	// 이스터에그의 새 메뉴를 만들때 표시되는 화면
	int MkEasterMenu();

	constexpr char* arr[5]{".", "..", "...", "....", "....."};
	constexpr char* load[18]{".    ", "..   ", "...  ", ".... ", ".....", " .....", "  .....", "   .....", "    .....", "     .....", "      .....", "       .....", "        .....", "         .....", "          .....", "           ...."
		, "            ...", "             ..", "              .", "                   "};
	constexpr char *badwords[10]badwords{"지랄", "씨발", "씨X", "씨*", "존나", "개", "새끼", "존나", "놈", "병신"};
	int lotto[5]{0,};
public:

	OverStd() = default;

	// 메일을 전송하는 COS의 소멸자!
	~OverStd();


	// 날짜와 시각을 구해 문자열로 리턴하는 메서드
	static char *Date();
	static wchar_t *wDate();

	// Overcalc Starter
	int start_overcalc(void);

	static void color(unsigned short text_color, unsigned short back_color);
	static void cur(int width_from_left, int height_from_top);
	static void cls(int line = EOF);

	// 매개변수에 따라 Sleep, getch, system("pause")의 역할을 함
	static void pus(int is_pus = 0, int Sec = 0);

	// Overcalc의 발전을 출력하는 메서드
	static int dvlp_Overcalc();

	// 에디션의 종류를 출력하는 정적 메서드
	static int Editions();


	static void *title(const char *pszTitle);

private:
	// Overcalc 사용 언어. 1은 한국어, 2는 영어
	inline static int language{1};

	// Overcalc의 명예점수
	inline static int honor;

	// 이스터 에그의 접근 가능 여부
	inline static int easter_egg{0};

};

