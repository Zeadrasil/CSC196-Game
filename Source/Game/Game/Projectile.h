#pragma once
#include "Framework/Actor.h"
#include "Actor.h"
namespace JoeBidenAwoken
{
	class Projectile : public JoeBidenAwoken::Actor
	{
	public:
		Projectile(const JoeBidenWakeup::Transform& transform, const std::shared_ptr<JoeBidenWakeup::Model> model, std::string tags, Asteroids* owner, JoeBidenWakeup::Vector2 movement, bool pierce, float lifespan, float damage) : Actor{ transform, model, tags, owner, nullptr, Asteroids::GameState::Game }, pierce{ pierce }, damage{ damage }, previousDamage{ damage }
		{
			change.position = movement;
			change.rotation = 0;
			change.scale = 0;
			this->remainingLifespan = lifespan;
			//if(std::)
		}
		void onCollision(JoeBidenWakeup::Actor* other) override;
		float getDamage() { return previousDamage; };
		JoeBidenWakeup::Vector2 getMovement() const { return change.position; };
		JoeBidenWakeup::Transform update() override;
	private:
		float damage;
		float previousDamage;
		bool pierce;
	};
}
/*
class Projectile : Actor
{
public:
	Projectile(JoeBidenWakeup::Transform& transform, const std::shared_ptr<JoeBidenWakeup::Model> model, std::string tags, Asteroids* owner) : Actor{ transform, }
};*/	