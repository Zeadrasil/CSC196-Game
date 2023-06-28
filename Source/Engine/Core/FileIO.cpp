#include "FileIO.h"

std::string JoeBidenWakeup::getFilePath()
{
	return std::filesystem::current_path().string();
}
