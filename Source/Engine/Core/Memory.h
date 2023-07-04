#pragma once
namespace JoeBidenWakeup
{
	struct MemoryAllocation
	{
		void* address;
		size_t size;
		MemoryAllocation* next;
		MemoryAllocation* previous;
	};

	class MemoryTracker
	{
	public:
		void add(void* address, size_t size);
		void remove(void* address, size_t size);	

		void displayInfo();
	private:
		size_t bytesAllocated = 0;
		size_t numAllocations = 0;
	};
	extern MemoryTracker memoryTracker;
}

