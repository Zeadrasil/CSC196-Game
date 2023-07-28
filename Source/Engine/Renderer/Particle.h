#pragma once
#include "Core/Vector2.h"
#include "Core/Color.h"
#include "Renderer.h"
namespace JoeBidenWakeup
{
	struct ParticleData
	{
		Vector2 position;
		Vector2 prevPosition;
		Vector2 velocity;
		float damping = 0;
		Color color;
		float lifetime = 0;
	};
	class Particle
	{
	public:
		Particle() = default;
		void initialize(const ParticleData& data)
		{
			this->data = data;
			isActive = true;
		}
		void update(float dt);
		void draw(Renderer& renderer);
		friend class ParticleSystem;
		friend class Emitter;
	private:
		ParticleData data;
		bool isActive = false;
	};


}