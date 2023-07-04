#include <iostream>
#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
using namespace std;


int main()
{
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
	cout << fileText << endl;*/
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
	cout << timer.GetElapsedSeconds();
}