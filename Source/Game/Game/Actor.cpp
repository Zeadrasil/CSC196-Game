#include "Actor.h"

JoeBidenWakeup::Transform JoeBidenAwoken::Actor::update()
{
	transform.position += change.position;
	transform.rotation += change.rotation;
	transform.scale += change.scale;
	draw();
	return JoeBidenWakeup::Transform();
}

void JoeBidenAwoken::Actor::draw()
{
	model.Draw(transform.position, transform.rotation, transform.scale);
}

void JoeBidenAwoken::Actor::setChangeData(JoeBidenWakeup::Transform change)
{
	this->change = change;
}
