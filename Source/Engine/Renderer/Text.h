#pragma once
#include <memory>
#include "Font.h"
#include "Renderer.h"
#include "Core/Color.h"
namespace JoeBidenWakeup
{
	class Text
	{
	public:
		Text(std::shared_ptr<Font> font) : font{ font } {}
		~Text();
		void create(Renderer& renderer, const std::string& text, const Color& color);
		void draw(Renderer& renderer, int x, int y);
	private:
		std::shared_ptr<Font> font;
		struct SDL_Texture* texture = nullptr;
	};

}