/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include "Customer.hpp"

BOOST_AUTO_TEST_CASE(CustomerDebit)
{
	Money m25(25);
	boost::shared_ptr<Customer> customer(new Customer("100", "John Doe"));
	BOOST_CHECK(customer->GetBalance() == Money(0));
	customer->Debit(m25);
	BOOST_CHECK(customer->GetBalance() == m25);
}

BOOST_AUTO_TEST_CASE(CustomerCredit)
{
	Money m25(25);
	boost::shared_ptr<Customer> customer(new Customer("100", "John Doe"));
	BOOST_CHECK(customer->GetBalance() == Money(0));
	customer->Credit(m25);
	BOOST_CHECK(customer->GetBalance() == Money(-25));
}
