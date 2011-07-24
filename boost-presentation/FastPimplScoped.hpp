/*
 * Boosting your C++ Development with Boost
 */
#pragma once

#include <boost/scoped_ptr.hpp>

class FastPimplScopedImp;

class FastPimplScoped
{
public:
	FastPimplScoped();
	~FastPimplScoped();
	void DoSomething();

private:
	boost::scoped_ptr<FastPimplScopedImp> imp;

};
