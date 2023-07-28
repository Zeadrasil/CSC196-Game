#pragma once
#include <vector>
#include "Particle.h"
namespace JoeBidenWakeup
{
	class ParticleSystem
	{
	public:
		ParticleSystem() = default;
		ParticleSystem(int maxCount)
		{
			initialize(maxCount);
		}
		void initialize(int maxCount);
		void update(float dt);
		void draw(Renderer& renderer);
		Particle* getFreeParticle();
	private:
		std::vector<Particle> particles;
	};

	extern ParticleSystem gParticleSystem;
}
