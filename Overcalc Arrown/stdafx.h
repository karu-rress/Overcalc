// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <tchar.h>


//Standard C++ headers
#include <iostream>						// climits, cmath, cstdio, cstdlib, cstring 포함
#include <locale>							// string 포함
#include <fstream>
#include <sstream>

//Standard C headers for *.cpp
#include <ctime>
#include <clocale>

//Unicodes and Graphics
#include <Windows.h>
#include <conio.h>

#include <typeinfo>

#define Honor 9999
#define IS_DEBUG 1
#define IS_TEST 1
#define VER "tilet"

//#include "openssl\ossl_typ.h"
#include "OverHead.h"
#include "MyFile.h"
#include "BasicStd.h"
#include "BDoll.h"
#include "HelpError.h"
#include "OverStd.h"
#include "Bkababo.h"
#include "BCal.h"
#include "BSutja.h"
#include "easendmailobj.tlh"
#include "Overtuni.h"

#ifdef TEST
#define WriteTestLog CMF::WriteTESTLog
#else
#define WriteTestLog
#endif // TEST

using namespace std;