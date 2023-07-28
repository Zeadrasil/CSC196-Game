#pragma once
#include "Actor.h"
#include <list>
#include <memory>
namespace JoeBidenWakeup
{
	class Scene
	{
	public:
		Scene() = default;

		void update();
		void draw();
		void add(std::shared_ptr<Actor> actor);
		void remove(Actor* actor);
		void clearScene();
		Actor* get(unsigned int actorIndex);
		template<typename T>
		T* getFirst();
	private:
		std::list<std::shared_ptr<Actor>> actors;
	};
	template<typename T>
	inline T* Scene::getFirst()
	{
		for (auto& actor : actors)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result)
			{
				return result;
			}
		}
		return nullptr;
	}
}

