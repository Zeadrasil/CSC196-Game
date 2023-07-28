#include "Actor.h"
namespace JoeBidenAwoken
{
	JoeBidenWakeup::Transform Actor::update()
	{
		if (owner && ownerState == owner->getState())
		{
			return JoeBidenWakeup::Actor::update();
		}
		return { JoeBidenWakeup::Vector2{0, 0}, 0, 0 };
	}
}