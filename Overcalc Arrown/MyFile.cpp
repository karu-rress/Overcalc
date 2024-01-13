#include "stdafx.h"
#include "MyFile.h"
#include "OverStd.h"

CMyFile::CMyFile(void)
	: ReadData(STR("OverData.Overcalc")), ReadEdition(STR("OverEdition.Overcalc")), ReadLogPrint(STR("OverLog.Overcalc"))
	, Editions(0), LogPrint(0)
{
	int input, StartQuit(1);
	cls(); BootScr();
	switch (StartQuit)
	{
	case 1: Print << STR("				>> 시작하기 <<					종료") << endl << endl; break;
	case 2: Print << STR("				 시작하기 					 >> 종료 << ") << endl << endl; break;
	}
	
	END;

	try
	{
#pragma message("명예점수 읽는중")
		bool Chk = Read1();
		if (Chk == false)
			throw false;

#pragma message("에디션 읽는중")
		Chk = Read2();
		if (Chk == false)
			throw false;

		Chk = Read3();
		if (Chk == false)
			throw false;

		Chk = Read4();
		//		switch (Chk)
		//		{
		//		case 1: Read = 1;
		//		}
	}
	catch (bool)
	{
		Read = EOF;
	}
	while (true)
	{
		cur(0, 0);
		BootScr();
		switch (StartQuit)
		{
		case 1: Print << STR("                               >> 시작하기 <<                                              종료      ") << endl << endl; break;
		case 2: Print << STR("                                  시작하기                                              >> 종료 << ") << endl << endl; break;
		}
		input = _getch();
		if (input == 224 || input == 0)
		{
			input = _getch();
			switch (input)
			{
			case 75: if (StartQuit == 1) { break; } StartQuit -= 1; break;
			case 77: if (StartQuit == 2) { break; } StartQuit += 1; break;
			}
		}

		else if (input == 13)
		{
			switch (StartQuit)
			{
			case 1: return;
			case 2: exit(0);
			}
		}
	}
	
}


CMyFile::~CMyFile()
{
	WriteLogPrint.open(STR("OverLog.Overcalc"), ios_base::out | ios_base::binary);

	if (WriteLogPrint.is_open() != false)		//파일이 열렸으면...
	{
		// LogPrint를 출력
		WriteLogPrint << LogPrint;

		WriteLog.close();
	}
}

// 명예점수를 읽는 함수
// 읽기에 성공하면 true, 실패시 false 리턴
bool CMyFile::Read1(void)
{
	int &honor(COverStd::honor);
	try					//시도해라
	{
		if (ReadData.is_open() == true)		//열렸냐?
		{
			ReadData >> honor;					//명예점수 복구
			ReadData.close();							//파일 닫고
			return true;									//참 리턴
		}
		else
			throw false;									//아니라면
															//		|
	}															//		|
																//		|
	catch (bool) {										//		|
		return false;										//거짓을 리턴
	}
}

// 에디션을 읽는 함수
// 읽기에 성공하면 true, 실패시 false 리턴
bool CMyFile::Read2(void)
{	
	try
	{
		if (ReadEdition.is_open() != false)		//파일이 열렸으면...
		{
			ReadEdition >> Editions;				//...에디션 복구
			ReadEdition.close();							//후 파일 닫기
			return true;										//참 반환후 종료
		}

		else														//열리지 않았으면
			throw false;										//...
	}

	catch (bool) {
		return false;											//거짓 반환
	}
}

bool CMyFile::Read3(void)
{	
	try
	{
		if (ReadLogPrint.is_open() != false)		//파일이 열렸으면...
		{
			ReadLogPrint >> LogPrint;				//...로그파일 출력 횟수 복구
			ReadLogPrint.close();							//후 파일 닫기
			return true;										//참 반환후 종료
		}

		else														//열리지 않았으면
			throw false;										//...
	}

	catch (bool) {
		return false;											//거짓 반환
	}
}

// 저장된 에디션을 바탕으로 에디션의 값을 리턴하는 함수
int CMyFile::Read4(void)
{
	switch (Editions)
	{
	case 1: return 1;
	case 2: return 2;
	case 3: return 3;
	}
	return 0;
}

// 로그파일에 게임로그를 출력하는 메서드.
// 호출 및 출력시마다 로그파일 출력 횟수를 ++한다.
// 매개변수-
// 00-에디션을 입력한다
// 01-게임명을 입력한다
// 02-이긴 여부, 이기면 true, 지면 false
bool CMyFile::WriteGameLog(const char* Edition, const char* Game, bool Did_Win, int return_succes)
{
	// 문자열 로그 생성
	string LogLine; {
		// Jan 01 2000 
		LogLine += Date();

		// Jan 01 2000(Tab)(Tab)
		LogLine += "\t\t";

		// Jan 01 2000		Overcalc+
		LogLine += Edition;

		// Jan 01 2000		Overcalc+버전 
		LogLine += "버전 ";

		// Jan 01 2000		Overcalc+버전 테트리스
		LogLine += Game;

		// Jan 01 2000		Overcalc+버전 테트리스 게임
		LogLine += " 게임 ";


		if (Did_Win == true)
			LogLine += "승리";

		else
			LogLine += "패배";

	}
	WriteLog.open("OverGame.log", ios_base::app);

	try
	{
		if (WriteLog.is_open() != false)		//파일이 열렸으면...
		{
			// 생성된 문자열 로그를 const char *형식으로 전환하여 출력.
			WriteLog << LogLine.c_str();

			// 파일을 닫고 this->LogPrint를 1증가
			WriteLog.close();
			++this->LogPrint;

			// 매개변수와 리턴값을 true로,
			if (return_succes == EOF)
				return true;
			return_succes = true;
			return true;										//참 반환후 종료
		}

		else														//열리지 않았으면
			throw false;										//...
	}

	catch (bool) {

		if (return_succes == EOF)
			return false;											//거짓 반환
		return_succes = false;
		return false;
	}

	return false;
}

template <typename T1, typename T2>
bool CMyFile::WriteTESTLog(T1 NameOrFunc, T2 Event)
{

	_TCHAR buf[30];
	_itot_s(Event, buf, 10);

	CMyFile::WriteTest.open(STR("TestLog.log"), ios_base::out | ios_base::app);

	if (WriteTest.is_open() == false)
		return false;

	String strLog(COverStd::_tDate());
	strLog = strLog + STR("\t\t") + static_cast<const _TCHAR*>(NameOrFunc) + STR("\t\t") + buf;

	CMyFile::WriteTest << strLog.data();


	CMyFile::WriteTest.close();
	return true;

}


template<>
bool CMyFile::WriteTESTLog(const _TCHAR * NameOrFunc, const _TCHAR * Event)
{
	CMyFile::WriteTest.open("TestLog.log", ios_base::out | ios_base::app);

	if (WriteTest.is_open() == false)
		return false;

	String strLog(COverStd::_tDate());
	strLog = strLog + STR("\t\t") + static_cast<const _TCHAR*>(NameOrFunc) + STR("\t\t") + Event;

	CMyFile::WriteTest << strLog.data();

	CMyFile::WriteTest.close();
	return false;
}
