#include "Actor.h"
#include "Scene.h"

JoeBidenWakeup::Transform JoeBidenWakeup::Actor::update()
{
	transform.position += change.position;
	transform.rotation += change.rotation;
	transform.scale += change.scale;
	for (auto& child : children)
	{
		child->setChangeData(change);
		child->update();
	}
	setChangeData({ 0, 0, 0 });
	if (model) draw();
	if (remainingLifespan != -1)
	{
		remainingLifespan -= gTime.getDeltaTime();
		if (remainingLifespan <= 0)
		{
			destroyed = true;
		}
	}
	return JoeBidenWakeup::Transform();
}

void JoeBidenWakeup::Actor::draw()
{
	model->Draw(transform.position, transform.rotation, transform.scale);
	for (auto child : children)
	{
		child->draw();
	}
}

void JoeBidenWakeup::Actor::setChangeData(JoeBidenWakeup::Transform change)
{
	this->change = change;
}

void JoeBidenWakeup::Actor::addChild(std::shared_ptr<Actor> actor)
{
	children.push_back(actor);
}

void JoeBidenWakeup::Actor::removeChild(std::shared_ptr<Actor> actor)
{
	children.remove(actor);
}

void JoeBidenWakeup::Actor::removeChildren()
{
	children.clear();
}
