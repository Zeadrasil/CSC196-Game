#include <iostream>
#include<vector>
#include "Core/Core.h"
#include "Renderer/Render.h"
#include "Input/Input.h"
#include <thread>
#include "Framework/Actor.h"
#include "Player.h"
#include "Framework/Scene.h"
#include "Audio/AudioSystem.h"
#include <memory>
using namespace std;
class Star
{
public:
	JoeBidenWakeup::Vector2 pos;
	JoeBidenWakeup::Vector2 vel;
	Star(JoeBidenWakeup::Vector2 position, JoeBidenWakeup::Vector2 velocity)
	{
		pos = position;
		vel = velocity;
	}
	void update()
	{
		pos += vel;
	}
};

int main(int argc, char* argv[])
{
	//cout << "enable rotation";
	/*for (int i = 0; i < 1000000; i++)
	{
		int* p = new int;
		delete p;
	}

	cout << "Hello World";
	JoeBidenWakeup::seedRandom((unsigned int)time(nullptr));
	cout << "\n";
	cout << JoeBidenWakeup::getFilePath() << endl;
	cout << JoeBidenWakeup::setFilePath("Assets") << endl;
	size_t size = 0;
	JoeBidenWakeup::getFileSize("game.txt", size);
	cout << size << endl;;
	std::string fileText;
	JoeBidenWakeup::readFile("game.txt", fileText);
	cout << fileText << endl;
	JoeBidenWakeup::memoryTracker.displayInfo();
	int* p = new int;
	JoeBidenWakeup::memoryTracker.displayInfo();
	delete p;
	JoeBidenWakeup::memoryTracker.displayInfo();


	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000000; i++)
	{
	}
	auto end = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

	JoeBidenWakeup::Time timer;
	for (int i = 0; i < 100000000; i++) {}
	cout << timer.GetElapsedSeconds();*/
	/*
	vector<JoeBidenWakeup::Vector2> points;
	for (int i = 0; i < 100; i++)
	{
		points.push_back(JoeBidenWakeup::Vector2(JoeBidenWakeup::random(JoeBidenWakeup::gRenderer.getWidth(), JoeBidenWakeup::random(JoeBidenWakeup::gRenderer.getHeight()))));
	}
	vector<Star> stars;
	for (int i = 0; i < 20; i++)
	{
		for (int i2 = 0; i2 < 20; i2++)
		{
			stars.push_back(Star(JoeBidenWakeup::Vector2(i, i2), JoeBidenWakeup::Vector2(1, 1)));
		}
	}
	JoeBidenWakeup::Vector2 starAcceleration;
	JoeBidenWakeup::Vector2 velocity;
	while (true)
	{
		starAcceleration.x = JoeBidenWakeup::random(-1, 2) * 0.5;
		
		JoeBidenWakeup::Vector2 pos(JoeBidenWakeup::random(JoeBidenWakeup::gRenderer.getWidth(), JoeBidenWakeup::random(JoeBidenWakeup::gRenderer.getHeight())));
	JoeBidenWakeup::gRenderer.setColor(JoeBidenWakeup::random((unsigned int)256), JoeBidenWakeup::random((unsigned int)256), JoeBidenWakeup::random((unsigned int)256), JoeBidenWakeup::random((unsigned int)256));
	for (auto point : points)
	{
		JoeBidenWakeup::gRenderer.drawPoint(point.x, point.y);
	}
	for (auto& point : points)
	{
		velocity = JoeBidenWakeup::Vector2(JoeBidenWakeup::random(-10, 10), JoeBidenWakeup::random(-10, 10));
		point += velocity;
		if (point.x > JoeBidenWakeup::gRenderer.getWidth())
		{
			point.x = 0;
		}
		else if (point.x < 0)
		{
			point.x = JoeBidenWakeup::gRenderer.getWidth();
		}
		if (point.y > JoeBidenWakeup::gRenderer.getHeight())
		{
			point.y = 0;
		}
		else if (point.y < 0)
		{
			point.y = JoeBidenWakeup::gRenderer.getHeight();
		}
	}
	for (int i = 0; i < 1; i++)
	{
		//JoeBidenWakeup::gRenderer.drawPoint(JoeBidenWakeup::random((unsigned int)JoeBidenWakeup::gRenderer.getWidth()), JoeBidenWakeup::random((unsigned int)JoeBidenWakeup::gRenderer.getHeight()));
	}
	for (int i = 0; i < 1000; i++)
	{
		//JoeBidenWakeup::gRenderer.drawLine(JoeBidenWakeup::random((unsigned int)JoeBidenWakeup::gRenderer.getWidth()), JoeBidenWakeup::random((unsigned int)JoeBidenWakeup::gRenderer.getHeight()), JoeBidenWakeup::random((unsigned int)JoeBidenWakeup::gRenderer.getWidth()), JoeBidenWakeup::random((unsigned int)JoeBidenWakeup::gRenderer.getHeight()));
	}
	starAcceleration.y = JoeBidenWakeup::random(-1, 2) * 0.5;
	for (auto& star : stars)
	{
		JoeBidenWakeup::gRenderer.drawPoint(star.pos.x, star.pos.y);
		star.update();
		star.vel += starAcceleration;
		if (star.pos.x > JoeBidenWakeup::gRenderer.getWidth())
		{
			star.pos.x -= JoeBidenWakeup::gRenderer.getWidth();
		}
		else if (star.pos.x < 0)
		{
			star.pos.x += JoeBidenWakeup::gRenderer.getWidth();
		}
		if (star.pos.y > JoeBidenWakeup::gRenderer.getHeight())
		{
			star.pos.y -= JoeBidenWakeup::gRenderer.getHeight();
		}
		else if (star.pos.y < 0)
		{
			star.pos.y += JoeBidenWakeup::gRenderer.getHeight();
		}
		if (star.vel.x > JoeBidenWakeup::gRenderer.getWidth())
		{
			star.vel.x -= JoeBidenWakeup::gRenderer.getWidth();
		}
		else if (star.vel.x <  -JoeBidenWakeup::gRenderer.getWidth())
		{
			star.vel.x += JoeBidenWakeup::gRenderer.getWidth();
		}
		if (star.vel.y > JoeBidenWakeup::gRenderer.getHeight())
		{
			star.vel.y -= JoeBidenWakeup::gRenderer.getHeight();
		}
		else if (star.vel.y < -JoeBidenWakeup::gRenderer.getHeight())
		{
			star.vel.y += JoeBidenWakeup::gRenderer.getHeight();
		}
	}
	std::cout << endl << "Star X: " << starAcceleration.x << "    Star Y: " << starAcceleration.y;
	JoeBidenWakeup::gRenderer.endFrame();
	}
	*/
	//JoeBidenWakeup::gAudioSystem.add("hit", "hit.wav");
	/*vector<int> colorR;
	vector<int> colorG;
	vector<int> colorB;
	vector<int> colorA;
	vector<float> rotations;*/
		/*
		colorR.push_back(JoeBidenWakeup::random((unsigned int)256));
		colorG.push_back(JoeBidenWakeup::random((unsigned int)256));
		colorB.push_back(JoeBidenWakeup::random((unsigned int)256));
		colorA.push_back(JoeBidenWakeup::random((unsigned int)256));*/
		/*
		models.push_back(JoeBidenWakeup::Model(model.getPoints()));
		locations.push_back(position);
		rotations.push_back(rotate);
		if (models.size() > 10)
		{
			JoeBidenWakeup::gRenderer.setColor(0, 0, 0, 255);
			models[0].Draw(JoeBidenWakeup::gRenderer, locations[0], rotations[0], 1);

			vector<JoeBidenWakeup::Model>::iterator modelIterator;
			modelIterator = models.begin();
			models.erase(modelIterator);

			vector<JoeBidenWakeup::Vector2>::iterator positionIterator;
			positionIterator = locations.begin();
			locations.erase(positionIterator);

			vector<int>::iterator colorRIterator;
			colorRIterator = colorR.begin();
			colorR.erase(colorRIterator);

			vector<int>::iterator colorGIterator;
			colorGIterator = colorG.begin();
			colorG.erase(colorGIterator);

			vector<int>::iterator colorBIterator;
			colorBIterator = colorB.begin();
			colorB.erase(colorBIterator);

			vector<int>::iterator colorAIterator;
			colorAIterator = colorA.begin();
			colorA.erase(colorAIterator);

			vector<float>::iterator rotationIterator;
			rotationIterator = rotations.begin();
			rotations.erase(rotationIterator);

			for (int i = 0; i < 10; i++)
			{
				JoeBidenWakeup::gRenderer.setColor(colorR[i], colorG[i], colorB[i], colorA[i]);
				models[i].Draw(JoeBidenWakeup::gRenderer, locations[i], rotations[i], 1);
			}
		}
		position += speed * JoeBidenWakeup::gTime.getDeltaTime();
		speed *= 0.9999999999 * (1 - JoeBidenWakeup::gTime.getDeltaTime());
		transform.rotation += rotating;
		rotating *= 0.99 * (1 - JoeBidenWakeup::gTime.getDeltaTime());*/
	JoeBidenAwoken::Asteroids asteroids;
	asteroids.init();
	JoeBidenWakeup::MemoryTracker::initialize();
	while (!JoeBidenWakeup::gInputSystem.getKeyDown(SDL_SCANCODE_ESCAPE))
	{
		asteroids.update(0);
	}
	JoeBidenWakeup::MemoryTracker::displayInfo();
	return 0;
}