#include "Asteroids.h"
#include "Audio/AudioSystem.h"
#include "Input/Input.h"
#include <vector>
#include "Player.h"
#include <thread>
#include "Renderer/Render.h"
#include "Asteroid.h"
namespace JoeBidenAwoken
{
	bool Asteroids::init()
	{
		JoeBidenWakeup::seedRandom((unsigned int)time(nullptr));
		JoeBidenWakeup::setFilePath("Assets");
		JoeBidenWakeup::gAudioSystem.initialize();
		JoeBidenWakeup::gAudioSystem.addAudio("shoot", "shoot.wav");
		JoeBidenWakeup::gAudioSystem.addAudio("shoot2", "shoot2.wav");
		JoeBidenWakeup::gAudioSystem.addAudio("shoot3", "shoot3.wav");
		JoeBidenWakeup::gAudioSystem.addAudio("BG", "91476_Glorious_morning.wav");
		JoeBidenWakeup::gAudioSystem.playOneShot("BG", true);
		JoeBidenWakeup::gInputSystem.initialize();
		scene = std::make_unique<JoeBidenWakeup::Scene>(JoeBidenWakeup::Scene());
		JoeBidenWakeup::gInputSystem.initialize();
		JoeBidenWakeup::gRenderer.initialize();
		JoeBidenWakeup::gRenderer.createWindow("CSC196", 1400, 900);
		JoeBidenWakeup::gParticleSystem.initialize(256);

		upgrades.push_back(std::make_shared<Upgrade>(Flavor::TurnRateUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::TurnRateDown));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::FireRateUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::MomentumUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::MomentumDown));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::RotationMomentumUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::RotationMomentumDown));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::LifeSpanUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::MaxHealthUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::RegenUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::AccelerationUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::AccelerationDown));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::ReverseThrustUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::ReverseThrustDown));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::DamageUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::BulletSizeUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::BulletSizeDown));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::BulletSpeedUp));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::BulletSpeedDown));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::GlassCannon));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::Tank));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::MachineGun));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::Cockroach));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::Rogue));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::Sniper));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::Spray));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::Pierce));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::FriendlyFire));
		upgrades.push_back(std::make_shared<Upgrade>(Flavor::Phoenix));

		return true;
	}

	void Asteroids::shutdown()
	{
		JoeBidenWakeup::MemoryTracker::displayInfo();
		scene->clearScene();
		JoeBidenWakeup::MemoryTracker::displayInfo();
	}

	void Asteroids::update(float dt)
	{
		JoeBidenWakeup::gRenderer.beginFrame();
		JoeBidenWakeup::gTime.tick();
		JoeBidenWakeup::gInputSystem.update();
		if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_TAB))
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(1));
		}
		switch (state)
		{
		case GameState::Title:
		{
			std::shared_ptr<JoeBidenWakeup::Font> font = std::make_shared<JoeBidenWakeup::Font>("Houston Regular Demo.ttf", 48);
			std::unique_ptr<JoeBidenWakeup::Text> title = std::make_unique<JoeBidenWakeup::Text>(font);
			title->create(JoeBidenWakeup::gRenderer, "AZZTEROIDS BUT BETTER", JoeBidenWakeup::Color{ 1.0f, 1.0f, 1.0f });
			title->draw(JoeBidenWakeup::gRenderer, 525, 200);
			JoeBidenWakeup::Vector2 mousePosition = JoeBidenWakeup::gInputSystem.getMousePosition();
			bool helpSelected = mousePosition.x < 1300 && mousePosition.x > 900 && mousePosition.y > 400 && mousePosition.y < 800;
			bool playSelected = mousePosition.x < 500 && mousePosition.x > 100 && mousePosition.y > 400 && mousePosition.y < 800;
			std::shared_ptr<JoeBidenWakeup::Font> bigFont = std::make_shared<JoeBidenWakeup::Font>("Houston Regular Demo.ttf", 96);
			std::unique_ptr<JoeBidenWakeup::Text> playButton = std::make_unique<JoeBidenWakeup::Text>(playSelected ? bigFont : font);
			playButton->create(JoeBidenWakeup::gRenderer, "PLAY", JoeBidenWakeup::Color{ 1.0f, 1.0f, 1.0f });
			playButton->draw(JoeBidenWakeup::gRenderer, playSelected ? 200 : 300, playSelected ? 600 : 655);
			std::unique_ptr<JoeBidenWakeup::Text> helpButton = std::make_unique<JoeBidenWakeup::Text>(helpSelected ? bigFont : font);
			helpButton->create(JoeBidenWakeup::gRenderer, "Help", JoeBidenWakeup::Color{ 1.0f, 1.0f, 1.0f });
			helpButton->draw(JoeBidenWakeup::gRenderer, helpSelected ? 1050 : 1000, helpSelected ? 600 : 655);

			if (JoeBidenWakeup::gInputSystem.getMouseButtonDown(0) && inputTimer < 0)
			{
				if (playSelected)
				{
					state = GameState::Game;

					JoeBidenWakeup::Vector2 position{ JoeBidenWakeup::gRenderer.getWidth(), JoeBidenWakeup::gRenderer.getHeight()};
					JoeBidenWakeup::Transform transform;
					transform.position = position;
					transform.rotation = 0;
					transform.scale = 1;

					std::unique_ptr<Player> player = std::make_unique<Player>(JoeBidenWakeup::halfPi / 30, transform, JoeBidenWakeup::gModelManager.get("ship.txt"), this);
					scene->add(std::move(player));
				}
			}
			break;
		}
		case GameState::Game:
		{
			Player* player = (Player*)scene->get(0);
			if (JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_SPACE) && (!JoeBidenWakeup::gInputSystem.getPreviousKeyDown(SDL_SCANCODE_SPACE) || player->getSpray()) && player->getCurrentCooldown() <= 0)
			{
				switch (JoeBidenWakeup::random(0, 3))
				{
				case 1:
				{
					JoeBidenWakeup::gAudioSystem.playOneShot("shoot2");
					break;
				}
				case 2:
				{
					JoeBidenWakeup::gAudioSystem.playOneShot("shoot3");
					break;
				}
				default:
				{
					JoeBidenWakeup::gAudioSystem.playOneShot("shoot");
				}
				}
				player->fire();
			}
			if (JoeBidenWakeup::gInputSystem.getMouseButtonDown(0))
			{
				emitter.toggle(true);
				emitter.setLocation(JoeBidenWakeup::gInputSystem.getMousePosition());
			}
			else
			{
				emitter.toggle(false);
			}
			emitter.update();
			JoeBidenWakeup::gParticleSystem.update(JoeBidenWakeup::gTime.getDeltaTime());
			JoeBidenWakeup::gParticleSystem.draw(JoeBidenWakeup::gRenderer);
			spawnHazards();
			break;
		}
		case GameState::Paused:
			break;
		case GameState::Item:
		{
			std::shared_ptr<JoeBidenWakeup::Font> font = std::make_shared<JoeBidenWakeup::Font>("Houston Regular Demo.ttf", 48);
			std::unique_ptr<JoeBidenWakeup::Text> text = std::make_unique<JoeBidenWakeup::Text>(font);


			text->create(JoeBidenWakeup::gRenderer, upgrades.at(availableUpgrades[0])->getText(), JoeBidenWakeup::Color{ 1.0f, 1.0f, 1.0f });
			text->draw(JoeBidenWakeup::gRenderer, 50, 100);
			text->create(JoeBidenWakeup::gRenderer, upgrades.at(availableUpgrades[1])->getText(), JoeBidenWakeup::Color{ 1.0f, 1.0f, 1.0f });
			text->draw(JoeBidenWakeup::gRenderer, JoeBidenWakeup::gRenderer.getWidth() / 2 + 50, 100);
			text->create(JoeBidenWakeup::gRenderer, upgrades.at(availableUpgrades[2])->getText(), JoeBidenWakeup::Color{ 1.0f, 1.0f, 1.0f });
			text->draw(JoeBidenWakeup::gRenderer, 50, JoeBidenWakeup::gRenderer.getHeight() / 2 + 100);
			text->create(JoeBidenWakeup::gRenderer, upgrades.at(availableUpgrades[3])->getText(), JoeBidenWakeup::Color{ 1.0f, 1.0f, 1.0f });
			text->draw(JoeBidenWakeup::gRenderer, JoeBidenWakeup::gRenderer.getWidth() / 2 + 50, JoeBidenWakeup::gRenderer.getHeight() / 2 + 100);

			int selected = -1;
			if (inputTimer < 0 && JoeBidenWakeup::gInputSystem.getMouseButtonDown(0))
			{
				if (JoeBidenWakeup::gInputSystem.getMousePosition().x < JoeBidenWakeup::gRenderer.getWidth() / 2)
				{
					if (JoeBidenWakeup::gInputSystem.getMousePosition().y < JoeBidenWakeup::gRenderer.getHeight() / 2)
					{
						selected = 0;
					}
					else
					{
						selected = 2;
					}
				}
				else
				{
					if (JoeBidenWakeup::gInputSystem.getMousePosition().y < JoeBidenWakeup::gRenderer.getHeight() / 2)
					{
						selected = 1;
					}
					else
					{
						selected = 3;
					}
				}
			}

			if (selected != -1)
			{
				((Player*)scene->get(0))->applyUpgrade(upgrades.at(availableUpgrades[selected]));
				inputTimer = 1;
				state = GameState::Game;
			}
			break;
		}
		case GameState::Dead:
		{
			std::shared_ptr<JoeBidenWakeup::Font> font = std::make_shared<JoeBidenWakeup::Font>("Houston Regular Demo.ttf", 48);
			std::unique_ptr<JoeBidenWakeup::Text> text = std::make_unique<JoeBidenWakeup::Text>(font);
			text->create(JoeBidenWakeup::gRenderer, "Dead", JoeBidenWakeup::Color{ 1.0f, 1.0f, 1.0f });
			text->draw(JoeBidenWakeup::gRenderer, 50, 100);
			break;
		}
		default:
			break;
		}
		inputTimer -= JoeBidenWakeup::gTime.getDeltaTime();
		scene->update();
		JoeBidenWakeup::gRenderer.setColor(0, 0, 0, 0);
		JoeBidenWakeup::gRenderer.endFrame();
	}

	void Asteroids::draw(JoeBidenWakeup::Renderer& renderer)
	{
	}
	void Asteroids::spawnHazards()
	{
		asteroidSpawnTimer += JoeBidenWakeup::gTime.getDeltaTime();
		while (asteroidSpawnTimer > asteroidSpawnRate)
		{
			asteroidSpawnTimer -= asteroidSpawnRate;
			if (JoeBidenWakeup::random(2) == 1)
			{
				scene->add(std::make_shared<Asteroid>(
					JoeBidenWakeup::Transform{ JoeBidenWakeup::Vector2{0, JoeBidenWakeup::random(0, JoeBidenWakeup::gRenderer.getHeight())}, 0, (float)asteroidSize },
					this, JoeBidenWakeup::randomFloat(JoeBidenWakeup::twoPi) - JoeBidenWakeup::pi,
					JoeBidenWakeup::Vector2{ (float)JoeBidenWakeup::randomFloat(JoeBidenWakeup::gRenderer.getWidth() / 200), (float)JoeBidenWakeup::gRenderer.getHeight() / 200 }));
			}
			else
			{
				scene->add(std::make_shared<Asteroid>(
					JoeBidenWakeup::Transform{ JoeBidenWakeup::Vector2{JoeBidenWakeup::random(0, JoeBidenWakeup::gRenderer.getWidth()), 0}, 0, (float)asteroidSize },
					this, JoeBidenWakeup::randomFloat(JoeBidenWakeup::twoPi) - JoeBidenWakeup::pi,
					JoeBidenWakeup::Vector2{ (float)JoeBidenWakeup::randomFloat(JoeBidenWakeup::gRenderer.getWidth() / 200), (float)JoeBidenWakeup::gRenderer.getHeight() / 200 }));
			}
			asteroidSpawnRate *= 0.95;
			if (asteroidSpawnRate < 5)
			{
				endRound();
				asteroidSpawnRate = 10;
				asteroidSize++;
			}
		}
	}
	void Asteroids::endRound()
	{
		int index = 0, count = 0;
		while (count < 4)
		{
			index = JoeBidenWakeup::random(111);
			if (index > 106)
			{
				index -= 82;
			}
			else if (index > 94)
			{
				index -= 76;
				index = 19 + (index - 19) % 6;
			}
			else
			{
				index %= 19;
			}

			if (upgrades.at(index)->getTier() != -1)
			{
				bool valid = true;
				for (int i = 0; i < count && valid; i++)
				{
					valid = availableUpgrades[i] != index;
				}
				availableUpgrades[count] = index;
				count++;
			}
		}
		state = GameState::Item;
		inputTimer = 2;
	}
}