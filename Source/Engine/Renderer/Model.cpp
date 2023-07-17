#include "Model.h"
#include<sstream>

void JoeBidenWakeup::Model::Draw(const Vector2& position, float radianRotation, float scale)
{
	if (points.size() < 2)
	{
		return;
	}
	for (size_t index = 0; index < points.size() - 1; index++)
	{
		Vector2 p1 = (points[index] * scale).rotateR(radianRotation) + position, p2 = (points[index + 1] * scale).rotateR(radianRotation) + position;
		gRenderer.drawLine(p1.x, p1.y, p2.x, p2.y);
	}
	Vector2 p1 = (points[points.size() - 1] * scale).rotateR(radianRotation) + position, p2 = (points[0] * scale).rotateR(radianRotation) + position;
	gRenderer.drawLine(p1.x, p1.y, p2.x, p2.y);
}

void JoeBidenWakeup::Model::Draw(const Transform& transform)
{
	Draw(transform.position, transform.rotation, transform.scale);
}

bool JoeBidenWakeup::Model::load(const std::string& filename)
{
	std::string buffer;
	JoeBidenWakeup::readFile(filename, buffer);

	std::istringstream stream(buffer);

	std::string line;
	std::getline(stream, line);

	int numPoints = std::stoi(line);

	for (int i = 0; i < numPoints; i++)
	{
		Vector2 point;
		stream >> point;
		points.push_back(point);
	}

	return true;
}
