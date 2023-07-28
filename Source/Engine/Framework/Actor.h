#pragma once
#include "Core/Core.h"
#include "Renderer/Render.h"
#include <list>
namespace JoeBidenWakeup
{
	class Actor
	{
	public:
		Actor(const JoeBidenWakeup::Transform& transform, const std::shared_ptr<Model> model, std::string tags, Actor* parent = nullptr) : transform{ transform }, model{ model }, tags { tags }, parent {parent}
		{
		}
		Actor() = default;
		virtual JoeBidenWakeup::Transform update();
		virtual void draw();
		void setChangeData(JoeBidenWakeup::Transform change);

		void addChild(std::shared_ptr<Actor> actor);
		void removeChild(std::shared_ptr<Actor> actor);
		void removeChildren();
		class Scene* scene = nullptr;
		bool isDestroyed() { return destroyed; };
		friend class Scene;
		float getRadius() { return model->getRadius() * transform.scale; };
		virtual void onCollision(Actor* other) { if(parent) parent->onCollision(other); };
		std::string tags = "";
		JoeBidenWakeup::Transform getChange() const { return change; };
	protected:
		JoeBidenWakeup::Transform transform;
		JoeBidenWakeup::Transform change;
		std::shared_ptr<Model> model;
		std::list<std::shared_ptr<Actor>> children = std::list<std::shared_ptr<Actor>>();
		Actor* parent;
		std::string type = "Actor";
		bool destroyed = false;
		float remainingLifespan = -1;
	};
}

