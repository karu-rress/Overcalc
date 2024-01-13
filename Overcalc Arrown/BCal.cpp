#include "stdafx.h"
#include "BCal.h"


CBCal::CBCal()
{
}


CBCal::~CBCal()
{
}

int CBCal::get_year(void)
{
	int year{-1};
	cout << "???? ???????? : ";
	cin >> year;
	return year;
}

int CBCal::get_day_code(int year)
{
	int day_code;
	double x1, x2, x3;
	x1 = (year - 1.) / 4.0;
	x2 = (year - 1.) / 100.;
	x3 = (year - 1.) / 400.;
	day_code = (year + CAST(int, x1) - CAST(int, x2) + CAST(int, x3)) % 7;
	return day_code;
}

int CBCal::get_leap_year(int year) const
{
	/*?????? 4?? ??????? 100?? ?????? ????, 400?? ??????? ???.*/
	if (((year % 4 == F) && (year % 100 != F)) || (year % 400 == F))
		return T;

	return F;
}

void CBCal::print_calendar(int year, int day_code, int leap)
{
	int days_in_month;		//?? ??? ??? ????? ??
	int day;							/* ?? ?? ??? ??? ????? ???? */
	int month;					// month = 1?? 1??, 2?? 2?? ??
	cout << "\t\t\t\t" << year;
	for (month = 1; month <= 12; month++)
	{
		switch (month)
		{
			/* print name and set days_in_month */
		case 1:		cout << "\n\n1??, January";			days_in_month = 31;						break;
		case 2:		cout << "\n\n2??, February";			days_in_month = leap ? 29 : 28;	break;
		case 3:		cout << "\n\n3??, March";			days_in_month = 31;						break;
		case 4:		cout << "\n\n4??, April";				days_in_month = 30;						break;
		case 5:		cout << "\n\n5??, May";				days_in_month = 31;						break;
		case 6:		cout << "\n\n6??, June";				days_in_month = 30;						break;
		case 7:		cout << "\n\n7??, July";				days_in_month = 31;						break;
		case 8:		cout << "\n\n8??, August";			days_in_month = 31;						break;
		case 9:		cout << "\n\n9??, September";		days_in_month = 30;						break;
		case 10:	cout << "\n\n10??, October";		days_in_month = 31;						break;
		case 11:	cout << "\n\n11??, November";	days_in_month = 30;						break;
		case 12:	cout << "\n\n12??, December";	days_in_month = 31;						break;
		}
		cout << "\n\n??(Sun)\t??(Mon)\t?(Tue)\t??(Wed)\t??(Thu)\t??(Fri)\t??(Sat)" << endl;

		for (day = 1; day < day_code + 1; day++)
			cout << "\t";

		for (day = 1; day <= days_in_month; day++)
		{
			cout << day;
			if ((day + day_code) % 7 > 0)
				cout << "\t";
			else if (day != days_in_month)
				cout << endl;
		}

		day_code = (day_code + days_in_month) % 7;
	}
}
