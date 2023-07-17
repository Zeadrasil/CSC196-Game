#pragma once
#include <cmath>
#include <iostream>
namespace JoeBidenWakeup
{
	constexpr float pi = 3.14159265359;
	constexpr float twoPi = pi * 2;
	constexpr float halfPi = pi / 2;
	constexpr float radiansToDegrees(float radians) { return radians * 180 / pi; };
	constexpr float degreesToRadians(float degrees) { return degrees * pi / 180; };

	inline float wrap(float value, float min, float max)
	{
		return std::fmod(value, max) + ((value < min) ? (max + min) : 0);
	}

	inline int wrap(int value, int min, int max)
	{
		return (value % max) + ((value < min) ? (max + min) : 0);
	}

	template <typename T>
	inline T max(T a, T b)
	{
		return (a > b) ? a : b;
	}

	template <typename T>
	inline T clamp(T value, T min, T max)
	{
		if (min > max)
		{
			T temp = max;
			max = min;
			min = temp;
		}
		if (value < min)
		{
			value = min;
		}
		else if (value > max)
		{
			value = max;
		}
		return value;
	}
}