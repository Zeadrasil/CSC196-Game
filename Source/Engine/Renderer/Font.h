#pragma once
#include <string>
#include "SDL2-2.28.0/include/SDL_ttf.h"
namespace JoeBidenWakeup
{
	class Font
	{
	public:
		Font(std::string filename, int fontSize)
		{
			load(filename, fontSize);
		}
		~Font();
		void load(std::string filename, int fontSize);
		friend class Text;

	private:
		_TTF_Font* font = nullptr;
	};

}