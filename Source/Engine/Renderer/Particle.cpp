#include "Particle.h"

void JoeBidenWakeup::Particle::update(float dt)
{
	data.lifetime -= dt;
	if (data.lifetime <= 0)
	{
		isActive = false;
		return;
	}

	data.prevPosition = data.position;
	data.position += data.velocity * dt;
	data.velocity *= std::pow(1.0f - data.damping, dt);
}

void JoeBidenWakeup::Particle::draw(Renderer& renderer)
{
	renderer.setColor(Color::toInt(data.color.r), Color::toInt(data.color.g), Color::toInt(data.color.b), Color::toInt(data.color.a));
	renderer.drawLine(data.position.x, data.position.y, data.prevPosition.x, data.prevPosition.y);
}
