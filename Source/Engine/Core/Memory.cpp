#include "Memory.h"
#include <iostream>
using namespace std;

JoeBidenWakeup::MemoryTracker JoeBidenWakeup::memoryTracker;

void* operator new (size_t size)
{
	void* p = malloc(size);
	JoeBidenWakeup::memoryTracker.add(p, size);
	return p;
}
void operator delete (void* address, size_t size)
{
	JoeBidenWakeup::memoryTracker.remove(address, size);
}

namespace JoeBidenWakeup
{

	void MemoryTracker::add(void* address, size_t size)
	{
		cout << "allocated: " << size << endl;
		bytesAllocated += size;
		numAllocations++;
	}

	void MemoryTracker::remove(void* address, size_t size)
	{
		cout << "deallocated: " << size << endl;
		bytesAllocated -= size;
		numAllocations--;
		free(address);
	}
	void MemoryTracker::displayInfo()
	{
		cout << "Allocated Bytes: " << bytesAllocated << endl;
		cout << "Number of Allocations: " << numAllocations << endl;
	}
}
