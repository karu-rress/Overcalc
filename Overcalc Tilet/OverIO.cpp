#include "stdafx.h"
#include "OverIO"

namespace Overcalc
{
	COverIO IOsys;
}

[[noreturn]] void Overcalc::CFileIO::ReadTopin(void) throw(bool)
{
	RWData.open(L"OverTopin.Overcalc", std::ios_base::in | std::ios_base::binary);

	if (RWData.is_open())
		RWData >> OData.Topin, RWData.close();

	else
		throw false;

	ReadEdition();
}

[[noreturn]] void Overcalc::CFileIO::ReadEdition(void) throw(bool)
{
	RWEdition.open(L"OverEdition.Overcalc", std::ios_base::in | std::ios_base::binary);

	if (RWEdition.is_open())
		RWEdition >> OData.Edition, RWEdition.close();

	else
		throw false;

	ReadLogPrint();
}

[[noreturn]] void Overcalc::CFileIO::ReadLogPrint(void) throw(bool)
{
	RWLogPrint.open(L"OverLogPrint.Overcalc", std::ios_base::in | std::ios_base::binary);

	if (RWLogPrint.is_open())	
		RWLogPrint >> LogPrint, RWLogPrint.close();
	
	else
		throw false;
}

[[nodiscard]] int Overcalc::CFileIO::ReturnEdition(void)
{
	return EditionArr[OData.Edition - 1];
}

[[noreturn]] void Overcalc::CFileIO::WriteULog(void)
{
	WriteLog.open(L"OverUserLog.log", std::ios_base::app);
	int i(0);
	for (auto iter : OData.ULogList)
		WriteLog << iter << std::endl, ++i;

	while (i != 0)
		OData.ULogList.pop_back(), --i;
	WriteLog.close();
}

[[noreturn]] void Overcalc::CFileIO::WriteGameLog(const wchar_t * Edition, const wchar_t * Game, bool Did_Win)
{
	std::unique_ptr<std::wstring> LogLine{std::make_unique<std::wstring>(IOsys.Date())};
	*LogLine = *LogLine + L"\t\t" + Edition + L"버전 " + Game;
	*LogLine += (Did_Win == true) ? L"승리" : L"패배";

	RWGameLOG.open(L"OverGame.log", std::ios_base::app);

	try
	{
		if (RWGameLOG.is_open())
		{
			RWGameLOG << LogLine->c_str() << std::endl;
			RWGameLOG.close();
			++LogPrint; return;
		}
		else    throw false;
	} // try
	catch (bool)  {   }
}

[[deprecated("Not prepared")]] [[nodiscard]] std::list<std::wstring> Overcalc::CFileIO::ReadGameLog(void)
{
	try
	{	
		std::list<std::wstring> LogList;
		if (LogPrint == 0) throw false;

		RWGameLOG.open(L"OverGame.log", std::ios_base::app);

		std::wstring GameLog;
		GameLog.reserve(50);
		for (int i = 0; i < LogPrint; ++i)
		{
			std::getline(RWGameLOG, GameLog);
			LogList.push_back(GameLog);
			GameLog.clear();
		}
		return LogList;
	}
	catch (bool)
	{
		std::list<std::wstring> temp = { L"No Data!" };
		return temp;
	}
}

Overcalc::COverIO::COverIO()
{
	SetCodePage(CP::Korean);
	std::locale::global(std::locale("kor"));

	SendMail();
	Var auto nInput{0}, Edition{0};
	Var bool is_button_on_start{true};
	
	BootScr(L"                               >> 시작하기 <<                                              종료");
	
	try 
	{
		File_.ReadTopin();
		Edition = File_.ReturnEdition();
	}
	catch (bool) 
	{
		Edition = -1;
	}

	while (true)
	{
		switch (is_button_on_start) 
		{
			case true: BootScr(L"                               >> 시작하기 <<                                              종료      "); break;
			case false: BootScr(L"                                  시작하기                                              >> 종료 << "); break;
		} // switch (is_button_on_start) 
		GetKey(nInput);
		if (nInput == KEY::Arrow || nInput == KEY::Fn) 
		{
			GetKey(nInput);
			switch (nInput) 
			{
				case 72: [[fallthrough]];
				case 75: if (is_button_on_start == true) { break; } 
						 is_button_on_start = true; break;
				case 80: [[fallthrough]];
				case 77: if (is_button_on_start == false) { break; } 
						 is_button_on_start = false; break;
			} // switch (nInput) 
		} // if (nInput == KEY::Arrow || nInput == KEY::Fn) 

		else if (nInput == KEY::Enter)
		{
			switch (is_button_on_start)
			{
				case true: return;
				case false: OData.exit = true; return;
			} // switch (is_button_on_start)
		} // else if (nInput == KEY::Enter)
	} // while (true)
}

[[nodiscard]] Cstr Overcalc::COverIO::Date()
{
	OData.Now = time(nullptr);
	localtime_s(&OData.tstruct, &OData.Now);
	std::wcsftime(OData.DateBuf, sizeof(OData.DateBuf), L"%F    %T", &OData.tstruct);
	return OData.DateBuf;
}
