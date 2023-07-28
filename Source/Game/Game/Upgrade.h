#pragma once
#include<string>
namespace JoeBidenAwoken
{
	enum class Flavor
	{
		TurnRateUp,
		TurnRateDown,
		FireRateUp,
		MomentumUp,
		MomentumDown,
		RotationMomentumUp,
		RotationMomentumDown,
		LifeSpanUp,
		MaxHealthUp,
		RegenUp,
		AccelerationUp,
		AccelerationDown,
		ReverseThrustUp,
		ReverseThrustDown,
		DamageUp,
		BulletSizeUp,
		BulletSizeDown,
		BulletSpeedUp,
		BulletSpeedDown,

		GlassCannon = 95,
		Tank = 96,
		MachineGun = 97,
		Cockroach = 98,
		Rogue = 99,
		Sniper = 100,

		Spray = 107,
		Pierce = 108,
		FriendlyFire = 109,
		Phoenix = 110
	};
	class Upgrade
	{
	public:
		Upgrade(Flavor flavor) : flavor{flavor}{}
		Flavor getFlavor() const { return flavor; };
		std::string getText();
		int getTier() { return tier; };
		void incrementTier() { tier++; };
		void reset() { tier = flavor != Flavor::Spray && flavor != Flavor::Pierce && flavor != Flavor::FriendlyFire ? 0 : -1; }
	private:
		Flavor flavor;
		int tier = 0;
	};

}