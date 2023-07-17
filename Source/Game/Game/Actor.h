#pragma once
#include "Core/Core.h"
#include "Renderer/Render.h"
namespace JoeBidenAwoken
{
	class Actor
	{
	public:
		Actor(const JoeBidenWakeup::Transform& transform, const JoeBidenWakeup::Model model) : transform{ transform }, model{ model }
		{

		}
		Actor() = default;
		virtual JoeBidenWakeup::Transform update();
		virtual void draw();
		void setChangeData(JoeBidenWakeup::Transform change);

	protected:
		JoeBidenWakeup::Transform transform;
		JoeBidenWakeup::Transform change;
		JoeBidenWakeup::Model model;
	};
}

