#pragma once

#include <iostream>
//static void* loc;

class MyClass
{
public:
	

	MyClass() = default;
	

	MyClass(size_t n) : arr(new double[n]), size(n)
	{
		std::cout << "Main Cnstr\n";
		for (size_t i = 0; i < size; ++i)
		{
			arr[i] = i;
		}
	}

	MyClass(const MyClass &cp) : arr(new double[cp.size]), size(cp.size)
	{
		std::cout << "Copy Cnstr\n";
		for (size_t i = 0; i < size; ++i)
			arr[i] = cp.arr[i];
	}

	MyClass & operator=(const MyClass &rhs)
	{
		std::cout << "Assignment operator\n";
		if (this == &rhs)
			return *this;

		delete[] arr;
		size = rhs.size;
		arr = new double[size];
		for (size_t a = 0; a < size; ++a)
			arr[a] = rhs.arr[a];
		return *this;
	}
	~MyClass()
	{
		std::cout << "Destructor called\n";
		delete[] arr;
		arr = nullptr;
		size = 0;
	}


	void *operator new(size_t size);
	void operator delete(void *ptr);

private:
	double *arr;
	size_t size;
	
   
};
