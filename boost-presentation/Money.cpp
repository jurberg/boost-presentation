/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include "Money.hpp"

Money::Money(double amount)
	: amount(amount)
{
}

Money::~Money()
{
}

const Money Money::operator+(const Money& other) const
{
	return Money(this->amount + other.amount);
}

const Money Money::operator-(const Money& other) const
{
	return Money(this->amount - other.amount);
}

bool Money::operator==(const Money& other) const
{
	return this->amount == other.amount;
}

bool Money::operator!=(const Money& other) const
{
	return !(*this == other);
}

bool Money::operator>(const Money& other) const
{
	return this->amount > other.amount;
}

bool Money::operator<(const Money& other) const
{
	return this->amount < other.amount;
}

bool Money::IsPositive() const
{
	return amount >= 0;
}

void Money::Increment()
{
	amount++;
}
