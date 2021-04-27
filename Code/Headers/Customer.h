#pragma once

class Customer
{
private:
	Customer* next;
	int timer;		// the amount of time our customer will wait in line
public:
	Customer(int timer, Customer* next = nullptr)
	{
		this->timer = timer;
		this->next = next;
	}

	void reduceTimer(int reduction)
	{
		this->timer = timer - reduction;
	}

	// SETTERS
	void setNext(Customer* newCustomer)
	{
		next = newCustomer;
	}

	// GETTERS
	Customer* getNext()
	{
		return next;
	}

	int getTimer()
	{
		return timer;
	}
};