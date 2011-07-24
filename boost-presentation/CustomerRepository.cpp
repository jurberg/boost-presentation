/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include "CustomerRepository.hpp"
#include "Customer.hpp"

CustomerRepository::CustomerRepository()
	: ref_count(0)
{
}

CustomerRepository::~CustomerRepository()
{
}

Customer* CustomerRepository::FindCustomerById(std::string id)
{
	return new Customer(id, "John Doe");
}

boost::shared_ptr<Customer> CustomerRepository::FindCustomerByName(std::string name)
{
	return boost::shared_ptr<Customer>(new Customer("200", name));
}

void CustomerRepository::AddRef() 
{ 
	++ref_count;
}

int CustomerRepository::Release() 
{
	return --ref_count;
}

int CustomerRepository::RefCount()
{
	return ref_count;
}
