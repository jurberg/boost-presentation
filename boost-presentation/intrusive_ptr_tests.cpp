/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include "MemoryMacros.h"
#include <boost/test/unit_test.hpp>
#include <boost/intrusive_ptr.hpp>
#include "CustomerRepository.hpp"

BOOST_AUTO_TEST_CASE(IntrusivePtrTest)
{
	MEMORY_CHECKPOINT
	
	boost::intrusive_ptr<CustomerRepository> rep(new CustomerRepository());
	BOOST_CHECK(rep->RefCount() == 1);

	{
		boost::intrusive_ptr<CustomerRepository> rep2(rep);
		BOOST_CHECK(rep->RefCount() == 2);
	}
	
	BOOST_CHECK(rep->RefCount() == 1);

	ASSERT_NO_MEMORY_LEAK
}
