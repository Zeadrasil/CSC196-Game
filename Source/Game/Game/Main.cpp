#include <iostream>
#include "Core/Random.h"
#include "Core/FileIO.h"
using namespace std;
int main()
{
#ifdef _DEBUG
	cout << "debug!";
#endif
	cout << "Hello World";
	JoeBidenWakeup::seedRandom((unsigned int)time(nullptr));
	cout << "\n";
	cout << JoeBidenWakeup::getFilePath() << endl;
}