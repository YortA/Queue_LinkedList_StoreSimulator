#include "Manager.h"

void Manager::storeLoop()
{
	while (true)
	{
		int timer = clock->randomNumberManager();
		newCustomer(findCashier(aisles));
		removeCustomer();

		cleanup();
		printCashiers();
		std::cout << "\n\nTIME UNTIL NEXT CUSTOMER: " << timer / 1000.0 << 's';
		// ghetto sleep "timer" for X seconds
		Sleep(timer);
		timedownCashier(timer);
	}
}

void Manager::cleanup()
{
	// CLEARS OUR TERMINAL
	std::cout << "\033[2J\033[1;1H";
}

void Manager::createCashier()
{
	for (int i = 0; i < totalCashiers; ++i)
	{
		aisles.push_back(new Cashier);
	}
}

void Manager::newCustomer(int index)
{
	aisles[index]->addQueue();
}

void Manager::removeCustomer()
{
	for (int i = 0; i < totalCashiers; ++i)
	{
		if (aisles[i]->getHead() != nullptr && aisles[i]->getHead()->getTimer() < 0)
		{
			aisles[i]->removeQueue();	// checked out. remove our old value
		}
	}
}

void Manager::printCashiers()
{
	for (int i = 0; i < totalCashiers; ++i)
	{
		aisles[i]->printQueue();
	}
}

int Manager::findCashier(std::vector<Cashier*> vec)
{
	// find our lowest iterator val for count
	auto min = std::min_element(vec.begin(), vec.end(), 
		[](Cashier* lhs, Cashier* rhs) { return lhs->getCustinline() < rhs->getCustinline(); });

	// get our position
	int minPos = std::distance(vec.begin(), min);

	return minPos;
}

// countdown our timer on the head of our linked list
void Manager::timedownCashier(int reduce)
{
	for (int i = 0; i < totalCashiers; ++i)
	{
		if (aisles[i]->getHead() != nullptr)
		{
			aisles[i]->getHead()->reduceTimer(floor(reduce / 1000));	// let's just round down
		}
	}
}