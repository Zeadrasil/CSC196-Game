#include "Asteroid.h"
#include "Player.h"
#include "Projectile.h"
JoeBidenWakeup::Transform JoeBidenAwoken::Asteroid::update()
{
	if (health <= 0)
	{
		if (transform.scale > 1)
		{
			transform.scale--;
			scene->add(std::make_shared<Asteroid>(transform, owner, change.rotation + JoeBidenWakeup::randomFloat(-1, 1),
				JoeBidenWakeup::Vector2{ change.position.x * JoeBidenWakeup::randomFloat(0.75, 1.25), change.position.y * (float)(1.0f + JoeBidenWakeup::randomFloat(0.5) - 0.25)}));
			scene->add(std::make_shared<Asteroid>(transform, owner, change.rotation + JoeBidenWakeup::randomFloat(-1, 1),
				JoeBidenWakeup::Vector2{ change.position.x * JoeBidenWakeup::randomFloat(0.75, 1.25), change.position.y * (float)(1.0f + JoeBidenWakeup::randomFloat(0.5) - 0.25) }));
		}
		this->destroyed = true;
	}
    JoeBidenWakeup::Transform trans = change;
	change.rotation *= JoeBidenWakeup::gTime.getDeltaTime();
	change.position *= JoeBidenWakeup::gTime.getDeltaTime();
	if (transform.position.x > JoeBidenWakeup::gRenderer.getWidth())
	{
		change.position.x -= JoeBidenWakeup::gRenderer.getWidth();
	}
	if (transform.position.x < 0)
	{
		change.position.x += JoeBidenWakeup::gRenderer.getWidth();
	}
	if (transform.position.y > JoeBidenWakeup::gRenderer.getHeight())
	{
		change.position.y -= JoeBidenWakeup::gRenderer.getHeight();
	}
	if (transform.position.y < 0)
	{
		change.position.y += JoeBidenWakeup::gRenderer.getHeight();
	}
    Actor::update();
    change = trans;
    return trans;
}

void JoeBidenAwoken::Asteroid::onCollision(JoeBidenWakeup::Actor* other)
{
	if (other->tags.find("Player") != std::string::npos)
	{
		if (other->tags.find("Bullet") == std::string::npos)
		{
			if (!((Player*)other)->getLastCollision() || ((Player*)other)->getLastCollision() != this)
			{
				health -= (change.position - ((Player*)other)->getCollisionSpeed()).length() / 50;
				change.position += ((Player*)other)->getCollisionSpeed() * 10;
			}
		}
		else
		{
			health -= ((Projectile*)other)->getDamage();
			change.position += ((Projectile*)other)->getMovement();
		}
	}
}
