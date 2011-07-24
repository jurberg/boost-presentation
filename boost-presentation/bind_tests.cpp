/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <boost/bind.hpp>
#include <string>
#include <vector>

using namespace std;

string cat(string a, string b, string c, string d) 
{ 
	return a + b + c + d; 
}

BOOST_AUTO_TEST_CASE(BindFunctionTest)
{
	string value = boost::bind(&cat, _3, _1, _4, _2)("1", "2", "3", "4");
	BOOST_CHECK(value == "3142");
}

class Counter
{
public:
	Counter() : total(0) {}
	void Add(int value)
	{
		total += value;
	}
	int total;
};

BOOST_AUTO_TEST_CASE(BindObjectFunctionTest)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> v(a, a + 8); 
	Counter counter;

	// boost::bind makes a copy of variables
	std::for_each(v.begin(), v.end(), boost::bind(&Counter::Add, counter, _1));
	BOOST_CHECK(counter.total == 0);

	// use boost::ref to avoid the copy
	std::for_each(v.begin(), v.end(), boost::bind(&Counter::Add, boost::ref(counter), _1));
	BOOST_CHECK(counter.total == 36);
}

BOOST_AUTO_TEST_CASE(BoostComposeTest)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> v(a, a + 8); 

	// # of vector entries where entry is > 5 && < 10
	int count = std::count_if(v.begin(), v.end(),
		boost::bind(
			std::logical_and<bool>(),
			boost::bind(std::greater<int>(), _1, 5),
			boost::bind(std::less_equal<int>(),_1, 10)));

	BOOST_CHECK(count == 3);
}

