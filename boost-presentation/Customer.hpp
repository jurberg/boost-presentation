/*
 * Boosting your C++ Development with Boost
 */
#pragma once

#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "Money.hpp"
#include <list>

class Customer;

class CustomerListener
{
public:
	virtual void OnNegativeBalance(boost::shared_ptr<Customer> customer, Money balance) = 0;
};

typedef std::list<boost::shared_ptr<CustomerListener> > CustomerList;

class Customer : public boost::enable_shared_from_this<Customer>
{
public:
	Customer();
	Customer(std::string id, std::string name);
	~Customer();

public:
	std::string GetId();
	std::string GetName();
	void SetName(std::string name);
	void Debit(Money amount);
	void Credit(Money amount);
	Money GetBalance();
	void AddListener(boost::shared_ptr<CustomerListener> l);
	void RemoveListener(boost::shared_ptr<CustomerListener> l);

private:
	void CheckForNegativeBalance();

private:
	std::string id;
	std::string name;
	Money balance;
	CustomerList listeners;

};
