#include "Font.h"

JoeBidenWakeup::Font::~Font()
{
	if (font)
	{
		TTF_CloseFont(font);
	}
}

void JoeBidenWakeup::Font::load(std::string filename, int fontSize)
{
	font = TTF_OpenFont(filename.c_str(), fontSize);
}
