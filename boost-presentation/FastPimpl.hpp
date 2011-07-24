/*
 * Boosting your C++ Development with Boost
 */
#pragma once

class FastPimplImp;

class FastPimpl
{
public:
	FastPimpl();
	~FastPimpl();
	void DoSomething();

private:
	FastPimplImp* imp;

};
