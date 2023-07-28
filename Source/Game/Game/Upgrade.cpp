#include "Upgrade.h"
#include <cmath>
std::string JoeBidenAwoken::Upgrade::getText()
{
    switch (flavor)
    {
    case Flavor::TurnRateUp:
    {
        return "Increase Turn Rate\nTurn Rate *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::TurnRateDown:
    {
        return "Decrease Turn Rate\nTurn Rate *" + std::to_string(std::pow(0.8, tier));
    }
    case Flavor::FireRateUp:
    {
        return "Increase Fire Rate\nFire Cooldown *" + std::to_string(std::pow(0.8, tier));
    }
    case Flavor::MomentumUp:
    {
        return "Increase Momentum\nSpeed Loss *" + std::to_string(std::pow(0.8, tier));
    }
    case Flavor::MomentumDown:
    {
        return "Decrease Momentum\nSpeed Loss *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::RotationMomentumUp:
    {
        return "Increase Rotation Momentum\nRotation Speed Loss *" + std::to_string(std::pow(0.8, tier));
    }
    case Flavor::RotationMomentumDown:
    {
        return "Decrease Rotation Momentum\nRotation Speed Loss *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::LifeSpanUp:
    {
        return "Increase Bullet Lifespan\nLifespan *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::MaxHealthUp:
    {
        return "Increase Max Health\nMax Health *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::RegenUp:
    {
        return "Increase Health Regeneration\nRegeneration *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::AccelerationUp:
    {
        return "Increase Acceleration\nAcceleration *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::AccelerationDown:
    {
        return "Decrease Acceleration\nAcceleration *" + std::to_string(std::pow(0.8, tier));
    }
    case Flavor::ReverseThrustUp:
    {
        return "Increase Backwards Acceleration\nReverse Thrust *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::ReverseThrustDown:
    {
        return "Decrease BackwardsAcceleration\nReverse Thrust *" + std::to_string(std::pow(0.8, tier));
    }
    case Flavor::DamageUp:
    {
        return "Increase Damage\nDamage *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::BulletSizeUp:
    {
        return "Increase Bullet Size\nBullet Size *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::BulletSizeDown:
    {
        return "Decrease BulletSize\nBullet Size *" + std::to_string(std::pow(0.8, tier));
    }
    case Flavor::BulletSpeedUp:
    {
        return "Increase Bullet Speed\nBullet Speed *" + std::to_string(std::pow(1.2, tier));
    }
    case Flavor::BulletSpeedDown:
    {
        return "Decrease Bullet Speed\nBullet Speed *" + std::to_string(std::pow(0.8, tier));
    }
    case Flavor::GlassCannon:
    {
        return "Glass Cannon\nDamage *" + std::to_string(std::pow(1.5, tier)) + "\nHealth *" + std::to_string(std::pow(0.5, tier));
    }
    case Flavor::Tank:
    {
        return "Tank\nHealth *" + std::to_string(std::pow(2, tier)) + "\nAcceleration *" + std::to_string(std::pow(0.5, tier)) + "\nTurn Rate *" + std::to_string(std::pow(0.5, tier));
    }
    case Flavor::MachineGun:
    {
        return "Machine Gun\nFire Cooldown *" + std::to_string(std::pow(0.5, tier)) + "\nDamage *" + std::to_string(std::pow(0.5, tier));
    }
    case Flavor::Cockroach:
    {
        return "Cockroach\nRegeneration *" + std::to_string(std::pow(5, tier)) + "\nMax Health *" + std::to_string(std::pow(0.4, tier));
    }
    case Flavor::Rogue:
    {
        return "Rogue\nTurn Rate *" + std::to_string(std::pow(1.5, tier)) + "\nAcceleration *" + std::to_string(std::pow(1.5, tier)) + "\nMax Health *" + std::to_string(std::pow(0.8, tier));
    }
    case Flavor::Sniper:
    {
        return "Sniper\nBullet Speed *" + std::to_string(std::pow(2, tier)) + "\nDamage *" + std::to_string(std::pow(2, tier)) + "\nShot Cooldown *" + std::to_string(std::pow(2, tier));
    }
    case Flavor::Spray:
    {
        return "Enable Continuous Firing";
    }
    case Flavor::Pierce:
    {
        return "Enable Pierce";
    }
    case Flavor::FriendlyFire:
    {
        return "Disable Friendly Fire";
    }
    case Flavor::Phoenix:
    {
        return "Phoenix\nHealth *" + std::to_string(std::pow(0.8, tier)) + "\nLives +" + std::to_string(tier);
    }
    default:
        return "This is empty, which should not be possible";
    }
}
