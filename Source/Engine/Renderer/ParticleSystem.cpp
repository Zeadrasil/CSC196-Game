#include "ParticleSystem.h"
namespace JoeBidenWakeup
{
	ParticleSystem gParticleSystem;
	void ParticleSystem::initialize(int maxCount)
	{
		particles = std::vector<Particle>();
		particles.resize(maxCount);
		for (int i = 0; i < maxCount; i++)
		{
			particles.push_back(Particle());
		}
	}
	void ParticleSystem::update(float dt)
	{
		for (auto& particle : particles)
		{
			if (particle.isActive)
			{
				particle.update(dt);
			}
		}
	}
	void ParticleSystem::draw(Renderer& renderer)
	{
		for (auto& particle : particles)
		{
			if (particle.isActive)
			{
				particle.draw(renderer);
			}
		}
	}
	Particle* ParticleSystem::getFreeParticle()
	{
		for (auto& particle : particles)
		{
			if (!particle.isActive)
			{
				return &particle;
			}
		}
		return nullptr;
	}
}