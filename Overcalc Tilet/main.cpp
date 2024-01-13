// ConsoleApplication3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

using Overcalc::IOsys;

int wmain()
{
	if (Overcalc::OData.is_exit() == true) return 0;

	Var Overcalc::COverUI UI;

	IOsys << Overcalc::Add_Log(L"미확인", L"Overcalc 시작");

	try
	{
		IOsys->ReadTopin();
	}
	catch (bool)
	{
		// Overcalc Starter
	}

	UI.RunBasic();
    return 0;
}

