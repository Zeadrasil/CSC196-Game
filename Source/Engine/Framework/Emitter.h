#pragma once
#include "Framework/Actor.h"
namespace JoeBidenWakeup
{
	struct EmitterData
	{
		float spawnRate = 0;
		float spawnRateTimer = 0;
		bool burst = false;
		size_t burstCount = 0;
		float lifetimeMin = 0;
		float lifetimeMax = 0;
		float speedMin = 0;
		float speedMax = 0;
		float damping = 0;
		float angle = 0;
		float angleRange = 0;
		Color color;
	};
	class Emitter : public Actor
	{
	public:
		Emitter() = default;
		Emitter(const Transform& transform, const EmitterData& data) : Actor{ transform, nullptr, "Emitter"}, data{ data }, isActive {true}
		{}
		Transform update() override;
		void draw(Renderer& renderer);
		bool active() { return isActive; };
		void toggle(bool activity) { isActive = activity; };
		void setLocation(Vector2 location) { transform.position = location; };
		void setSpeedMin(float newMin) { data.speedMin = newMin; };
		void setSpeedMax(float newMax) { data.speedMax = newMax; };
		void setAngle(float newAngle) { data.angle = newAngle; };
		void setAngleRange(float newRange) { data.angle = newRange; };
		void setColor(Color newColor) { data.color = newColor; };
	private:
		void emit();
	private:
		EmitterData data;
		bool isActive = true;
	};

}