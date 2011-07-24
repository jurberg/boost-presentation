/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class TimerTest
{
public:
	TimerTest(boost::asio::io_service& io_service) 
		: io_service(io_service), timer(io_service), timer_called(false) 
	{
	}
	void Run()
	{
		timer.expires_from_now(boost::posix_time::seconds(1));
		timer.async_wait(boost::bind(&TimerTest::TimerDone, this, _1));
	}
	void TimerDone(const boost::system::error_code& ec)
	{
		timer_called = true;
	}
	bool timer_called;

private:
	boost::asio::io_service& io_service;
	boost::asio::deadline_timer timer;

};

BOOST_AUTO_TEST_CASE(AsyncTimerTest)
{
	boost::asio::io_service io_service;
	TimerTest test(io_service);

	test.Run();
	io_service.run();  // blocks until no more work to be done

	BOOST_REQUIRE(test.timer_called);
}