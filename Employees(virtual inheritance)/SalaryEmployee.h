#pragma once
#include <iostream>
#include "Employee.h"

class SalaryEmployee: virtual public Employee
{
protected:
	double weeklySalary; 
public:
	SalaryEmployee(std::string &&f, std::string &&l, std::string &&sin, double salary = 0.0) :
		Employee(std::forward<std::string>(f), 
				std::forward<std::string>(l),
				std::forward<std::string>(sin)), weeklySalary(salary)
	{
		//std::cout << "SalaryEmployee: " << std::endl;
	}

	double getWeeklySalary() const { return weeklySalary; }
	void setWeeklySalary(double salary) { weeklySalary = salary; }

	// do destructor, getter and setter for salary to do...

	virtual double earnings() const override
	{
		return weeklySalary;
	}
	virtual void print() const override
	{
		Employee::print();
		cout << "Salary: " << earnings() << endl;
	}// to be done by students....
	virtual void raiseEarning()
	{
		weeklySalary *= 1.1;
	}
};
