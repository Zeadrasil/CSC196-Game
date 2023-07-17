#include "Renderer.h"
#include "SDL2-2.28.0/include/SDL.h"

namespace JoeBidenWakeup
{
	Renderer gRenderer;
	bool Renderer::initialize()
	{
		SDL_Init(SDL_INIT_VIDEO);
		return true;
	}
	void Renderer::shutdown()
	{
	}
	void Renderer::createWindow(const std::string& title, int width, int height)
	{
		this->width = width;
		this->height = height;

		window = SDL_CreateWindow(title.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}
	void Renderer::beginFrame()
	{
		SDL_RenderClear(renderer);
	}
	void Renderer::endFrame()
	{
		SDL_RenderPresent(renderer);
	}
	void Renderer::setColor(int r, int g, int b, int a)
	{
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
	}
	void Renderer::drawLine(int startX, int startY, int endX, int endY)
	{
		SDL_RenderDrawLine(renderer, startX, startY, endX, endY);
	}
	void Renderer::drawPoint(int x, int y)
	{
		SDL_RenderDrawPoint(renderer, x, y);
	}
	void Renderer::setColor(float r, float g, float b, float a)
	{
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
	}
	void Renderer::drawLine(float startX, float startY, float endX, float endY)
	{
		SDL_RenderDrawLineF(renderer, startX, startY, endX, endY);
	}
	void Renderer::drawPoint(float x, float y)
	{
		SDL_RenderDrawPointF(renderer, x, y);
	}
}
