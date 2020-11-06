#ifndef TEST_RUNNER_H_
#define TEST_RUNNER_H_

#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>


//template <typename First, typename Second>
//std::ostream& operator << (std::ostream& out, const std::pair<First, Second>& p);

template <typename Collection>
std::string Join(const Collection& c, const std::string& d);

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& vi);

template <typename Key, typename Value>
std::ostream& operator << (std::ostream& out, const std::map<Key, Value>& m);

template <typename T>
std::ostream& operator << (std::ostream& out, const std::set<T>& s);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint);

void Assert(bool cond, const std::string& hint);


class TestRunner
{
public:
	TestRunner();
	~TestRunner();
	template<class TestFunction>
	void RunTest(TestFunction test_function, const std::string& test_function_name);
private:
	int fail_count;
};

#endif /* TEST_RUNNER_H_ */
