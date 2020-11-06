  #include "test_runner.h"

//template <typename First, typename Second>
//std::ostream& operator << (std::ostream& out, const std::pair<First, Second>& p)
//{
	//return out << '(' << p.first << ", " << p.second << ')';
//}

template <typename Collection>
std::string Join(const Collection& c, const std::string& d)
{
	std::stringstream ss;
	bool first = true;
	for (const auto& i : c) {
		if (!first) {
			ss << d;
		}
		first = false;
		ss << i;
	}
	return ss.str();
}

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& vi)
{
	return out << '[' << Join(vi, ", ") << ']';
}

template <typename Key, typename Value>
std::ostream& operator << (std::ostream& out, const std::map<Key, Value>& m)
{
	return out << '{' << Join(m, ", ") << '}';
}

template <typename T>
std::ostream& operator << (std::ostream& out, const std::set<T>& s)
{
	return out << '{' << Join(s, ", ") << '}';
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint)
{
	if (t != u)
	{
		std::ostringstream os;
		os << "Assertion failed: " << t << " != " << u << " Hint: " << hint;

		throw std::runtime_error(os.str());
	}
}

void Assert(bool cond, const std::string& hint)
{
        AssertEqual(cond, true, hint);
}

TestRunner::TestRunner()
{
        fail_count = 0;
}

TestRunner::~TestRunner()
{
        if (fail_count > 0)
        {
                std::cerr << fail_count << " tests failed. Terminate";
                exit(1);
        }
}

template<class TestFunction>
void TestRunner::RunTest(TestFunction test_function, const std::string& test_function_name)
{
	try
	{
		test_function();
		std::cerr << test_function_name << " OK" << std::endl;
	}
	catch (std::runtime_error& ex)
	{
		++fail_count;
		std::cerr << test_function_name << " fail: " << ex.what() << std::endl;
	}
}
