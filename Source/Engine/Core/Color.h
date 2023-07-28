#pragma once
#include "MathUtils.h"
#include <iostream>
#include <string>
namespace JoeBidenWakeup
{
	class Color
	{
	public:
		float r, g, b, a;

		Color()
		{
			r = 0;
			g = 0;
			b = 0;
			a = 0;
		}
		Color(float r, float g, float b, float a = 1) : r{ r }, g{ g }, b{ b }, a{a}
		{
		}

		static uint8_t toInt(float c) { return clamp(c, 0.0f, 1.0f) * 255; };
	};
	inline std::istream& operator >> (std::istream& stream, Color& c)
	{
		std::string line;
		std::getline(stream, line);
		std::string str = line.substr(line.find("{") + 1, line.find(",") - line.find("{"));
		c.r = std::stof(str);

		line = line.substr(line.find(",") + 1);
		str = line.substr(0, line.find(","));
		c.g = std::stof(str);

		line = line.substr(line.find(",") + 1);
		str = line.substr(0, line.find("}"));
		c.b = std::stof(str);
		c.a = 1;
		return stream;
	}
}