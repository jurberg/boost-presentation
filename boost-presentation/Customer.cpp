/*
 * Boosting your C++ Development with Boost
 */
#include "Customer.hpp"
#include <boost/bind.hpp>

Customer::Customer()
	: id()
	, name()
	, balance(0)
	, listeners()
{
}

Customer::Customer(std::string id, std::string name)
	: id(id)
	, name(name)
	, balance(0)
	, listeners()
{
}

Customer::~Customer()
{
}

std::string Customer::GetId()
{
	return id;
}

std::string Customer::GetName()
{
	return name;
}

void Customer::SetName(std::string name)
{
	this->name = name;
}

void Customer::Debit(Money amount)
{
	balance = balance + amount;
	CheckForNegativeBalance();
}

void Customer::Credit(Money amount)
{
	balance = balance - amount;
	CheckForNegativeBalance();
}

Money Customer::GetBalance()
{
	return balance;
}

void Customer::AddListener(boost::shared_ptr<CustomerListener> l)
{
	listeners.push_back(l);
}

void Customer::RemoveListener(boost::shared_ptr<CustomerListener> l)
{
	CustomerList::iterator it = std::find(listeners.begin(), listeners.end(), l);
	if (it != listeners.end())
	{
		listeners.erase(it);
	}
}

void Customer::CheckForNegativeBalance()
{
	if (balance < Money(0))
	{
		std::for_each(
			listeners.begin(), 
			listeners.end(), 
			boost::bind(&CustomerListener::OnNegativeBalance, _1, shared_from_this(), balance)); 
	}
}
