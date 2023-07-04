#include "FileIO.h"

std::string JoeBidenWakeup::getFilePath()
{
	return std::filesystem::current_path().string();
}

bool JoeBidenWakeup::setFilePath(const std::filesystem::path& path)
{
	std::error_code ec;
	std::filesystem::current_path(path, ec);
	return ec.value() == 0;
}

bool JoeBidenWakeup::fileExists(const std::filesystem::path& path)
{
	return std::filesystem::exists(path);
}

bool JoeBidenWakeup::getFileSize(const std::filesystem::path& path, size_t& size)
{
	std::error_code ec;
	size = std::filesystem::file_size(path, ec);
	return ec.value() == 0;
}

bool JoeBidenWakeup::readFile(const std::filesystem::path& path, std::string& buffer)
{
	if (fileExists(path))
	{
		size_t size;
		if (getFileSize(path, size))
		{
			buffer.resize(size);
			std::ifstream stream(path);
			stream.read(buffer.data(), size);
			return true;
		}
	}
	return false;
}
