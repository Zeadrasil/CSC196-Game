#pragma once
#include "Vector2.h"
namespace JoeBidenWakeup
{
	class Transform
	{
	public:
		Vector2 position;
		float rotation;
		float scale;

		Transform() = default;
		Transform(const Vector2& position, float rotation, float scale = 1) : position{ position }, rotation{ rotation }, scale{ scale }
		{
		}
	};
}
