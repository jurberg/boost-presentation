/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "Money.hpp"

BOOST_AUTO_TEST_CASE(MoneyAdd)
{
	Money m1(25);
	Money m2(25);
	Money expected(50);

	BOOST_CHECK((m1 + m2) == expected);
}

BOOST_AUTO_TEST_CASE(MoneySubtract)
{
	Money m1(50);
	Money m2(30);
	Money expected(20);

	BOOST_CHECK((m1 - m2) == expected);
}

BOOST_AUTO_TEST_CASE(MoneyIsPositive)
{
	Money m1(50);
	BOOST_CHECK(m1.IsPositive());

	Money m2(-30);
	BOOST_CHECK(!m2.IsPositive());
}

BOOST_AUTO_TEST_CASE(MoneyIncrement)
{
	Money m1(50);
	Money m2(51);
	
	m1.Increment();
	
	BOOST_CHECK(m1 == m2);
}

BOOST_AUTO_TEST_CASE(MoneyGT)
{
	Money m1(50);
	Money m2(51);
	
	BOOST_CHECK(m1 < m2);
}

BOOST_AUTO_TEST_CASE(MoneyLT)
{
	Money m1(50);
	Money m2(51);
	
	BOOST_CHECK(m2 > m1);
}