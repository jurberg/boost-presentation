/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <boost/signals.hpp>
#include <boost/bind.hpp>

class EventListener
{
public:
	EventListener() : event_called(false) {}
	void OnEvent()
	{
		event_called = true;
	}
	bool event_called;
};

BOOST_AUTO_TEST_CASE(SignalsTest)
{
	boost::signal<void ()> sig;
	EventListener el1;
	EventListener el2;

	sig.connect(boost::bind(&EventListener::OnEvent, &el1));
	sig.connect(boost::bind(&EventListener::OnEvent, &el2));

	sig();

	BOOST_CHECK(el1.event_called);
	BOOST_CHECK(el2.event_called);
}
