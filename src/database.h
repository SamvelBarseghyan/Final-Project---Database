#ifndef DATABASE_H_
#define DATABASE_H_

#include <map>
#include "date.h"
#include <vector>
#include <string>
#include <iostream>

using std::map;
using std::vector;
using std::string;
using std::ostream;

class Database {
public:
	void Add(const Date&, const string&);
	void Print(ostream&) const;
	string Last(const Date&) const;

	template<class LambdaFunction>
	int RemoveIf(LambdaFunction);

	template<class LambdaFunction>
	void Find(LambdaFunction) const;
private:
	map<Date, vector<string>> _storage;
};



#endif /* DATABASE_H_ */
