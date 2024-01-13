#pragma once
#include "stdafx.h"
#define VER L"Tilet"

#pragma region using_type

	///////////                               WIN64                      ////////

	#ifdef _WIN64

		using Int = long long;
		using Uint = unsigned long long;
		using Time = __time64_t;

	#elif defined( _WIN32) //   ^^ _WIN64  ^^  |   v v _WIN32  v v   //

		using Int = int;
		using Uint = unsigned int;
		using Time = __time32_t;

	#endif // _WIN64

	using Cstr = const wchar_t *;


// using_type
#pragma endregion 


#define BASIC
#define PRO

////////                     MACRO FOR DEBUG               //////////

#if (IS_DEBUG == 1)

	//1�̶�� �� ����ġ�� �����鼭
	#define DEBUG										
	//DEBUG�� ���� �ǰ�
	#pragma message("����� DEBUG��ũ�ΰ� Ȱ��ȭ �Ǿ� �ֽ��ϴ�."

#else

	// 0�̶�� DEBUG�� ���� ���� �ʴ´�
	#ifdef DEBUG
		#undef DEBUG
	#endif  

#endif // IS_DEBUG == 1

#ifdef DEBUG

	// DEBUG�� ������ �Ǹ� �� ����ġ�� ������
	#define msgout(x) std::Cerr << L#x) << std::endl;
	// msgout��ũ�ΰ� �����Ѵ�

#else

	// �׷��Ƿ� msgout��ũ�ΰ� �ƹ��� ���ҵ� ���� �ʴ´�.
	#define msgout(x)

#endif // DEBUG

///                 MACRO FOR PROGRAMMING                ///

#define pthis (*this)													// (*this)
#define Var
#define print_only

#define ESCAPE_EDITION()		throw 0;

// ...

//////                                   VARIABLE                         /////
#ifdef _UNICODE
	constexpr wchar_t Square = 0x25A1U;
	constexpr wchar_t *Squares[7]{L"\u25a1", L"\u25a1", L"\u25a1\u25a1", L"\u25a1\u25a1\u25a1", L"\u25a1\u25a1\u25a1\u25a1", L"\u25a1\u25a1\u25a1\u25a1\u25a1", L"\u25a1\u25a1\u25a1\u25a1\u25a1\u25a1"};
#else
	constexpr unsigned wchar_t Square = 128;
#endif // _UNICODE

