#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>	// ghetto timer
#include <algorithm>
#include "Cashier.h"
#include "Time.h"


class Manager
{
private:
	Timer* clock = nullptr;
	int totalCashiers = 9;
	std::vector<Cashier*> aisles;
public:
	Manager()
	{
		createCashier();
	}

	void storeLoop();
	void cleanup();

	void createCashier();
	void newCustomer(int index);
	void removeCustomer();

	void printCashiers();
	// finds our lowest custInline and returns the index
	int findCashier(std::vector<Cashier*> vec);

	void timedownCashier(int reduce);
};