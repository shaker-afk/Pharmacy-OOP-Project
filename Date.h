#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
	int day, month, year;
public:
	Date();
	Date(int, int, int);
	Date(const Date&);
	~Date();

	bool setday(int);
	bool setmonth(int);
	bool setyear(int);

	int get_day() const;
	int get_month() const;
	int get_year() const;

	void print()const;
};