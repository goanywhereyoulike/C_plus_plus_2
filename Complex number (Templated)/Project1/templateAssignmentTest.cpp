#include "Complex.h"
#include <random>

using namespace std;
template <typename T, size_t N>
class MyArray
{
	int sz = 0;		// number of elements
	T elem[N];	// address of first element
	int totalSize = N;	// number of elements plus free-space
		// slots for new elements
public:
	MyArray() {}

	MyArray(const MyArray&v) 
	{
		sz = v.sz;
		T elem[v.totalSize];
		totalSize = v.totalSize;
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = v.elem[i];
		}
	}
	MyArray& operator=(const MyArray & v)
	{
		sz = v.sz;
		T elem[v.totalSize];
		totalSize = v.totalSize;
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = v.elem[i];
		}
		return this;
	}

	T& operator[](int n)
	{
		if (n > N||n<0)
		{
			cout << "Out of range, error" << endl;
		}
		return elem[n];
	}
	const T& operator[](int n) const
	{
		if (n > N || n < 0)
		{
			cout << "Out of range, error" << endl;
		}
		return elem[n];
	}

	int size() const { return sz; }
	int capacity() const { return N; }

};

int main()
{
	cout << "The template type is int" << endl;
	MyArray<Complex<int>, 10> comp1;
	for (int i = 0; i < 10; ++i)
	{
		comp1[i].changeNumber(rand()%20, rand()%20);

	}
	cout << "Put random number to array" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "comp1[" << i << "]:" << comp1[i] << endl;

	}
	// assign 10 complex numbers to comp1, using random numbers
	// print the numbers. Here you must use print operation, that you implement, in complex class to print it.
	comp1[2] = Complex<int>(2, 5); // assign complex number z = 2 + 5i to comp1[2]
	//print comp1 again.
	cout << "Assign complex number z = 2 + 5i to comp1[2]" << endl;
	cout << "comp1[2]:" << comp1[2];
	cout << "comp1[3] + comp1[6] = " << comp1[3] + comp1[6];
	cout << "comp1[3] * comp1[5] = " << comp1[3] * comp1[5];
	cout << "comp1[3] - comp1[6] = " << comp1[3] - comp1[6];
	cout << "comp1[3] / comp1[5] = " << comp1[3] / comp1[5];
	cout << "The conjugate of comp1[3] = " << comp1[3] << " is " << comp1[3].conjuage();
	cout << "The angle arguement of comp1[1] =" << comp1[1] << " is " << comp1[1].angleResult() << " degrees" << endl;

	cout << endl;
	cout << "--------------------------\n";
	cout << "--------------------------\n";
	cout << "The template type is float" << endl;
	MyArray<Complex<float>, 10> comp2;
	for (int i = 0; i < 10; ++i)
	{
		comp2[i].changeNumber(rand() % 20+0.3, rand() % 20+0.4);

	}
	cout << "Put random number to array" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "comp2[" << i << "]:" << comp2[i] << endl;

	}

	comp2[2] = Complex<float>(2.3, 5.5); 
	cout << "Assign complex number z = 2.3 + 5.5i to comp2[2]" << endl;
	cout << "comp2[2]:" << comp2[2];
	cout << "comp2[3] + comp2[6] = " << comp2[3] + comp2[6];
	cout << "comp2[3] * comp2[5] = " << comp2[3] * comp2[5];
	cout << "comp2[3] - comp2[6] = " << comp2[3] - comp2[6];
	cout << "comp2[3] / comp2[5] = " << comp2[3] / comp2[5];
	cout << "The conjugate of comp2[3] = " << comp2[3] << " is " << comp2[3].conjuage();
	cout << "The angle arguement of comp2[2] =" << comp2[2] << " is " << comp2[2].angleResult() << " degrees" << endl;


	cout << endl;
	cout << "--------------------------\n";
	cout << "--------------------------\n";
	cout << "The template type is double" << endl;
	MyArray<Complex<double>, 10> comp3;
	for (int i = 0; i < 10; ++i)
	{
		comp3[i].changeNumber(rand() % 20 + 0.3349, rand() % 20 + 0.4452);

	}
	cout << "Put random number to array" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "comp3[" << i << "]:" << comp3[i] << endl;

	}

	comp3[2] = Complex<double>(2.335, 5.542);
	cout << "Assign complex number z = 2.3 + 5.5i to comp3[2]" << endl;
	cout << "comp3[2]:" << comp3[2];
	cout << "comp3[3] + comp3[6] = " << comp3[3] + comp3[6];
	cout << "comp3[3] * comp3[5] = " << comp3[3] * comp3[5];
	cout << "comp3[3] - comp3[6] = " << comp3[3] - comp3[6];
	cout << "comp3[3] / comp3[5] = " << comp3[3] / comp3[5];
	cout << "The conjugate of comp3[3] = " << comp3[3] << " is " << comp3[3].conjuage();
	cout << "The angle arguement of comp3[2] =" << comp3[2] << " is " << comp3[2].angleResult() << " degrees" << endl;
	//cout << sizeof(comp1[2].getreal());
	// Do all the above tests sequence for float and double.
	system("pause");
	return 0;
}