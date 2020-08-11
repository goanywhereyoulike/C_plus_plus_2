#pragma once

#include <string>
#include<iostream>
#include "Employee.h"
using namespace std;
class CommissionEmployee : virtual public Employee
{
protected:
	double grossSale; // gross weekly sale
	double commission; // commission percentage
public:
	CommissionEmployee(std::string &&f, std::string &&l, std::string &&sin,
		double gs = 0.0, double rate = 0.15) :
		Employee(forward<string>(f), forward<string>(l), forward<string>(sin)), grossSale(gs), commission(rate){}



	virtual ~CommissionEmployee()
	{

		std::cout << "~CommissionEmployee" << std::endl;

	}

	double getgrossSale() const
	{
		return grossSale;
	}

	double getcommission() const
	{
		return commission;
	}

	void setgrossSale(double sale)
	{
		grossSale = sale;
	}

	void setcommision(double com)
	{
		commission = com;
	}
	// getter and setter for grossSale and commission.... to be done

	virtual void raise()
	{
		commission += 0.01;
	
	}

	virtual double earnings() const override
	{

		return grossSale * commission;

	}// to be done (multiply sale by commission)
	virtual void print() const override
	{
		std::cout << "[CommissionEmployee] " << std::endl;
		Employee::print();
		std::cout << "grossSale: " << grossSale << ", commission: " << commission << " ,earnings:" << earnings() << std::endl;
		std::cout << std::endl;

	}// to be done
};
