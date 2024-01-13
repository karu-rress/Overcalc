#include "stdafx.h"
#include "OverUI"

void Overcalc::COverUI::SelectMenu(int &rMenu)
{
	Var int nInput(0), nMenu(rMenu);
	nInput = _getch();

	while (true)
	{
		if (nInput == KEY::Enter)
			rMenu = nMenu;

		else if (nInput == KEY::Esc)
			rMenu = -1;

		else if (nInput == KEY::Arrow || nInput == KEY::Fn)
		{
			nInput = _getch();

			switch (static_cast<KEY>(nInput))
			{
			case KEY::F1: rMenu = static_cast<int>(KEY::F1);
			case KEY::Arrow_Up: if (nMenu == 1) { IOsys.Alarm(); break; }
								--nMenu; break;
			case KEY::Arrow_Down: if (nMenu == 11) { IOsys.Alarm(); break; }
								  ++nMenu; break;
			default: break;
			} // switch (static_cast<KEY>(nInput))

		} // else if (nInput == 224 || nInput == 0)
	} // while (true)
}

int Overcalc::COverUI::RunBasic(void)
{
	try
	{
		Var std::vector<std::unique_ptr<Overcalc::CBasic> > Basic
		{
			// 각각의 원소들이 Overcalc::CBasic* 형태이다.
			std::make_unique<Overcalc::CBMenu1>(), std::make_unique<Overcalc::CBMenu2>(),
			std::make_unique<Overcalc::CBMenu3>(), std::make_unique<Overcalc::CBMenu4>(),
			std::make_unique<Overcalc::CBMenu5>(), std::make_unique<Overcalc::CBMenu6>(),
			std::make_unique<Overcalc::CBMenu7>(), std::make_unique<Overcalc::CBMenu8>(),
			std::make_unique<Overcalc::CBMenu9>(), std::make_unique<Overcalc::CBMenu10>(),
			std::make_unique<Overcalc::CBMenu11>()
		};

		Var int menu(1);
	
		try
		{
			while (true)
			{
				PrintMenu(*Basic[menu]);
				SelectMenu(menu);
				if (menu == -1) return 0;
				PlayMenu(*Basic[menu]); // CBMenu11에서 throw를 작성해야 Basic이 끊긴다.
			}
		}
		catch (int)
		{
			return 1;
		}

			IOsys.Flush_In();
	}
	catch (const std::bad_alloc &exp)
	{
		
	}
}

