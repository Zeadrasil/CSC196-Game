#pragma once
#include <memory>
namespace JoeBidenWakeup
{
	class Game
	{
	public:
		Game() = default;
		virtual ~Game() = default;

		virtual bool init() = 0;
		virtual void shutdown() = 0;
		virtual void update(float dt) = 0;
		virtual void draw(class Renderer& renderer) = 0;
		int getScore() const { return score; };
		void addScore(int scoreToAdd) { score += scoreToAdd; };

		int getLives() const { return lives; };
		int addLives(int livesToAdd) { lives += livesToAdd; };

	protected:
		int score = 0;
		int lives = 0;
		std::unique_ptr<class Scene> scene;
	};
}