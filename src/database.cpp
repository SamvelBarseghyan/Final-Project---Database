#include "database.h"
#include <algorithm>

void Database::Add(const Date& date, const string& event)
{
	if (std::count(begin(_storage[date]), end(_storage[date]), event) == 0)
		_storage[date].push_back(event);
}

void Database::Print(ostream& stream) const
{
	for (const auto& [date, event_vec] : _storage)
	{
		for (const auto& event : event_vec)
		{
			stream << date << " " << event;
		}
	}
}

string Database::Last(const Date& date) const
{
	auto it = std::lower_bound(begin(_storage), end(_storage), date);
	if (it == begin(_storage))
	{
		if (it->first == begin(_storage)->first)
		{
			return *(end(it->second) - 1);
		}
		else
		{
			throw std::invalid_argument("Invalid value of Date!");
		}
	}
	else if (it == end(_storage))
		throw std::invalid_argument("Invalid value of Date!");
	else
	{

	}
//    1 2 3 4 5 6
//      |
//   lower(2)

//    1 3 3 4 5 6
//      |
//   lower(2)

//    1 2 3 4 5 6
//    |
// lower(0)
}
