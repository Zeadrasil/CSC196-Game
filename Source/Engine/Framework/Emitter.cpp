#include "Emitter.h"
#include "Renderer/Particle.h"
#include "Core/Random.h"
#include "Renderer/ParticleSystem.h"
namespace JoeBidenWakeup
{
	Transform Emitter::update()
	{
		Actor::update();
		// create burst particles
		if (data.burst && isActive)
		{
			data.burst = false;
			for (int i = 0; i < data.burstCount; i++)
			{
				emit();
			}
		}
		// create particles based on rate
		if (data.spawnRate > 0.0f && isActive)
		{
			data.spawnRateTimer += gTime.getDeltaTime();
			while (data.spawnRateTimer > 0)
			{
				emit();
				data.spawnRateTimer -= (1 / data.spawnRate);
			}
		}
		return { {0, 0}, 0, 0 };
	}
	void Emitter::emit()
	{
		Particle* particle = gParticleSystem.getFreeParticle();
		if (particle)
		{
			ParticleData particleData;
			particleData.lifetime = randomFloat(data.lifetimeMin, data.lifetimeMax);
			particleData.position = transform.position;
			particleData.prevPosition = particleData.position;
			particleData.color = data.color;
			float angle = transform.rotation + data.angle + randomFloat(-data.angleRange, data.angleRange);
			Vector2 direction = Vector2{ 0, -1 }.rotateR(angle);
			particleData.velocity = direction * randomFloat(data.speedMin, data.speedMax);
			particleData.damping = data.damping;
			particle->initialize(particleData);
		}
	}
}