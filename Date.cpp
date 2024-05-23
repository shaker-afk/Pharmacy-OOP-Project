#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

Date::Date() {
	day = 1;
	month = 1;
	year = 2024;
}
Date::Date(int d, int m , int y) {
	setday(d);
	setmonth(m);
	setyear(y);
}
Date::Date(const Date& copy) {
	day = copy.day;
	month = copy.month;
	year = copy.year;
}
Date::~Date() {
}

bool Date::setday(int d) {
	if (d > 0 && d<=32)
	{
		day = d;
		return true;
	}
	else
	{
		day = 1;
		return false;
	}
}
bool Date::setmonth(int m) {
	if (m  >0 && m<=12)
	{
		month = m;
		return true;
	}
	else
	{
		month = 1;
		return false;
	}
}
bool Date::setyear(int y) {
	if (y >=2024)
	{
		year = y;
		return true;
	}
	else
	{
		year = 2024;
		return false;
	}
}

int Date::get_day()const {
	return day;
}
int Date::get_month() const{
	return month;
}
int Date::get_year() const{
	return year;
}

void Date::print() const{
	cout << day << "/" << month << "/" << year<<endl;
}
