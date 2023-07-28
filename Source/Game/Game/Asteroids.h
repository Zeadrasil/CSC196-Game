#pragma once
#include "Framework/Framework.h"
#include "Framework/Emitter.h"
#include "Upgrade.h"
namespace JoeBidenAwoken
{
	class Asteroids : public JoeBidenWakeup::Game
	{
	public:
		enum class GameState
		{
			Title,
			Game,
			Paused,
			Item,
			Dead
		};

		// Inherited via Game
		virtual bool init() override;
		virtual void shutdown() override;
		virtual void update(float dt) override;
		virtual void draw(JoeBidenWakeup::Renderer& renderer) override;
		GameState getState() { return state; }
		float getInputTimer() { return inputTimer; };
		friend class Player;
	private:
		GameState state = GameState::Title;
		JoeBidenWakeup::Emitter emitter;
		float asteroidSpawnRate = 6, asteroidSpawnTimer = 6;
		float enemySpawnRate = 60, enemySpawnTimer = 60;
		int asteroidSize = 1;
		std::vector<std::shared_ptr<Upgrade>> upgrades;
		void spawnHazards();
		void endRound();
		int* availableUpgrades = new int[4];
		float inputTimer = 0;
	};

}