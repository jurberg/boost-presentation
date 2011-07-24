/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include "MemoryMacros.h"
#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include "Customer.hpp"
#include "CustomerRepository.hpp"

BOOST_AUTO_TEST_CASE(FactoryMethodNoSharedPtr)
{
	MEMORY_CHECKPOINT

	CustomerRepository repository;
	Customer* cust100 = repository.FindCustomerById("100");

	//...

	// oops, forgot to delete cust100

	ASSERT_MEMORY_LEAK
}

BOOST_AUTO_TEST_CASE(FactoryMethodWithSharedPtr)
{
	MEMORY_CHECKPOINT

	CustomerRepository repository;
	boost::shared_ptr<Customer> custJane = repository.FindCustomerByName("Jane Doe");
	BOOST_CHECK(custJane.use_count() == 1);
	{
		boost::shared_ptr<Customer> custJane2 = custJane;
		BOOST_CHECK(custJane.use_count() == 2);
	}
	BOOST_CHECK(custJane.use_count() == 1);

	ASSERT_NO_MEMORY_LEAK
}

class CustomerDeleter
{
public:
	void operator()(Customer* c) 
	{
		delete c;
		deleted = true;
	}
	static bool deleted;
};
bool CustomerDeleter::deleted = false;

BOOST_AUTO_TEST_CASE(DeleterTest)
{
	MEMORY_CHECKPOINT

	CustomerDeleter::deleted = false;
	{
		boost::shared_ptr<Customer> c(new Customer("100", "John Doe"), CustomerDeleter());
	}
	BOOST_REQUIRE(CustomerDeleter::deleted);

	ASSERT_NO_MEMORY_LEAK
}

class TestListener : public CustomerListener
{
public:
	TestListener() : last_balance(Money(0)) {}
	virtual ~TestListener() {}
	virtual void OnNegativeBalance(boost::shared_ptr<Customer> customer, Money balance)
	{
		last_balance = balance;
	}

public:
	Money last_balance;

};

BOOST_AUTO_TEST_CASE(SharedFromThisTest)
{
	MEMORY_CHECKPOINT

	boost::shared_ptr<TestListener> listener(new TestListener());
	boost::shared_ptr<Customer> cust(new Customer("100", "John Doe"));
	cust->AddListener(listener);
	
	cust->Credit(Money(50));

	BOOST_REQUIRE(listener->last_balance == Money(-50));

	ASSERT_NO_MEMORY_LEAK
}
