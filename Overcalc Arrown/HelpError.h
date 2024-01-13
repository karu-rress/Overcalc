#pragma once

class CHelpError
{
	//문제해결에서 도움말로 탈출하는 경로를 담는 인스턴스
	bool back_to_help;

	//도움말의 메뉴를 담고있는 인스턴스
	int HM;

	//문제해결의 메뉴를 담고있는 인스턴스
	int EM;

public:

	CHelpError();
	~CHelpError();

	// Basic 버전의 도움말을 출력하는 메서드
	int PrintHelp();

	// Baisc 버전의 메뉴를 선택 및 출력하는 메서드
	int SelectPrintHelp();
};

