#include "Text.h"

JoeBidenWakeup::Text::~Text()
{
	if (texture)
	{
		SDL_DestroyTexture(texture);
	}
}

void JoeBidenWakeup::Text::create(Renderer& renderer, const std::string& text, const Color& color)
{
	SDL_Color c{ Color::toInt(color.r), Color::toInt(color.g), Color::toInt(color.b), Color::toInt(color.a) };
	SDL_Surface* surface = TTF_RenderText_Solid(font->font, text.c_str(), c);
	texture = SDL_CreateTextureFromSurface(renderer.renderer, surface);
	SDL_FreeSurface(surface);
}

void JoeBidenWakeup::Text::draw(Renderer& renderer, int x, int y)
{
	int width, height;
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	SDL_Rect rect{ x, y, width, height };
	SDL_RenderCopy(renderer.renderer, texture, NULL, &rect);
}
