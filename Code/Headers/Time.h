#pragma once
#include <random>

class Timer
{
public:
	// get random number
	int randomNumber()
	{
		std::random_device seed;
		std::mt19937 engine(seed());
		std::uniform_int_distribution<int> dist(10, 20);		// arbitrary numbers. Could use int_min, int_max if we wanted the full range of int
		int rVal = dist(engine);

		return rVal;		// return our randomly generated number
	}

	// returns the time at which a new customer is init
	int randomNumberManager()
	{
		std::random_device seed;
		std::mt19937 engine(seed());
		std::uniform_int_distribution<int> dist(1000, 2000);		// arbitrary numbers. Could use int_min, int_max if we wanted the full range of int
		int rVal = dist(engine);

		return rVal;		// return our randomly generated number
	}
};