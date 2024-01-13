#pragma once
#include "OverStd.h"
class CBkababo : public COverStd
{
private:
	String &kaba;				//가위바위보	
	integer random;						//컴퓨터와의 가위바위보 랜덤값
public:
	CBkababo(String &rkaba, integer &rjumsu);
	~CBkababo();

	integer jumsu;					//가위바위보의 점수

	integer menu;

	// 가위바위보 게임의 메뉴를 출력하는 메서드
	integer Print_Menu();

	// 가위바위보 게임의 하는 방법을 출력하는 메서드
	void HowToPlay();



	// 메뉴를 호출하는 메서드
	int Call_menu();

private:
	// 중첩된 문에서 이중 탈출을 해줄수 있게 해주는 인스턴스
	int breakX2;

	// 가위바위보에서 사용자가 가위를 선택했을때 출력되는 메서드
	integer kababo_ka();

	// 가위바위보 게임에서 사용자가 바위를 선택했을 경우 출력하는 메서드
	integer kababo_ba();

	// 가위바위보 게임에서 사용자가 보를 선택했을 경우 출력하는 메서드
	integer kababo_bo();
};

