#pragma once
#include "Actor.h"
namespace JoeBidenAwoken
{
	class Asteroid :public Actor
	{
	public:
		Asteroid(JoeBidenWakeup::Transform transform, Asteroids* owner, float rotationSpeed, JoeBidenWakeup::Vector2 velocity) : 
			Actor{transform, JoeBidenWakeup::gModelManager.get("asteroid.txt"), "Asteroid", owner, nullptr, Asteroids::GameState::Game}, 
			maxHealth{ 5 * (float)std::pow(2, transform.scale) }
		{
			change = { velocity, rotationSpeed, 0 };
			health = maxHealth;
		}
		JoeBidenWakeup::Transform update() override;
		void onCollision(JoeBidenWakeup::Actor* other) override;
		float getMaxHealth() { return maxHealth; };
		float getHealth() { return health; };
	private:
		float health, maxHealth;
	};

}