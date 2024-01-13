#include "stdafx.h"
#include "Bkababo.h"


CBkababo::CBkababo(String &rkaba, integer &rjumsu)
	: menu(0), random(0), jumsu(rjumsu), kaba(rkaba)
	, breakX2(0)
{
}


CBkababo::~CBkababo()
{
}


// 가위바위보 게임의 메뉴를 출력하는 메서드
integer CBkababo::Print_Menu()
{
	C_0F; cls();
	Print << BP_BAR << endl;
	cout << "\t\t\t\t\t    가위바위보 게임(현재 점수=" << jumsu << ')' << endl;
	Print << BP_BAR << endl;
	cout << "1. 가장 먼저 읽으세요-게임 방법" << endl;
	cout << "2. 가위바위보 게임하기" << endl;
	cout << "3. 인생역전 가위바위보" << endl;
	cout << "4. 메인으로 돌아가기" << endl;
	Print << BP_BAR << endl;
	cout << "선택\\> ";
	cin >> this->menu;

	return this->menu;
}

// 가위바위보 게임의 하는 방법을 출력하는 메서드
void CBkababo::HowToPlay()
{
	C_75;
	cout << "\t\t게임 방법" << endl;
	cout << "게임을 시작하시면 가위, 바위, 보 중에 하나를 선택합니다." << endl;
	cout << "이기거나 지면 각각 1점을 얻거나 잃습니다." << endl;
	cout << "인생 역전은 승리시 10점을 얻지만 패배시 점수를 다 잃습니다." << endl;
	cout << "점수가 -3이 되면 당신의 패배로 게임이 끝납니다." << endl;
	cout << "점수가 10이 되면 당신이 이깁니다." << endl;
	cout << "메인으로 돌아가기를 누르시면 메인으로 갑니다." << endl;
	cout << "준비가 되셨다면 엔터키를 눌러주세요." << endl;
	cout << "행운을 빕니다!" << endl;
	pus(); cls();
}

integer CBkababo::kababo_ka()
{
	Print << "\n당신의 선택은 \"가위\"입니다." << endl; pus(0, 2);
	cout << "가위,\t";  pus(0, 1); cout << "바위,\t";  pus(0, 1); cout << "보!\t";  pus(0, 1); cout << endl << endl;
	srand(CAST(int, time(NULL))); 
	random = rand() % 2 + 1;

	switch (random)
	{
	case 1: cout << "당신 : 가위\n컴퓨터 : 보\n\n" << "당신이 이겼습니다. 1점을 획득하셨습니다."; ++jumsu; break;
	case 2: cout << "당신 : 가위\n컴퓨터 : 가위\n\n" << "이런...비겼습니다."; break;
	case 3: cout << "당신 : 가위\n컴퓨터 : 보\n\n" << "운이 없었나?.... 졌습니다. 1점을 잃었습니다."; --jumsu; break;
	}

	return jumsu;
}

// 가위바위보 게임에서 사용자가 바위를 선택했을 경우 출력하는 메서드
integer CBkababo::kababo_ba()
{
	cout << "\n당신의 선택은 \"바위\"입니다.\n" << endl; pus(0, 2);
	cout << "가위,\t"; pus(0, 1); cout << "바위,\t"; pus(0, 1); cout << "보!\t"; pus(0, 1); cout << endl << endl;
	srand(CAST(int, time(NULL)));
	random = rand() % 2 + 1;

	switch (random)
	{
	case 1: cout << "당신 : 바위\n컴퓨터 : 가위" << "\n\n당신이 이겼습니다. 1점을 획득하셨습니다."; jumsu++; break;
	case 2: cout << "당신 : 바위\n컴퓨터 : 바위" << "\n\n이런...비겼습니다."; break;
	case 3: cout << "당신 : 바위\n컴퓨터 : 보" << "\n\n운이 없었나?.... 졌습니다. 1점을 잃었습니다."; jumsu--; break;
	}

	random = 0;
	return jumsu;
}


// 가위바위보 게임에서 사용자가 보를 선택했을 경우 출력하는 메서드
integer CBkababo::kababo_bo()
{
	cout << "\n당신의 선택은 \"보\"입니다." << endl; pus(0, 2);
	cout << "가위,\t";  pus(0, 1); cout << "바위,\t";  pus(0, 1); cout << "보!\t";  pus(0, 1); cout << endl << endl;
	srand(CAST(int, time(NULL))); random = rand() % 2 + 1;

	switch (random)
	{
	case 1: cout << "당신 : 보\n컴퓨터 : 바위" << "\n\n당신이 이겼습니다. 1점을 획득하셨습니다."; jumsu++; break;
	case 2: cout << "당신 : 보\n컴퓨터 : 보" << "\n\n이런...비겼습니다."; break;
	case 3: cout << "당신 : 보\n컴퓨터 : 가위" << "\n\n운이 없었나?.... 졌습니다. 1점을 잃었습니다."; jumsu--; break;
	}

	return jumsu;
}


// 메뉴를 호출하는 메서드
int CBkababo::Call_menu()
{
	switch (menu)
	{
	case 1: this->HowToPlay();		return 1;
	case 2:
		cls(); _tcout << STR("가위, 바위, 보 중 하나를 입력하세요 : ");
		_tcin >> kaba;

		if (kaba == STR("가위"))
			kababo_ka();

		else if (kaba == STR("바위"))
			kababo_ba();

		else if (kaba == STR("보"))
			kababo_bo();

		else
			_tcout << STR("아니..가위바위보를 하라니까 뭘 입력한거야?") << endl;
		pus(); return 2;
	case 3:
		cls(); C_60;
		cout << "자...가위, 바위, 보 중에 하나를 입력하세요 : ";
		_tcin >> kaba;

		if (kaba == STR("가위"))
		{
			cout << "\n당신의 선택은 \"가위\"입니다.";
			pus(0, 2); cout << "가위...\t";
			pus(0, 2); cout << "바위...\t";
			pus(0, 2); cout << "보!\t" << endl << endl;
			pus(0, 2);

			srand(CAST(int, time(NULL)));
			random = rand() % 2 + 1;

			switch (random)
			{
			case 1: cout << "당신 : 가위\n컴퓨터 : 보" << endl << endl;
				cout << "당신이 이겼습니다!!!! 10점을 획득하셨습니다!";
				jumsu += 10; pus(); break;

			case 2: cout << "당신 : 가위\n컴퓨터 : 가위" << endl << endl;
				cout << "이런...비겼습니다. 5점을 잃었습니다...";
				jumsu -= 5; pus(); break;

			case 3: cout << "당신 : 가위\n컴퓨터 : 보" << endl << endl;
				cout << "운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...";
				jumsu -= 20; pus(); break;
			}
		}

		else if (kaba == STR("바위"))	//바위
		{
			cout << "\n당신의 선택은 \"바위\"입니다.";
			pus(0, 2); cout << "가위...\t";
			pus(0, 2); cout << "바위...\t" << endl << endl;
			pus(0, 2); cout << "보!\t"; pus(0, 2);

			srand(CAST(int, time(NULL)));
			random = rand() % 2 + 1;

			switch (random)
			{
			case 1:
				cout << "당신 : 바위\n컴퓨터 : 가위";
				cout << "\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!";
				jumsu += 10; pus(); break;

			case 2:
				cout << "당신 : 바위\n컴퓨터 : 바위";
				cout << "\n\n이런...비겼습니다. 5점을 잃었습니다...";
				jumsu -= 5; pus(); break;

			case 3:
				cout << "당신 : 바위\n컴퓨터 : 보" << endl << endl;
				cout << "운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...";
				jumsu -= 20; pus(); break;
			}
		}

		else if (kaba == STR("보"))
		{
			cout << "\n당신의 선택은 \"보\"입니다.";
			pus(0, 2); cout << "가위...\t";
			pus(0, 2); cout << "바위...\t";
			pus(0, 2); cout << "보!" << endl << endl; pus(0, 2);

			srand(CAST(int, time(NULL)));
			random = rand() % 2 + 1;

			switch (random)
			{
			case 1:
				cout << "당신 : 보\n컴퓨터 : 바위";
				cout << "\n\n당신이 이겼습니다!!!! 10점을 획득하셨습니다!";
				jumsu += 10; pus(); break;

			case 2:
				cout << "당신 : 보\n컴퓨터 : 보";
				cout << "\n\n이런...비겼습니다. 5점을 잃었습니다...";
				jumsu -= 5; pus(); break;

			case 3:
				cout << "당신 : 보\n컴퓨터 : 가위";
				cout << "\n\n운이 없었나?.... 졌습니다. 모든 점수를 잃었습니다...";
				jumsu -= 20; pus(); break;
			}
		}

		else 
			cout << "아니..가위바위보를 하라니까 뭘 입력한거야?"; pus(1);
		
		return 3;
	case 4: breakX2 = 1; break;
	default: Print << STR("똑바로 입력해!!!") << endl; pus(); return EOF;
	}
	if (breakX2 == 1) { breakX2 = 0; return ESCAPE; }
	return 0;
}

