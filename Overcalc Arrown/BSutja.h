#pragma once
typedef int Medal;

class CBSutja : public COverStd
{
public:
	CBSutja();
	~CBSutja();

private:

	// 메뉴를 담고있는 인스턴스
	int menu;

	// 금메달의 갯수를 저장하는 인스턴스
	Medal gold;

	// 은메달의 갯수를 저장하는 인스턴스
	Medal silver;

	// 동메달의 갯수를 저장하는 인스턴스
	Medal bronze;

	// 난수를 담고 있는 인스턴스
	int nansu;

	// 시도 횟수를 담고 있는 인스턴스
	int sido;

	// 입력값을 담고 있는 인스턴스
	int answ;

	// 메달 교환 후 남은 값을 담고 있는 인스턴스
	int other;

public:
	// 숫자 맞추기 게임을 정리시키는 메서드
	int Release();
	
	// 메뉴를 출력하고 입력받는 메서드
	int PrintMenu();

	// menu인스턴스의 값에 따라 메뉴를 호출하는 매서드
	int CallMenu();

	// 게임 방법을 설명하는 메서드
	int HowToPlay();

private:
	// 숫자 맞추기의 이지 모드를 수행하는 비공개 매서드
	int Easy();

	// 숫자맞추기의 노말모드를 수행하는 비공개 메서드
	int Normal();

	// 숫자맞추기의 하드모드를 수행하는 비공개 메서드
	int Hard();

	// 숫자맟추기 게임에서 임파서블 모드를 수행하는 비공개 메서드
	int Imposible();

	// 메달을 바꿀때 사용하는 비공개 메서드
	int MedalExchange(int WhatsMedal);

};

