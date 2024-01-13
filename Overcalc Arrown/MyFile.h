#pragma once
#include "stdafx.h"
#include "OverStd.h"

typedef class CMyFile : public COverStd
{
	//명예점수를 읽는 입력 스트림
	_tifstream ReadData;

	//에디션을 읽는 입력 스트림
	_tifstream ReadEdition;

	// 로그 출력 횟수를 읽는 입력 스트림
	_tifstream ReadLogPrint;

	int Editions;

	// 로그파일을 쓰는 출력 스트림
	_tofstream WriteLog;

	//명예점수를 쓰는 출력 스트림
	_tofstream WriteData;

	//에디션을 쓰는 출력 스트림
	_tofstream WriteEdition;

	// 로그파일 출력 '횟수'를 쓰는 출력 스트림
	_tofstream WriteLogPrint;

	// 로그파일 출력 횟수
	int LogPrint;

	// TEST로그파일 출력
	static _tofstream WriteTest;

public:
	
	CMyFile(void);
	~CMyFile(void);

	int Read;

	// 명예점수를 읽는 함수
	// 읽기에 성공하면 true, 실패시 false 리턴
	bool Read1(void);

	// 에디션을 읽는 함수
	// 읽기에 성공하면 true, 실패시 false 리턴
	bool Read2(void);

	// LogPrint 횟수를 읽어오는 메서드
	bool Read3(void);

	// 저장된 에디션을 바탕으로 에디션의 값을 리턴하는 함수
	int Read4(void);

	// 로그파일에 게임로그를 출력하는 메서드
	bool WriteGameLog(const char* Edition, const char* Game, bool Did_Win, int return_succes = EOF);

	// 테스트 로그파일에 로그를 출력하는 메서드
	template <typename T1 = const _TCHAR*, typename T2 = const int>
	static bool WriteTESTLog(T1 NameOrFunc, T2 Event);

	template<>
	static bool WriteTESTLog(const _TCHAR *NameOrFunc, const _TCHAR *Event);

}CMF, *PSMF, &RCMF;
