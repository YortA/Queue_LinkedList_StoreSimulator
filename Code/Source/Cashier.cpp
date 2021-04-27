#include "Cashier.h"
#include <iostream>

Cashier::Cashier() : custInline(0), head(nullptr), tail(nullptr)
{
	//addQueue();
}

void Cashier::addQueue()
{
	int timer = getGenerateTime();		// generate a random time for our customer at checkout

	Customer* temp = new Customer(timer);

	if (isEmpty(head))
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->setNext(temp);
		tail = temp;
	}
	++custInline;
}

void Cashier::removeQueue()
{
	Customer* temp = head;

	if (isEmpty(head))
	{
		return;		// empty list. nothing to delete.
	}
	else
	{
		head = temp->getNext();		// change our head value to the next node and delete our old obj
		delete temp;
	}
	--custInline;
}

void Cashier::printQueue()
{
	Customer* temp;
	temp = head;
	while (!isEmpty(temp))		// while not empty
	{
		//std::cout << temp->getTimer() << ' ';
		std::cout << '*' << ' ';
		temp = temp->getNext();
	}
	std::cout << std::endl;
}

bool Cashier::isEmpty(Customer* node)
{
	if (node == nullptr)		// node is empty, return true
		return true;
	else
		return false;
}

int Cashier::getCustinline()
{
	return custInline;
}

int Cashier::getGenerateTime()
{
	return clock->randomNumber();		// how long it will take our customer to checkout
}