/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include "FastPimpl.hpp"
#include <exception>

class FastPimplImp
{
public:
	FastPimplImp() {}
	void SomePrivateFunction() {}
	int aPrivateVariable;
};

FastPimpl::FastPimpl() 
	: imp(new FastPimplImp()) 
{
	throw std::exception();
}

FastPimpl::~FastPimpl()
{
}

void FastPimpl::DoSomething()
{
	imp->SomePrivateFunction();
	imp->aPrivateVariable = 10;
};
