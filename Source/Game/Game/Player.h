#pragma once
#include "Actor.h"
namespace JoeBidenAwoken
{
	class Player : public Actor
	{
	public:
		Player(JoeBidenWakeup::Vector2 speed, float turnRate, const JoeBidenWakeup::Transform& transform, const JoeBidenWakeup::Model model) : Actor{ transform, model }, speed{speed}, turnRate{turnRate}
		{

		}
		Player(Player leader, JoeBidenWakeup::Vector2 speed, float turnRate, const JoeBidenWakeup::Transform& transform, const JoeBidenWakeup::Model model) : Actor{ transform, model }, speed{ speed }, turnRate{ turnRate }
		{

		}
		Player() = default;
		JoeBidenWakeup::Transform update() override;
		float rotating = 0;
	private:
		JoeBidenWakeup::Vector2 speed = 0;
		float turnRate = 0;
	};
}

