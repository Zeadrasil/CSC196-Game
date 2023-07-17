#pragma once
#include <string>
#include "SDL2-2.28.0/include/SDL.h"
namespace JoeBidenWakeup
{

	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;
		bool initialize();
		void shutdown();
		void createWindow(const std::string& title, int width, int height);
		void beginFrame();
		void endFrame();

		void setColor(int r, int g, int b, int a);
		void drawLine(int startX, int startY, int endX, int endY);
		void drawPoint(int x, int y);
		void setColor(float r, float g, float b, float a);
		void drawLine(float startX, float startY, float endX, float endY);
		void drawPoint(float x, float y);
		int getWidth() const { return width; };
		int getHeight() const { return height; };
	private:
		int width = 0;
		int height = 0;
		SDL_Renderer* renderer = nullptr;
		SDL_Window* window = nullptr;
	};

	extern Renderer gRenderer;
}

