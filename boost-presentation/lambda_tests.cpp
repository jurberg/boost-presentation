/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/function.hpp>
#include <vector>

// bring the placeholders into scope
using namespace boost::lambda;

BOOST_AUTO_TEST_CASE(LambdaTest)
{
	int value = (_1 + _2)(10, 2);
	BOOST_CHECK(value == 12);

	boost::function<int (int, int)> f = (_1 + _2);
	BOOST_CHECK(f(7, 11) == 18);
}

BOOST_AUTO_TEST_CASE(LambdaComposeTest)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	std::vector<int> v(a, a + 8); 

	// # of vector entries where entry is > 5 && < 10
	/*
	int count = std::count_if(v.begin(), v.end(),
		boost::bind(
			std::logical_and<bool>(),
			boost::bind(std::greater<int>(), _1, 5),
			boost::bind(std::less_equal<int>(),_1, 10)));
	*/
	
	int count = std::count_if(v.begin(), v.end(), (_1 > 5 && _1 < 10));
	BOOST_CHECK(count == 3);
}
