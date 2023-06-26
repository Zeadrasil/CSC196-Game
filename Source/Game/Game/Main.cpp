#include <iostream>

int main()
{
#ifdef _DEBUG
	std::cout << "debug!";
#endif
	std::cout << "Hello World";
}