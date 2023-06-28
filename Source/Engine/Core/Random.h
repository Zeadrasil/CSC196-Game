#pragma once
#include <random>
namespace JoeBidenWakeup
{
	void seedRandom(unsigned int seed) { srand(seed); };
	int random() { return rand(); };
	int random(unsigned int max) { return random() % max; };
	int random(int min, int max) 
	{ 
		if (min > max)
		{
			int temp = max;
			max = min;
			min = temp;
		}
		if (min == max)
		{
			return min;
		}
		int temp = max - min;
		if (temp < 0)
		{
			return random((unsigned int)(temp * -1)) * -1 + min;
		}
		else
		{
			return random((unsigned int)temp) + min;
		}
	}
}

