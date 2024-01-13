#pragma once
#include "BasicStd.h"
class CBCal : public CBasicStd
{
public:
	CBCal();
	~CBCal();

	int get_year(void);

	int get_day_code(int year);

	int get_leap_year(int year) const;

	void print_calendar(int year, int day_code, int leap);
};

