#ifndef __date
#define __date
#include <iostream>
#include <string>
#include <fstream>

#include "GlobalConsts.h"
#include "Exception.h"
using namespace std;
const int MAX_NUM_OF_DAYS = 31;
const int MAX_NUM_OF_MONTHS = 12;
const int MIN_YEAR_NUMBER = 1;
const int MIN_MONTH_NUMBER = 1;
const int MIN_DAY_NUMBER = 1;
class Date
{
public:
	Date(int day=MIN_DAY_NUMBER, int month=MIN_MONTH_NUMBER, int year=MIN_YEAR_NUMBER)throw(Exception&);
	Date(const Date& date);
	Date(ifstream& in);

	bool setDay(const int _day);
	bool setMonth(const int _month);
	bool setYear(const int _year);
	const int getDay()const;
	const int getMonth()const;
	const int getYear()const;
 ostream & toOs(ostream & os)const;

	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::ifstream& operator>>(std::ifstream& in,  Date& date);

private:
	int day;
	int month;
	int year;

};

class DateException:public Exception
{
public:
	virtual void DateException::show() const;

};
#endif