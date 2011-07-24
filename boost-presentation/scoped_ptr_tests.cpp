/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include "MemoryMacros.h"
#include <boost/test/unit_test.hpp>
#include <boost/scoped_ptr.hpp>
#include "Money.hpp"
#include "FastPimpl.hpp"
#include "FastPimplScoped.hpp"

BOOST_AUTO_TEST_CASE(NoScopedPtrTest)
{
	MEMORY_CHECKPOINT
	int i = 0;
	while(i < 1)
	{
		Money* m25 = new Money(25);
		if (m25->IsPositive())
		{
			m25->Increment();
			break;
		}
		//...
		delete m25;
		i++;
	}
	ASSERT_MEMORY_LEAK
}

BOOST_AUTO_TEST_CASE(ScopedPtrTest)
{
	MEMORY_CHECKPOINT
	int i = 0;
	while(i < 1)
	{
		boost::scoped_ptr<Money> m25(new Money(25));
		if (m25->IsPositive())
		{
			m25->Increment();
			break;
		}
		//...
		i++;
	}
	ASSERT_NO_MEMORY_LEAK
}

BOOST_AUTO_TEST_CASE(FastPimplNoScopedPtr)
{
	MEMORY_CHECKPOINT
	
	try
	{
		FastPimpl();
	}
	catch (std::exception&) {}

	ASSERT_MEMORY_LEAK
}

BOOST_AUTO_TEST_CASE(FastPimplWithScopedPtr)
{
	MEMORY_CHECKPOINT
	
	try
	{
		FastPimplScoped();
	}
	catch (std::exception&) {}

	ASSERT_NO_MEMORY_LEAK
}
