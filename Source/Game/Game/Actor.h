#pragma once
#include "Framework/Framework.h"
#include "Asteroids.h"
#include <memory>
namespace JoeBidenAwoken
{
	class Actor : public JoeBidenWakeup::Actor
	{
	public:
		Actor(const JoeBidenWakeup::Transform& transform, const std::shared_ptr<JoeBidenWakeup::Model> model, std::string tags, Asteroids* owner, 
			Actor* parent = nullptr, Asteroids::GameState ownerState = Asteroids::GameState::Title) 
			: JoeBidenWakeup::Actor(transform, model, tags, parent), owner{ owner }, ownerState{ ownerState } 
		{
			if (!parent)
			{
				JoeBidenWakeup::Transform location = transform;
				location.position.y += JoeBidenWakeup::gRenderer.getHeight();
				std::shared_ptr<Actor> child = std::make_shared<Actor>(location, model, tags, owner, this, ownerState);
				addChild(child);
				location.position.x += JoeBidenWakeup::gRenderer.getWidth();
				child = std::make_shared<Actor>(location, model, tags, owner, this, ownerState);
				addChild(child);
				location.position.y -= JoeBidenWakeup::gRenderer.getHeight();
				child = std::make_shared<Actor>(location, model, tags, owner, this, ownerState);
				addChild(child);
				location.position.y -= JoeBidenWakeup::gRenderer.getHeight();
				child = std::make_shared<Actor>(location, model, tags, owner, this, ownerState);
				addChild(child);
				location.position.x -= JoeBidenWakeup::gRenderer.getWidth();
				child = std::make_shared<Actor>(location, model, tags, owner, this, ownerState);
				addChild(child);
				location.position.x -= JoeBidenWakeup::gRenderer.getWidth();
				child = std::make_shared<Actor>(location, model, tags, owner, this, ownerState);
				addChild(child);
				location.position.y += JoeBidenWakeup::gRenderer.getHeight();
				child = std::make_shared<Actor>(location, model, tags, owner, this, ownerState);
				addChild(child);
				location.position.y += JoeBidenWakeup::gRenderer.getHeight();
				child = std::make_shared<Actor>(location, model, tags, owner, this, ownerState);
				addChild(child);
			}
		}

		JoeBidenWakeup::Transform update() override;
		Asteroids::GameState ownerState = Asteroids::GameState::Title;
	protected:
		Asteroids* owner;
	};

}