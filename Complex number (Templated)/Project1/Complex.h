#pragma once
#include<iostream>
#include "math.h"
#define PI 3.1415927

using namespace std;

template<class T>   
class Complex
{
public:
	Complex() { real = 0; imag = 0; }
	Complex(T r, T i) { real = r; imag = i; }

	friend Complex operator+ (Complex & number1, Complex & number2)
	{
		return Complex(number1.real + number2.real, number1.imag + number2.imag);
	}
	friend  Complex operator- (Complex & number1, Complex & number2)
	{
		return Complex(number1.real - number2.real, number1.imag - number2.imag);
	}
	friend Complex operator* (Complex & number1, Complex & number2)
	{
		Complex newNumber;
		newNumber.real = number1.real*number2.real - number1.imag*number2.imag;
		newNumber.imag = number1.real*number2.imag + number1.imag*number2.real;
		return newNumber;
	}
	friend Complex operator/ (Complex & number1, Complex & number2)
	{
		Complex newNumber;
		if (number2.real != 0 && number2.imag != 0)
		{
			newNumber.real = (number1.real*number2.real + number1.imag*number2.imag) / (number2.real*number2.real + number2.imag*number2.imag);
			newNumber.imag = (number1.imag*number2.real - number1.real*number2.imag) / (number2.real*number2.real + number2.imag*number2.imag);
		}
		else
		{
			cout << "Error, can not use divide operator" << endl;
	
		}
		return newNumber;
	}
	friend ostream& operator<<(ostream& os, const Complex& dt)
	{
		os << "(" << dt.real << ")" << "+" << "(" << dt.imag << ")" << "i" << endl;
		return os;
	}

	Complex conjuage()
	{
		return Complex(real, -imag);
	}
	void changeNumber(T chreal, T chimag)
	{
		real = chreal;
		imag = chimag;

	}
	double angleResult()
	{
		double result = 0;
		result = atan2(imag,real) * 180 / PI;
		return result;
	
	}
	T getreal()
	{
		return real;
	}

/*	void ptint()
	{
		cout << real << "+" << imag << "i" << endl;
	}*/
private:
	T real;
	T imag;

};
