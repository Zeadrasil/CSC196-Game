#pragma once
#include <Core/Core.h>
#include "Renderer.h"
namespace JoeBidenWakeup
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<JoeBidenWakeup::Vector2>& points) : points{ points } 
		{}
		void Draw(const JoeBidenWakeup::Vector2& position, float radianRotation, float scale);
		void Draw(const JoeBidenWakeup::Transform& transform);

		std::vector<JoeBidenWakeup::Vector2> getPoints() const { return points; };
		bool load(const std::string& filename);
	private:
		std::vector<JoeBidenWakeup::Vector2> points;

	};
}

