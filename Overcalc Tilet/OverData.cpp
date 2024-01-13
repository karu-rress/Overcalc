#include "stdafx.h"
#include "OverData"

namespace Overcalc 
{
	COverData OData;
	std::vector<wchar_t*> badwords
	{
		L"지랄", L"씨발", L"씨X", L"씨*", L"존나", L"개", L"새끼", L"존나", L"놈", L"병신"
	};
	HANDLE Overhdl { GetStdHandle(STD_OUTPUT_HANDLE) };
}
