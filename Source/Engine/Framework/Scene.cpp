#include "Scene.h"
namespace JoeBidenWakeup
{
	void Scene::update()
	{
		auto iter = actors.begin();
		while (iter != actors.end())
		{
			iter->get()->update();
			if (iter->get()->isDestroyed())
			{
				iter = actors.erase(iter);
			}
			else
			{
				auto iter2 = std::next(iter, 1);
				while (iter2 != actors.end())
				{
					float bruh = iter->get()->transform.position.x;
					float distance = (*iter)->transform.position.distance((*iter2)->transform.position);
					float radii = (*iter)->getRadius() + (*iter2)->getRadius();
					if ( distance < radii && !(*iter2)->isDestroyed())
					{
						(*iter)->onCollision(iter2->get());
						(*iter2)->onCollision(iter->get());
					}
					iter2++;
				}
				iter++;
			}
		}


	}

	void Scene::draw()
	{
		for (auto& actor : actors)
		{
			actor->draw();
		}
	}

	void Scene::add(std::shared_ptr<Actor> actor)
	{
		actor->scene = this;
		actors.push_back(actor);
	}

	void Scene::remove(Actor* actor)
	{
		actor->scene = nullptr;
		//actors.remove(actor);
	}

	void Scene::clearScene()
	{
		actors.clear();
	}
	Actor* Scene::get(unsigned int actorIndex)
	{
		if (actorIndex < actors.size())
		{
			int index = 0;
			auto iter = actors.begin();
			while (iter != actors.end())
			{
				if (index == actorIndex)
				{
					return iter->get();
				}
				else
				{
					iter++;
				}
			}
		}
		return nullptr;
	}
}
