#pragma once
#include "BasicStd.h"
#include "OverHead.h"

class CBDoll : public COverStd
{
	bool DidKey[2];						// 인증키 시도 횟수
	int HowManyKey[2];
	
	enum class price : int {
		bear = 1000,
		lava = 2000,
		jibang = 3000,
		simpsons = 5000,
		big_bear = 2,
		lotto = 10,
		ddong = -3000,
		satan = 0,
	};
	int money;
public:
	CBDoll(int);
	~CBDoll() = default;

													// goto문 대신 경로를 생성해줌
	bool go_to;

	// 집게를 출력
	int jibgae();

	// 인형뽑기 게임의 메뉴를 선택
	int doll_menu(int& menu);

	// 인형뽑기 게임 오버시 호출하는 함수
	int gameover();

	// 인형뽑기 게임과정
	int Doll_Game();

	// 인형의 종류를 보여주는 메서드
	int kind_of_dolls();

	// 인형뽑기 게임의 인증키 입력을 담당하는 메서드
	int Doll_key();

	// 인형뽑기 게임이 끝나기 직전 게임을 정리하고 초기화한다.
	int Release();
};