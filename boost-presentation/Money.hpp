/*
 * Boosting your C++ Development with Boost
 */
#pragma once

/**
 * The standard unit testing example
 */
class Money
{
public:
	Money(double amount);
	~Money();

public:
	const Money operator+(const Money& other) const;
	const Money operator-(const Money& other) const;
	bool operator==(const Money& other) const;	
	bool operator!=(const Money& other) const;	
	bool operator>(const Money& other) const;	
	bool operator<(const Money& other) const;	
	bool IsPositive() const;
	void Increment();

private:
	double amount;

};
