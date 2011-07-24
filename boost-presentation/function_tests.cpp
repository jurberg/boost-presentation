/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

int add(int a, int b) { return a + b; }

class Multiplier
{
public:
	int Mulitply(int a, int b) { return a * b; } 
};

BOOST_AUTO_TEST_CASE(FunctionTest)
{
	Multiplier m;
	
	boost::function<int (int, int)> fa = &add;
	BOOST_CHECK(fa(10, 20) == 30);

	boost::function<int (Multiplier, int, int)> fm = &Multiplier::Mulitply;
	BOOST_CHECK(fm(m, 5, 2) == 10);

	boost::function<int (int, int)> fb = boost::bind(&Multiplier::Mulitply, m, _1, _2);
	BOOST_CHECK(fb(5, 2) == 10);

}

class Button
{
public:
	void Click() { OnClick(); }
	boost::function<void ()> OnClick;

};

class ButtonHandler
{
public:
	ButtonHandler() : click_called(false) {}
	void OnClick() { click_called = true; }
	bool click_called;
};

BOOST_AUTO_TEST_CASE(FunctionCallbackTest)
{
	Button button;
	ButtonHandler handler;
	
	button.OnClick = boost::bind(&ButtonHandler::OnClick, &handler);

	button.Click();
	
	BOOST_CHECK(handler.click_called);

}
