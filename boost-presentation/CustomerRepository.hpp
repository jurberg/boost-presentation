/*
 * Boosting your C++ Development with Boost
 */
#pragma once

#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/intrusive_ptr.hpp>

template <typename T> void intrusive_ptr_add_ref(T* t) 
{
	t->AddRef();
}

template <typename T> void intrusive_ptr_release(T* t) 
{
	if (t->Release() <= 0) delete t;
}

class Customer;

class CustomerRepository
{
public:
	CustomerRepository();
	~CustomerRepository();

public:
	Customer* FindCustomerById(std::string id);
	boost::shared_ptr<Customer> FindCustomerByName(std::string name);
    void AddRef(); 
    int Release();
	int RefCount();

private:
	int ref_count;

};
