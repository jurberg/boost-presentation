/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include "FastPimplScoped.hpp"
#include <exception>

class FastPimplScopedImp
{
public:
	FastPimplScopedImp() {}
	void SomePrivateFunction() {}
	int aPrivateVariable;
};

FastPimplScoped::FastPimplScoped() 
	: imp(new FastPimplScopedImp()) 
{
	throw std::exception();
}

FastPimplScoped::~FastPimplScoped()
{
}

void FastPimplScoped::DoSomething()
{
	imp->SomePrivateFunction();
	imp->aPrivateVariable = 10;
}
