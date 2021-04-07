#include <string>
#include "Exception.h"
#include <fstream>

#include "date.h"
using namespace std;

Date::Date(int day,int month,int year)throw(DateException&)
{
	if(day < MIN_DAY_NUMBER || day > MAX_NUM_OF_DAYS || month < MIN_MONTH_NUMBER || month>MAX_NUM_OF_MONTHS || year < MIN_YEAR_NUMBER)
	{
		throw DateException();
	}
	

		setDay(day);
		setMonth(month);
		setYear(year);
	
}

Date::Date(const Date& date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

Date::Date(ifstream & in)
{
	in >> *this;
}


bool Date::setDay(const int _day)
{
	day = _day;
	return true;
}
bool Date::setMonth(const int _month)
{
	month = _month;
	return true;
}
bool Date::setYear(const int _year)
{
	year = _year;
	return true;
}
const int Date::getDay()const
{
	return day;
}
const int Date::getMonth()const
{
	return month;
}
const int Date::getYear()const
{
	return year;
}

ostream & Date::toOs(ostream & os)const
{
 if (typeid(os) == typeid(ofstream))
	{
		os << day << " " << month << " " << year<<" ";
	}
	else
		os << "Date(DD\MM\YYYY): " << day << " \ " << month << " \ " << year;
	return os;
}

std::ostream & operator<<(std::ostream & os, const Date & date)
{
	return date.toOs(os);

}

std::ifstream & operator >> (std::ifstream& in, Date& date)
{
	string dd;
	string mm;
	string yyyy;
	in >> dd>> mm >> yyyy;

	date.setDay(atoi(dd.c_str()));
	date.setMonth(atoi(mm.c_str()));
	date.setYear(atoi(yyyy.c_str()));
	return in;
}

void DateException::show() const
{
	cout << "Date is invalid \n";
}
