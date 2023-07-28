#include "Player.h"
#include "Input/InputSystem.h"
#include "Core/Core.h"
#include "Projectile.h"
void JoeBidenAwoken::Player::onCollision(JoeBidenWakeup::Actor* other)
{
	if (other->tags.find("Bullet") != std::string::npos)
	{
		if (friendlyFire || other->tags.find("Enemy") != std::string::npos)
		{

		}
	}
	else if (other->tags.find("Asteroid") != std::string::npos)
	{
		if (!lastCollision || lastCollision != other)
		{
			health -= (speed - other->getChange().position).length() / 50;
			collisionSpeed = speed;
			speed += ( speed - other->getChange().position) * JoeBidenWakeup::gTime.getDeltaTime() * acceleration * 1;
		}
	}
}

JoeBidenWakeup::Transform JoeBidenAwoken::Player::update()
{
	Actor::update();
	float accelerationModifier = JoeBidenWakeup::randomFloat(0.9, 1.1);
	float rotationModifier = JoeBidenWakeup::randomFloat(0.9, 1.1);
	float deltaTime = JoeBidenWakeup::gTime.getDeltaTime();
	currentCooldown -= deltaTime;
	if (health < 0)
	{
		lives -= 1;
		health = maxHealth;
	}
	if (lives == -1)
	{
		owner->state = Asteroids::GameState::Dead;
	}
	antiDoubleCollision += deltaTime;
	if (antiDoubleCollision > 0.25)
	{
		lastCollision = nullptr;
	}
	while (transform.rotation > JoeBidenWakeup::twoPi)
	{
		transform.rotation -= JoeBidenWakeup::twoPi;
	}
	while (transform.rotation < -JoeBidenWakeup::twoPi)
	{
		transform.rotation += JoeBidenWakeup::twoPi;
	}
	if (owner->getInputTimer() < 0)
	{
		if (JoeBidenWakeup::gInputSystem.getMouseButtonDown(0))
		{
			//rotating += ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position).rotateR(-transform.rotation + JoeBidenWakeup::halfPi).angle()) * deltaTime * turnRate * 0.5 * rotationModifier;
			//JoeBidenWakeup::Vector2 mousePosition = JoeBidenWakeup::gInputSystem.getMousePosition();
			//transform.rotation = (-JoeBidenWakeup::Vector2::signedAngle(transform.position, mousePosition) - transform.rotation);
			JoeBidenWakeup::Vector2 direction = JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position;
			JoeBidenWakeup::Vector2 forward = JoeBidenWakeup::Vector2{ 0, -1 }.rotateR(transform.rotation);
			rotating += JoeBidenWakeup::Vector2::signedAngle(forward, direction.normalized()) * deltaTime * turnRate - rotating * turnRate * deltaTime;
			//rotating += (-JoeBidenWakeup::Vector2::signedAngle(transform.position.normalized(), mousePosition.normalized()) - transform.rotation) * deltaTime;

		}
		else
		{
			if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_A) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_LEFT))
			{
				rotating -= turnRate * deltaTime * rotationModifier;
			}
			if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_D) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_RIGHT))
			{
				rotating += turnRate * deltaTime * rotationModifier;
			}
		}
		if (JoeBidenWakeup::gInputSystem.getMouseButtonDown(2))
		{
			//float relativeAngle = ((int)(JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position).rotateR(-transform.rotation + JoeBidenWakeup::halfPi).angle());
			//float relativeAngle = JoeBidenWakeup::Vector2::signedAngle(JoeBidenWakeup::gInputSystem.getMousePosition(), transform.position.rotateR(transform.rotation));
			JoeBidenWakeup::Vector2 direction = JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position;
			JoeBidenWakeup::Vector2 forward = JoeBidenWakeup::Vector2{ 0, -1 }.rotateR(transform.rotation);
			float relativeAngle = JoeBidenWakeup::Vector2::signedAngle(forward, direction.normalized());
			if (relativeAngle < 0)
			{

				if (relativeAngle < 0.0f - JoeBidenWakeup::halfPi)
				{
					JoeBidenWakeup::Vector2 increase = forward * ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position).length() * deltaTime * ((JoeBidenWakeup::halfPi - relativeAngle) / 50) * reverseThrustModifier);
					speed -= increase * accelerationModifier * acceleration;
				}
				else
				{
					JoeBidenWakeup::Vector2 increase = forward * ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position).length() * deltaTime * ((JoeBidenWakeup::halfPi - relativeAngle) / 50));
					speed += increase * accelerationModifier * acceleration;
				}
			}
			else
			{

				if (relativeAngle > JoeBidenWakeup::pi)
				{
					JoeBidenWakeup::Vector2 increase = forward * ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position).length() * deltaTime * ((JoeBidenWakeup::halfPi - relativeAngle) / 50) * reverseThrustModifier);
					speed += increase * accelerationModifier * acceleration;
				}
				else
				{
					JoeBidenWakeup::Vector2 increase = forward * ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position).length() * deltaTime * ((JoeBidenWakeup::halfPi - relativeAngle) / 50));
					speed += increase * accelerationModifier * acceleration;
				}
			}

		}
		else
		{
			if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_W) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_UP))
			{
				speed -= JoeBidenWakeup::Vector2{ (float)0, (float)2 * deltaTime }.rotateR(transform.rotation) * accelerationModifier * acceleration;
				JoeBidenWakeup::Vector2 backward = (JoeBidenWakeup::Vector2{ 0, 1 } *transform.scale).rotateR(JoeBidenWakeup::twoPi - transform.rotation);
				thruster.setLocation(backward + transform.position);
				thruster.setAngle(JoeBidenWakeup::twoPi - transform.rotation);
				thruster.setSpeedMin(acceleration * 2);
				thruster.setSpeedMax(acceleration * 10);
			}
			if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_S) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_DOWN))
			{
				speed += JoeBidenWakeup::Vector2{ (float)0, (float)2 * deltaTime }.rotateR(transform.rotation) * accelerationModifier * acceleration * reverseThrustModifier;
				JoeBidenWakeup::Vector2 forward = (JoeBidenWakeup::Vector2{ 0, -1 } *transform.scale).rotateR(transform.rotation);
				thruster.setLocation(forward + transform.position);
				thruster.setAngle(transform.rotation);
				thruster.setSpeedMin(acceleration);
				thruster.setSpeedMax(acceleration * 5);
			}
		}
	}
	if ((JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_W) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_UP) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_S) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_DOWN)) || JoeBidenWakeup::gInputSystem.getMouseButtonDown(2))
	{
		thruster.setColor({ JoeBidenWakeup::randomFloat(0.8, 1), JoeBidenWakeup::randomFloat(0, 0.8), 0 });
		thruster.update();
	}
	JoeBidenWakeup::Transform changes{ speed, rotating, 0 };
	speed *= (1 - momentum) * (1 - JoeBidenWakeup::gTime.getDeltaTime());
	rotating *= (1 - rotationMomentum) * (1 - JoeBidenWakeup::gTime.getDeltaTime());
	transform.position += changes.position;
	transform.rotation += changes.rotation;
	if (transform.position.x > JoeBidenWakeup::gRenderer.getWidth())
	{
		changes.position.x -= JoeBidenWakeup::gRenderer.getWidth();
	}
	if (transform.position.x < 0)
	{
		changes.position.x += JoeBidenWakeup::gRenderer.getWidth();
	}
	if (transform.position.y > JoeBidenWakeup::gRenderer.getHeight())
	{
		changes.position.y -= JoeBidenWakeup::gRenderer.getHeight();
	}
	if (transform.position.y < 0)
	{
		changes.position.y += JoeBidenWakeup::gRenderer.getHeight();
	}
	for (auto& child : children)
	{
		child->setChangeData(changes);
		child->update();
	}
	transform.position.x = JoeBidenWakeup::wrap((float)transform.position.x, (float)0, (float)JoeBidenWakeup::gRenderer.getWidth());
	transform.position.y = JoeBidenWakeup::wrap((float)transform.position.y, (float)0, (float)JoeBidenWakeup::gRenderer.getHeight());
	speed.x = JoeBidenWakeup::clamp<float>(speed.x, -JoeBidenWakeup::gRenderer.getWidth(), JoeBidenWakeup::gRenderer.getWidth());
	speed.y = JoeBidenWakeup::clamp<float>(speed.y, -JoeBidenWakeup::gRenderer.getHeight(), JoeBidenWakeup::gRenderer.getHeight());
	this->draw();
	return changes;
}

void JoeBidenAwoken::Player::fire()
{
	JoeBidenWakeup::Vector2 position{ (float)0, -((10 * transform.scale) + (5 * bulletSize)) };
	std::shared_ptr<JoeBidenWakeup::Model> bulletModel = (friendlyFire ? JoeBidenWakeup::gModelManager.get("weapon.txt") : JoeBidenWakeup::gModelManager.get("weapon.txt"));
	scene->add(std::make_shared<Projectile>(JoeBidenWakeup::Transform{ position.rotateR((transform.rotation)) + transform.position, transform.rotation, bulletSize },
		bulletModel, "Bullet, Player", owner,
		(JoeBidenWakeup::Vector2(0, -1).rotateR(transform.rotation) * bulletSpeed) + speed, pierce, bulletLifespan, damage));
	currentCooldown = shotCooldown;
}

void JoeBidenAwoken::Player::applyUpgrade(std::shared_ptr<Upgrade> upgrade)
{
	switch (upgrade->getFlavor())
	{
	case Flavor::TurnRateUp:
	{
		turnRate *= std::pow(1.2, upgrade->getTier());
	}
	case Flavor::TurnRateDown:
	{
		turnRate *= std::pow(0.8, upgrade->getTier());
	}
	case Flavor::FireRateUp:
	{
		shotCooldown *= std::pow(0.8, upgrade->getTier());
	}
	case Flavor::MomentumUp:
	{
		momentum *= std::pow(0.8, upgrade->getTier());
	}
	case Flavor::MomentumDown:
	{
		momentum *= std::pow(1.2, upgrade->getTier());
	}
	case Flavor::RotationMomentumUp:
	{
		rotationMomentum *= std::pow(0.8, upgrade->getTier());
	}
	case Flavor::RotationMomentumDown:
	{
		rotationMomentum *= std::pow(1.2, upgrade->getTier());
	}
	case Flavor::LifeSpanUp:
	{
		bulletLifespan *= std::pow(1.2, upgrade->getTier());
	}
	case Flavor::MaxHealthUp:
	{
		maxHealth *= std::pow(1.2, upgrade->getTier());
	}
	case Flavor::RegenUp:
	{
		regen *= std::pow(1.2, upgrade->getTier());
	}
	case Flavor::AccelerationUp:
	{
		acceleration *= (std::pow(1.2, upgrade->getTier()));
	}
	case Flavor::AccelerationDown:
	{
		acceleration *= (std::pow(0.8, upgrade->getTier()));
	}
	case Flavor::ReverseThrustUp:
	{
		reverseThrustModifier *= (std::pow(1.2, upgrade->getTier()));
	}
	case Flavor::ReverseThrustDown:
	{
		reverseThrustModifier *= (std::pow(0.8, upgrade->getTier()));
	}
	case Flavor::DamageUp:
	{
		damage *= (std::pow(1.2, upgrade->getTier()));
	}
	case Flavor::BulletSizeUp:
	{
		bulletSize *= (std::pow(1.2, upgrade->getTier()));
	}
	case Flavor::BulletSizeDown:
	{
		bulletSize *= (std::pow(0.8, upgrade->getTier()));
	}
	case Flavor::BulletSpeedUp:
	{
		bulletSpeed *= (std::pow(1.2, upgrade->getTier()));
	}
	case Flavor::BulletSpeedDown:
	{
		bulletSpeed *= (std::pow(0.8, upgrade->getTier()));
	}
	case Flavor::GlassCannon:
	{
		damage *= (std::pow(1.5, upgrade->getTier()));
		maxHealth *= (std::pow(0.5, upgrade->getTier()));
	}
	case Flavor::Tank:
	{
		maxHealth *= (std::pow(2, upgrade->getTier()));
		acceleration *= (std::pow(0.5, upgrade->getTier()));
		turnRate *= (std::pow(0.5, upgrade->getTier()));
	}
	case Flavor::MachineGun:
	{
		shotCooldown *= (std::pow(0.5, upgrade->getTier()));
		damage *= (std::pow(0.5, upgrade->getTier()));
	}
	case Flavor::Cockroach:
	{
		regen *= (std::pow(5, upgrade->getTier()));
		maxHealth *= (std::pow(0.4, upgrade->getTier()));
	}
	case Flavor::Rogue:
	{
		turnRate *= (std::pow(1.5, upgrade->getTier()));
		acceleration *= (std::pow(1.5, upgrade->getTier()));
		maxHealth *= (std::pow(0.8, upgrade->getTier()));
	}
	case Flavor::Sniper:
	{
		bulletSpeed *= (std::pow(2, upgrade->getTier()));
		damage *= (std::pow(2, upgrade->getTier()));
		shotCooldown *= (std::pow(2, upgrade->getTier()));
	}
	case Flavor::Spray:
	{
		spray = true;
	}
	case Flavor::Pierce:
	{
		pierce = true;
	}
	case Flavor::FriendlyFire:
	{
		friendlyFire = false;
	}
	case Flavor::Phoenix:
	{
		maxHealth *= (std::pow(0.8, upgrade->getTier()));
		maxLives += (upgrade->getTier());
	}
	}
	upgrade.reset();
	lives = maxLives;
	health = maxHealth;
}

