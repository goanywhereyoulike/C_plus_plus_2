
#include "MyClass.h"
#include<string.h>
#include <new>



struct myAllocator
{
	char storage[1000][64];
	size_t allocatorIdx = 0;
	char *ret=NULL;
	int count{ 0 };
	void *allocate(size_t size)
	{
		
		if (allocatorIdx >= 1000)
		{ 
			count=1;
		}
		if (count > 0)
			{
				allocatorIdx = 0;
				while (storage[allocatorIdx][0] != 'F' || storage[allocatorIdx][1] != 'F'&& allocatorIdx < 1000)
				{
					allocatorIdx = allocatorIdx + (size / 64 + 1);
				}
				if (storage[allocatorIdx][0] == 'F' && storage[allocatorIdx][1] == 'F')
				{
					ret = storage[allocatorIdx];
				}
				else
				{
					std::cout << "There is no space to allocate\n";
					ret = nullptr;
				}

			}

		else
			{
				if (size <= 0 )
					return nullptr;
				ret = storage[allocatorIdx];
				allocatorIdx = allocatorIdx + (size / 64 + 1);
			}

			return (void *)ret;
	
	}


	void deallocate(void *ptr)
	{
		size_t freeIndex = ((char*)ptr - storage[0])/64;
		if (freeIndex >= 1000)
			std::cout << "DEALLOCATE ERROR!\n";
		memset(storage[freeIndex], 'F', 64);
		std::cout << "storage[" << freeIndex << "] is free\n";

		
	}
};
myAllocator mAllocator;

void *operator new(size_t n)
{
	if (mAllocator.allocatorIdx < 1000 && mAllocator.count == 0)
	{
		std::cout << "Our global operator new";
		std::cout << "  called for size " << n
			<< " index=" << mAllocator.allocatorIdx << std::endl;
	}
	void *location = mAllocator.allocate(n);
	if (mAllocator.allocatorIdx >= 1000 || mAllocator.count > 0)
	{
		std::cout << "Our global operator new";
		std::cout << "  called for size " << n
			<< " index=" << mAllocator.allocatorIdx << std::endl;
	}
	if (location == nullptr)
		throw "allocation failed!";
	return location;
}
void operator delete(void *ptr)
{
	std::cout << "Our global operator delete\n";
	mAllocator.deallocate(ptr);

}

void* MyClass::operator new(size_t size)
{
	if (mAllocator.allocatorIdx < 1000 && mAllocator.count==0)
	{
		std::cout << "operator new called for size " << size
			<< " index=" << mAllocator.allocatorIdx << std::endl;
	}
	void *storage = mAllocator.allocate(size);


	if (mAllocator.allocatorIdx >= 1000|| mAllocator.count>0)
	{
		std::cout << "operator new called for size " << size
			<< " index=" << mAllocator.allocatorIdx << std::endl;
	}
	if ( storage== nullptr)
		throw "allocation failed!";
	return storage;
}


void MyClass::operator delete(void *ptr)
{
	std::cout << "operator delete called\n";
	mAllocator.deallocate(ptr);
	
}


int main()
{
	MyClass *a0 = new MyClass;
//	void * a00 = operator new(sizeof(MyClass));
//	MyClass *aA0 = ::new(a00) MyClass;

	for (size_t count = 0; count < 141; ++count)
	{
		MyClass *a = new MyClass(5); // calls my operator new
		MyClass *b = new MyClass(7); // calls my operator new
		char *place = (char*)mAllocator.allocate(sizeof(MyClass));
		MyClass *c = ::new(place) MyClass(10);
	}

	MyClass *a = new MyClass(5); // calls my operator new
	MyClass *b = new MyClass(7); // calls my operator new


	char *place = (char*)mAllocator.allocate(sizeof(MyClass));
	MyClass *c = ::new(place) MyClass(10);
	delete a; // calls my operator delete
	delete b; // calls my operator delete

	MyClass *ab = new MyClass(5); // calls my operator new
	MyClass *bc = new MyClass(7); // calls my operator new
	MyClass *bq = new MyClass(7); // calls my operator new
	MyClass *bcq = new MyClass(7); // calls my operator new
	system("Pause");

	return 0;

}