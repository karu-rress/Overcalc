#include "stdafx.h"
#include "BDoll.h"
#include "MyFile.h"

CBDoll::CBDoll(int money)
	: money(money) , go_to(false) { }

// 집게를 출력
int CBDoll::jibgae()
{
	pus(0, 3);
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300);

	//집게바가 내려감
	pus(0, 2);//2초 쉼
	cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300); cls();
	cout << "\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n\t||\n"
		<< "\t||\n\t||\n\t||\n\t||\n\t||\n\t||" << endl;
	cout << "    =========\n    ||      ||\n    ||      ||" << endl; pus(0, -300);
	return 0;
}

// 인형뽑기 게임의 메뉴를 선택
int CBDoll::doll_menu(int& menu)
{
	int num;
	Print << BP_BAR << endl;
	Print << "\t\t\t\t\t\t\t인형 뽑기" << endl;
	Print << BP_BAR << endl;
	Print << STR("1. 인형뽑기 게임하기		현재 잔액=") << money << STR("원") << endl;
	Print << STR("2. 인형종류 확인하기") << endl;
	Print << STR("3. 인증키 입력\n") << STR("4. 나가기\n") << STR("> ") << endl;
	Get >> num;
	num = menu;
	return num * 100 + 1;
}

// 인형뽑기 게임 오버시 호출하는 함수
int CBDoll::gameover()
{
	CMyFile CMF;
	bool is_succeed(false);
	cls(); C_0C;

	const char *dolgm_ovr[]
	{ "당", "신", "은 ", "그", "렇", "게", ".", ".", ".", "\n", "\'", "거", "지", "\'", "가 ", "되", "고 ", "말", "았", "다", ".", ".", ".", ".\n" };

	for (auto &charact : dolgm_ovr)	
		cout << charact; pus(0, 2);
	
	// "Basic"버전의 "인형뽑기"게임에서, false (졌다)했다!
	CMF.WriteGameLog("Basic", "인형뽑기", false, is_succeed);

	if (is_succeed) return 1;

	return 0;
}

// 인형뽑기 게임과정
int CBDoll::Doll_Game()
{
	cls(); system("color 2f");
	cout <<"인형을 뽑습니다...1000원이 소비됩니다..."  << endl;
	money -= 1000;
	cout << "현재 잔액은 " << money << "원입니다." << endl;

	// 집게 호출!!
	jibgae();

	// 1부터 36까지의 값을 보관
	srand(static_cast <int> (time(NULL)));
	

	switch (int random{rand() % 35 + 1}; random)
	{
	case 1: [[fallthrough]];
	case 7: cout << "곰인형을 뽑았습니다.\n1000원을 벌었습니다." << endl;	money += bear;	pus(1); break;
	case 2: [[fallthrough]];
	case 10: cout << "라바 인형을 뽑았습니다.\n2000원을 벌었습니다." << endl;					money += lava;	pus(1); break;
	case 22: [[fallthrough]];
	case 20: cout << "지방이 인형을 뽑았습니다.\n3000원을 벌었습니다." << endl;			money += jibang;	pus(1); break;
	case 19: cout << "심슨 인형을 뽑았습니다.\n5000원을 벌었습니다." << endl;				money += simpsons;	pus(1); break;
	case 12: cout << "왕 곰인형을 뽑았습니다.\n현재 잔액이 두배로 증가됩니다." << endl;	money *= big_bear;			pus(1); break;
	case 6: cout << "축하합니다!\n복권을 뽑았습니다.\n현재 잔액이 10배로 증가합니다!" << endl; money *= lotto; pus(1); break;
	case 31: cout << "똥 인형을 뽑았습니다.\n3000원을 잃었습니다." << endl;					money += ddong;	pus(1); break;
	case 4: C_0C; cout << "사탄의 인형을 뽑았습니다.\n모든 재산을 잃었습니다!!" << endl;	money = satan;			pus(1); break;
	default: cout << "이런.....\n아무것도 뽑지 못했습니다......" << endl; pus(1); break;
	}
	cls();
	return random;
}


// 인형의 종류를 보여주는 메서드
int CBDoll::kind_of_dolls()
{
	cout << "1. 곰인형 : 잔액을 1000원 추가합니다.\n" << "2. 라바 인형 : 잔액을 2000원 추가합니다." << endl;
	cout << "3. 지방이 인형 : 잔액을 3000원 추가합니다.\n" << "4.심슨 인형 : 잔액을 5000원 추가합니다." << endl;
	cout << "5. 왕 곰인형 : 잔액을 2배로 증가시킵니다.\n" << "6. ????? : 잔액을 10배로 증가시킵니다." << endl;
	cout << "7. 똥 인형 : 잔액을 3000원 감소시킵니다.\n" << "8. 사탄의 인형 : 잔액을 0으로 만듭니다." << endl;
	pus(1); cls();
	return 0;
}


// 인형뽑기 게임의 인증키 입력을 담당하는 메서드
int CBDoll::Doll_key()
{
	std::string key;
	constexpr char *Key[2]{ "Overcalc", "AllenNa" };

	// 키 인증을 시도한 적이 없으면 키 시도 횟수를 초기화한다.
	if (DidKey[0] == false)
		HowManyKey[0] = 0;

	if (DidKey[1] == false)
		HowManyKey[1] = 0;

	cout << "인증키를 입력하세요 : ";
	cin >> key;

	if (key == Key[0])
	{
		if (HowManyKey[0] == F) {
			cout << "인증키가 확인되었습니다. 현재 잔액이 늘어납니다." << endl;
			money += 7000; DidKey[0] = true; HowManyKey[0]++;

			return 1;
		}

		else 
			cout << "아니 이것이 어디서 인증키를 한번 더쓰려고!!!" << endl;

		HowManyKey[0]++; pus(1); cls();

		return EOF;
	}
	else if (key == Key[1])
	{
		if (HowManyKey[1] == F) {
			cout << "인증키가 확인되었습니다. 현재 잔액이 늘어납니다." << endl;
			money += 20000; DidKey[1] = true; HowManyKey[1]++;

			return 1;
		}
		else { cout << "아니 이것이 어디서 인증키를 한번 더쓰려고!!!" << endl; }
		HowManyKey[1]++; pus(1); cls();

		return EOF;
	}

	else { cout << "얘! 그런 인증키는 없단다..."; pus(1); }
	return EOF;
}

// 인형뽑기 게임이 끝나기 직전 게임을 정리하고 초기화한다.
int CBDoll::Release()
{
	money = 5000;
	DidKey[0] = false;
	DidKey[1] = false;
	HowManyKey[0] = 0;
	HowManyKey[1] = 0;

	try
	{
		if (money != 5000)
			throw false;

		if (DidKey[0] != false)
			throw false;

		if (DidKey[1] != false)
			throw false;

		if (HowManyKey[0] != 0)
			throw false;

		if (HowManyKey[0] != 0)
			throw false;
	}
	catch (bool)
	{
		return EOF;
	}

	return 0;
}
