#include "Player.h"
#include "Input/InputSystem.h"

JoeBidenWakeup::Transform JoeBidenAwoken::Player::update()
{
	float accelerationModifier = JoeBidenWakeup::randomFloat(0.9, 1.1);
	float rotationModifier = JoeBidenWakeup::randomFloat(0.9, 1.1);
	float deltaTime = JoeBidenWakeup::gTime.getDeltaTime();
	if (JoeBidenWakeup::gInputSystem.getMouseButtonDown(0))
	{
		rotating += ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position).rotateR(-transform.rotation + JoeBidenWakeup::halfPi).angle()) * deltaTime * turnRate * 0.5 * rotationModifier;
		while (transform.rotation > JoeBidenWakeup::twoPi)
		{
			transform.rotation -= JoeBidenWakeup::twoPi;
		}
		while (transform.rotation < -JoeBidenWakeup::twoPi)
		{
			transform.rotation += JoeBidenWakeup::twoPi;
		}
		float relativeAngle = ((int)(JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position).rotateR(-transform.rotation + JoeBidenWakeup::halfPi).angle());
		if (relativeAngle < 0)
		{

			if (relativeAngle < JoeBidenWakeup::halfPi)
			{
				JoeBidenWakeup::Vector2 increase = ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position) * deltaTime * ((JoeBidenWakeup::halfPi - relativeAngle) / 50));
				speed += increase.rotateR(-relativeAngle) * accelerationModifier;
			}
			else
			{
				JoeBidenWakeup::Vector2 increase = ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position) * deltaTime * ((JoeBidenWakeup::halfPi - relativeAngle) / 100));
				speed += increase.rotateR(-relativeAngle + JoeBidenWakeup::pi) * accelerationModifier;
			}
		}
		else
		{

			if (relativeAngle < JoeBidenWakeup::halfPi)
			{
				JoeBidenWakeup::Vector2 increase = ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position) * deltaTime * ((JoeBidenWakeup::halfPi + relativeAngle) / 50));
				speed += increase.rotateR(-relativeAngle) * accelerationModifier;
			}
			else
			{
				JoeBidenWakeup::Vector2 increase = ((JoeBidenWakeup::gInputSystem.getMousePosition() - transform.position) * deltaTime * ((JoeBidenWakeup::halfPi + relativeAngle) / 100));
				speed += increase.rotateR(-relativeAngle + JoeBidenWakeup::pi) * accelerationModifier;
			}
		}
	}
	else
	{
		if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_W) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_UP))
		{
			speed -= JoeBidenWakeup::Vector2{ (float)0, (float)10 * deltaTime }.rotateR(transform.rotation) * accelerationModifier;
		}
		if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_S) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_DOWN))
		{
			speed += JoeBidenWakeup::Vector2{ (float)0, (float)5 * deltaTime }.rotateR(transform.rotation) * accelerationModifier;
		}
		if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_A) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_LEFT))
		{
			rotating -= turnRate * deltaTime * rotationModifier;
		}
		if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_D) || JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_RIGHT))
		{
			rotating += turnRate * deltaTime * rotationModifier;
		}
	}
	JoeBidenWakeup::Transform change{ speed, rotating, 0 };
	speed *= 0.9999999999 * (1 - JoeBidenWakeup::gTime.getDeltaTime());
	rotating *= 0.9999 * (1 - JoeBidenWakeup::gTime.getDeltaTime());
	transform.position += change.position;
	transform.rotation += change.rotation;
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
	transform.position.x = JoeBidenWakeup::wrap((float)transform.position.x, (float)0, (float)JoeBidenWakeup::gRenderer.getWidth());
	transform.position.y = JoeBidenWakeup::wrap((float)transform.position.y, (float)0, (float)JoeBidenWakeup::gRenderer.getHeight());
	speed.x = JoeBidenWakeup::clamp<float>(speed.x, -JoeBidenWakeup::gRenderer.getWidth(), JoeBidenWakeup::gRenderer.getWidth());
	speed.y = JoeBidenWakeup::clamp<float>(speed.y, -JoeBidenWakeup::gRenderer.getHeight(), JoeBidenWakeup::gRenderer.getHeight());
	this->draw();
	return change;
}

