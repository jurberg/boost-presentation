/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include "MemoryMacros.h"
#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include "Customer.hpp"

BOOST_AUTO_TEST_CASE(WeakPtrTest)
{
	MEMORY_CHECKPOINT

	boost::weak_ptr<Customer> weak_cust;
	{
		boost::shared_ptr<Customer> cust(new Customer("100", "John Doe"));
		BOOST_CHECK(cust.use_count() == 1);
		
		weak_cust = cust;
		BOOST_CHECK(cust.use_count() == 1);
		BOOST_CHECK(weak_cust.use_count() == 1);
		  
		// must convert back to strong pointer to use, throws error if null
		boost::shared_ptr<Customer> cust2(weak_cust);
		BOOST_CHECK(cust2->GetId() == "100");

		// lock can be used on empty weak pointers
		if (boost::shared_ptr<Customer> cust3 = weak_cust.lock())
		{
			BOOST_CHECK(cust3->GetId() == "100");
		}
	}
	BOOST_CHECK(weak_cust.use_count() == 0);

	ASSERT_NO_MEMORY_LEAK
}
