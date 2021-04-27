#pragma once
#include "Customer.h"
#include "Time.h"

class Cashier
{
protected:
	Customer* head, * tail;
private:
	int custInline;

	Timer* clock = nullptr;
public:
	Cashier();

	void addQueue();
	void removeQueue();

	void printQueue();

	bool isEmpty(Customer* node);
	int getCustinline();
	int getGenerateTime();

	Customer* getHead()
	{
		return head;
	}
};