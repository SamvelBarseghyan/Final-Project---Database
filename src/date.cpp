#include "date.h"
#include <tuple>
#include <string>
#include <iomanip>

using std::setw;
using std::setfill;
using std::to_string;
using std::make_tuple;
using std::logic_error;

Date::Date(int year, int month, int day)
{
	_year = year;
	if (month > 12 || month < 1)
		throw logic_error("Month value is invalid: " + to_string(month));
	_month = month;
	if (day > 31 || day < 1)
		throw logic_error("Day value is invalid: " + to_string(day));
	_day = day;
}

bool Date::operator < (const Date& date) const
{
	return make_tuple(_year, _month, _day) < make_tuple(date._year, date._month, date._day);
}
bool Date::operator > (const Date& date) const
{
	return make_tuple(_year, _month, _day) > make_tuple(date._year, date._month, date._day);
}
bool Date::operator <= (const Date& date) const
{
	return make_tuple(_year, _month, _day) <= make_tuple(date._year, date._month, date._day);
}
bool Date::operator >= (const Date& date) const
{
	return make_tuple(_year, _month, _day) >= make_tuple(date._year, date._month, date._day);
}
bool Date::operator == (const Date& date) const
{
	return make_tuple(_year, _month, _day) == make_tuple(date._year, date._month, date._day);
}
bool Date::operator != (const Date& date) const
{
	return make_tuple(_year, _month, _day) != make_tuple(date._year, date._month, date._day);
}

ostream& operator << (ostream& stream, const Date& date)
{
	stream << setw(4) << setfill('0') << date._year
		   << setw(2) << setfill('0') << date._month
		   << setw(2) << setfill('0') << date._day;
//	 stream << std::endl;
	return stream;
}

Date ParseDate(istream& date_stream)
{
	bool ok = true;

	int year;
	ok = ok && (date_stream >> year);
	ok = ok && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int month;
	ok = ok && (date_stream >> month);
	ok = ok && (date_stream.peek() == '-');
	date_stream.ignore(1);

	int day;
	ok = ok && (date_stream >> day);
	ok = ok && date_stream.eof();

	if (!ok) {
		throw logic_error("Wrong date format!");
	}
	return Date(year, month, day);
}
