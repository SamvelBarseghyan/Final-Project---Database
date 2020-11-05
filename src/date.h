#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using std::istream;
using std::ostream;

class Date {
public:
	Date(int, int, int);

	bool operator < (const Date&) const;
	bool operator > (const Date&) const;
	bool operator <= (const Date&) const;
	bool operator >= (const Date&) const;
	bool operator == (const Date&) const;
	bool operator != (const Date&) const;

	friend ostream& operator << (ostream&, const Date&);
private:
	int _year;
	int _month;
	int _day;
};

Date ParseDate(istream&);

#endif /* DATE_H_ */
