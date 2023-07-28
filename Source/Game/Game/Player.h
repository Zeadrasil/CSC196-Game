#pragma once
#include "Actor.h"
#include "Framework/Framework.h"
#include <memory>
#include "Framework/Emitter.h"
namespace JoeBidenAwoken
{
	class Player : public Actor
	{
	public:
		Player(float turnRate, const JoeBidenWakeup::Transform& transform, const std::shared_ptr<JoeBidenWakeup::Model> model, Asteroids* owner) : Actor{ transform, model, "Player" , owner, nullptr, Asteroids::GameState::Game}, turnRate{turnRate}
		{

		}
		Player() = default;

		void onCollision(JoeBidenWakeup::Actor* other) override;
		JoeBidenWakeup::Transform update() override;
		float rotating = 0;
		float getTurnRate() { return turnRate; };
		float getCurrentCooldown() { return currentCooldown; };
		void fire();
		bool getSpray() { return spray; };
		void applyUpgrade(std::shared_ptr<Upgrade> upgrade);
		float getMaxHealth() { return maxHealth; };
		JoeBidenWakeup::Vector2 getCollisionSpeed() { return collisionSpeed; };
		Actor* getLastCollision() const { return lastCollision; };
	private:
		JoeBidenWakeup::Vector2 speed = 0, collisionSpeed = 0;
		float turnRate = 0;
		bool friendlyFire = true;
		bool spray = false;
		float shotCooldown = 1, currentCooldown = 0;
		float momentum = 0.0000000001;
		float rotationMomentum = 0.0001;
		float bulletLifespan = 3;
		float health = 500, maxHealth = 500;
		float regen = 0.1;
		int lives = 0, maxLives = 0;
		float acceleration = 1;
		float reverseThrustModifier = 0.5;
		float damage = 5;
		float bulletSize = 1;
		float antiDoubleCollision = 0.25;
		float bulletSpeed = 3;
		bool pierce = false;
		Actor* lastCollision = nullptr;
		JoeBidenWakeup::Emitter thruster = JoeBidenWakeup::Emitter({ {0, 0}, 0 }, { 100, 0.1, false, 0, 1, 2, 2, 10, 0, 0, JoeBidenWakeup::halfPi / acceleration, {1.0f, 0.647f, 0.0f} });
	};
}

