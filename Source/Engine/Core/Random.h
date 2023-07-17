#pragma once
#include <random>
namespace JoeBidenWakeup
{
	inline void seedRandom(unsigned int seed) { srand(seed); };
	inline int random() { return rand(); };
	inline int random(unsigned int max) { return random() % max; };
	inline int random(int min, int max)
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
	inline float randomFloat() { return random() / (float)RAND_MAX; };
	inline float randomFloat(float maxAbsoluteValue) { return randomFloat() * maxAbsoluteValue; };
	inline float randomFloat(float min, float max)
	{
		if (min > max)
		{
			float temp = max;
			max = min;
			min = temp;
		}
		if (min == max)
		{
			return min;
		}
		float temp = max - min;
		if (temp < 0)
		{
			return randomFloat(temp * -1) * -1 + min;
		}
		else
		{
			return randomFloat(temp) + min;
		}
	}
}

