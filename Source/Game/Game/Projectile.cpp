#include "Projectile.h"
#include "Actor.h"
#include "Asteroid.h"
namespace JoeBidenAwoken
{
	void Projectile::onCollision(JoeBidenWakeup::Actor* other)
	{
		if (other->tags.find("Enemy") != std::string::npos && tags.find("Enemy") == std::string::npos)
		{
			if (other->tags.find("Bullet") != std::string::npos)
			{
				damage -= ((Projectile*)other)->getDamage();
			}
			else
			{

			}
		}
		else if (other->tags.find("Player") != std::string::npos)
		{
			if (model->getColor().g != 0)
			{
				if (other->tags.find("Bullet"))
				{
					damage -= ((Projectile*)other)->getDamage();
				}
				else
				{
					destroyed = true;
				}
			}
		}
		else if (other->tags.find("Asteroid") != std::string::npos && tags.find("Player") != std::string::npos)
		{
			if (pierce)
			{
				damage -= ((Asteroid*)other)->getHealth();
			}
			else
			{
				damage = 0;
			}
			if (damage <= 0)
			{
				destroyed = true;
			}
		}
	}
	JoeBidenWakeup::Transform Projectile::update()
	{
		previousDamage = damage;
		JoeBidenWakeup::Transform data = change;
		Actor::update();
		change = data;
		return change;
	}
}