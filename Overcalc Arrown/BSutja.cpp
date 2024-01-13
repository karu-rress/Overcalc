#include "stdafx.h"
#include "BSutja.h"


CBSutja::CBSutja()
	: gold(0), silver(0), bronze(0), menu(0), nansu(0), sido(0)
	, answ(0), other(0)
{
}


CBSutja::~CBSutja()
{
}


// 숫자 맞추기 게임을 정리시키는 메서드
int CBSutja::Release()
{
	this->gold = 0;
	this->silver = 0;
	this->bronze = 0;

	try
	{
		if (!(gold == 0 && silver == 0 && bronze == 0))
			throw false;
	}
	catch (bool)
	{
		return EOF;
	}
	return 0;
}


// 메뉴를 출력하고 입력받는 메서드
int CBSutja::PrintMenu()
{
	cls();
	_tcout << BP_BAR << endl;
	_tcout << STR("\t\t숫자 맞히기") << endl;
	_tcout << STR("금메달 개수 : ") << this->gold << STR("은메달 개수 : ") << silver << STR("동메달 개수 : ") << bronze << endl;
	_tcout << BP_BAR << endl;
	_tcout << STR("1. 플레이 방법") << endl;
	_tcout << STR("2. 게임하기-난이도 쉬움(EASY)") << endl;
	_tcout << STR("3. 게임하기-난이도 보통(NORMAL)") << endl;
	_tcout << STR("4. 게임하기-난이도 어려움(HARD)") << endl;
	_tcout << STR("5. 게임하기-클리어 불가능(IMPOSSIBLE)") << endl;
	_tcout << STR("6. 금메달을 명예점수로 교환") << endl;
	_tcout << STR("7. 은메달을 금메달로 교환") << endl;
	_tcout << STR("8. 동메달을 은메달로 교환") << endl;
	_tcout << STR("9. 메인으로 가기") << endl;
	_tcout << BP_BAR << endl;
	_tcout << STR("> ");
	_tcin >> menu;
	return 0;

}

// menu인스턴스의 값에 따라 메뉴를 호출하는 매서드
int CBSutja::CallMenu()
{
	cls();
	switch (menu)
	{
	case 1: HowToPlay();			break;
	case 2: Easy();						break;
	case 3: Normal();					break;
	case 4: Hard();						break;
	case 5: Imposible();				break;
	case 6: MedalExchange(1);	break;
	case 7: MedalExchange(2);	break;
	case 8: MedalExchange(3);	break;
	case 9: return ESCAPE;
	default: _tcout << STR("숫자 모르니?"); pus(); break;
	}
	return 0;
}


// 게임 방법을 설명하는 메서드
int CBSutja::HowToPlay()
{
	cls();
	const character *arrays1[] {
		STR("이"), STR("지"), STR("모"), STR("드"), STR("에"), STR("서"), STR("는"), STR(" "), STR("1"), STR("~"), STR("9"), STR("사"), STR("이"), STR("의"),
		STR(" "), STR("숫"), STR("자"), STR("를"), STR(" "), STR("맞"), STR("추"), STR("면"),  STR("\n"), STR("이"), STR("기"), STR("게"), STR(" "), STR("되"), STR("며"), STR(",  "),
		STR("동"), STR("메"), STR("달"), STR(" "), STR("하"), STR("나"), STR("를"), STR(" 얻"), STR("습"), STR("니"), STR("다"), STR("."), STR("\n"),
		STR("숫"),  STR("자"), STR("를"), STR(" "), STR("맞"), STR("추"), STR("는"), STR(" 횟"), STR("수"), STR("엔"), STR(" 제"), STR("한"), STR("이"), STR(" 없"), STR("습"),
		STR("니"), STR("다"), STR("."), STR("\n")
	};
	const character *arrays2[] {
		STR("노"), STR("멀"), STR("모"), STR("드"), STR("에"), STR("서"), STR("는"), STR(" 1"), STR("1"), STR("~"), STR("9"),
		STR("9"), STR("사"), STR("이"), STR("의"), STR(" "), STR("숫"), STR("자"), STR("를"), STR(" "), STR("맞"), STR("추"), STR("면"),  STR("\n"), STR("이"), STR("기"),
		STR("게"), STR(" "), STR("되"), STR("며"), STR(",  "),
		STR("은"), STR("메"), STR("달"), STR(" "), STR("하"), STR("나"), STR("를"), STR(" 얻"), STR("습"), STR("니"), STR("다"), STR("."), STR("\n"),
		STR("숫"),  STR("자"), STR("를"), STR(" "), STR("맞"), STR("추"), STR("는"), STR(" 횟"), STR("수"), STR("는"), STR("1"), STR("0"), STR("0"), STR("번"), STR(" 제"),
		STR("한"), STR("이"), STR(" 있"), STR("습"), STR("니"), STR("다"), STR(".\n")
	};
	const character *arrays3[] {
		STR("하"), STR("드"), STR("모"), STR("드"), STR("에"), STR("서"), STR("는"), STR(" 1"), STR("1"), STR("1"), STR("~"), STR("9"),
		STR("9"), STR("9"), STR("사"), STR("이"), STR("의"), STR(" "), STR("숫"), STR("자"), STR("를"), STR(" "), STR("맞"), STR("추"), STR("면"),  STR("\n"), STR("이"), STR("기"),
		STR("게"), STR(" "), STR("되"), STR("며"), STR(",  "),
		STR("금"), STR("메"), STR("달"), STR(" "), STR("하"), STR("나"), STR("를"), STR(" 얻"), STR("습"), STR("니"), STR("다"), STR("."), STR("\n"),
		STR("숫"),  STR("자"), STR("를"), STR(" "), STR("맞"), STR("추"), STR("는"), STR(" 횟"), STR("수"), STR("는"), STR("5"), STR("0"), STR("번"), STR(" 제"),
		STR("한"), STR("이"), STR(" 있"), STR("습"), STR("니"), STR("다"), STR(".\n")
	};
	const character *arrays4[] {
		STR("임"), STR("파"), STR("서"), STR("블"), STR("모"), STR("드"), STR("에"), STR("서"), STR("는"), STR(" 1"), STR("1"), STR("1"), STR("1"), STR("1"), STR("~"), STR("9"),
		STR("9"), STR("9"), STR("9"), STR("9"), STR("사"), STR("이"), STR("의"), STR(" "), STR("숫"), STR("자"), STR("를"), STR(" "), STR("맞"), STR("추"), STR("면"),  STR("\n"), STR("이"), STR("기"),
		STR("게"), STR(" "), STR("되"), STR("며"), STR(",  "),
		STR("금"), STR(", "), STR("은"), STR(", "), STR("동"), STR("메"), STR("달"), STR("들"), STR("을"), STR(" 각"), STR("각 "), STR("하"), STR("나"), STR("씩"), STR(" 얻"), STR("습"), STR("니"), STR("다"), STR("."), STR("\n"),
		STR("숫"),  STR("자"), STR("를"), STR(" "), STR("맞"), STR("추"), STR("는"), STR(" 횟"), STR("수"), STR("는"), STR("2"), STR("5"), STR("번"), STR(" 제"),
		STR("한"), STR("이"), STR(" 있"), STR("습"), STR("니"), STR("다"), STR(".\n")
	};

	for (auto &n : arrays1)
		_tcout << n; pus(0, -50);
	pus(0, 2);

	for (auto &n : arrays2)
		_tcout << n; pus(0, -50);
	pus(0, 2);

	for (auto &n : arrays3)
		_tcout << n; pus(0, -50);
	pus(0, 2);

	for (auto &n : arrays4)
		_tcout << n; pus(0, -50);
	pus(0, 2);

	return 1;
}

// 숫자 맞추기의 이지 모드를 수행하는 비공개 매서드
int CBSutja::Easy()
{
	srand(static_cast <unsigned int> (time(NULL)));
	nansu = rand() % 8 + 1; cls();

	for (sido = 1; ; sido++)
	{
		cout << "1~9중 맞을 것 같은 숫자를 입력하세요 : ";
		cin >> answ;
		if (answ == nansu)
		{
			if (sido == 1)
				cout << "한번에 맞히다니! 사람이야?" << endl << "어쨌든 동메달 한개를 획득하셨습니다!" << endl;

			else
				cout << sido << "번의 시도 끝에 정답을 맞혔습니다! " << endl << "동메달 한개를 획득하셨습니다." << endl;
			bronze++, pus(); break;
		}

		else if (answ > nansu)
			cout << answ << "보다 작은 수입니다." << endl;

		else if (answ < nansu)
			cout << answ << "보다 큰 수입니다." << endl;
	}
	return 0;
}


// 숫자맞추기의 노말모드를 수행하는 비공개 메서드
int CBSutja::Normal()
{
	srand(static_cast <unsigned int> (time(NULL)));
	nansu = rand() % 88 + 11; cls();

	for (sido = 1; sido < 100; sido++) {
		cout << "11~99중 맞을 것 같은 숫자를 입력하세요 : ";
		cin >> answ;
		if (answ == nansu) {
			if (sido == T)
				cout << "한번에 맞히다니! 사람이야?\n어쨌든 은메달 한개를 획득하셨습니다!" << endl;
			else
				cout << sido << "번의 시도 끝에 정답을 맞혔습니다! " << endl << "은메달 한개를 획득하셨습니다." << endl;
			silver++, pus(); break;
		}
		else if (answ > nansu)
			cout << answ << "보다 작은 수입니다." << endl;
		else if (answ < nansu)
			cout << answ << "보다 큰 수입니다." << endl;
	}
	if (sido >= 100) {
		cout << "이런...기회를 다 썼습니다." << endl; pus(1);
	}
	return 0;
}


// 숫자맞추기의 하드모드를 수행하는 비공개 메서드
int CBSutja::Hard()
{
	srand(static_cast <unsigned int> (time(NULL)));
	nansu = rand() % 888 + 111;
	cls();

	for (sido = 1; sido < 50; sido++)
	{
		cout << "111~999중 맞을 것 같은 숫자를 입력하세요 : ";
		cin >> answ;
		if (answ == nansu)
		{
			if (sido == 1)
				cout << "한번에 맞히다니! 사람이야?\n어쨌든 금메달 한개를 획득하셨습니다!" << endl;
			else
				cout << sido << "번의 시도 끝에 정답을 맞혔습니다!\n" << "금메달 한개를 획득하셨습니다." << endl;
			gold++, pus(); break;
		}
		else if (answ > nansu)
			cout << answ << "보다 작은 수입니다." << endl;
		else if (answ < nansu)
			cout << answ << "보다 큰 수입니다." << endl;
	}
	if (sido >= 50) {
		cout << "이런...기회를 다 썼습니다." << endl; pus();
	}
	return 0;
}


// 숫자맟추기 게임에서 임파서블 모드를 수행하는 비공개 메서드
int CBSutja::Imposible()
{
	srand(static_cast <unsigned int> (time(NULL)));
	nansu = rand() % 88888 + 11111; cls();

	for (sido = 0; sido < 25; sido++)
	{
		std::cout << "11111~99999중 맞을 것 같은 숫자를 입력하세요 : ";
		cin >> answ;

		if (answ == nansu)
		{
			if (sido == 1)
				_tcout << STR("한번에 맞히다니! 당신은 신이야!\n어쨌든 금, 은, 동메달 하나씩 획득하셨습니다!") << endl;
			else
				std::cout << sido << "번의 시도 끝에 정답을 맞혔습니다!\n금, 은, 동메달을 하나씩 획득하셨습니다." << endl;
			gold++; silver++; bronze++; pus(); break;
		}

		else if (answ > nansu)
			std::cout << answ << "보다 작은 수입니다." << endl;

		else if (answ < nansu)
			std::cout << answ << "보다 큰 수입니다." << endl;
	}

	if (sido >= 25) {
		std::cout << "이런...기회를 다 썼습니다." << endl; pus(1);
	}
	return 0;
}


// 메달을 바꿀때 사용하는 비공개 메서드
int CBSutja::MedalExchange(int WhatsMedal)
{
	switch (WhatsMedal)
	{
	case 1:
		if (gold < 3)
		{
			std::cout << "교환에 필요한 금메달이 부족합니다.\n금메달은 적어도 3개이상 필요합니다." << endl;
			pus(1); return EOF;
		}

		std::cout << "금메달을 명예점수로 교환합니다. "; pus(1);
		honor += gold / 3; other = gold % 3;
		std::cout << "성공적으로 교환하였습니다.\n남은 금메달은 " << other << "개 입니다." << endl;
		gold = other;
		pus(1); return WhatsMedal;

	case 2:
		if (silver < 5) {
			std::cout << "교환에 필요한 은메달이 부족합니다. \n은메달은 적어도 5개이상 필요합니다." << endl;
			pus(1); return EOF;
		}

		std::cout << "은메달을 금메달로 교환합니다. "; pus(1);
		gold += (silver / 5); other = silver % 5;
		std::cout << "성공적으로 교환하였습니다.\n남은 은메달은 " << other << "개 입니다." << endl;
		silver = other;
		pus(1); return WhatsMedal;

	case 3:
		if (bronze < 10) {
			std::cout << "교환에 필요한 동메달이 부족합니다. \n동메달은 적어도 10개이상 필요합니다.\n";
			pus(1); return EOF;
		}

		std::cout << "동메달을 은메달로 교환합니다. "; pus(1);
		silver += bronze / 10; other = bronze % 10;
		std::cout << "성공적으로 교환하였습니다.\n남은 ,동메달은 " << other << "개 입니다." << endl;
		bronze = other;
		pus(1); return WhatsMedal;
	}
	return 0;
}
