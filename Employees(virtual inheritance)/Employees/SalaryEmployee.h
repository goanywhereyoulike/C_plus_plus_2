#pragma once
#include <iostream>
#include "Employee.h"
#include "CommissionEmployee.h"

class SalaryEmployee : virtual public Employee
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
	double getsalary()
	{
		return weeklySalary;
	}

	void setsalary(double money)
	{
	
		weeklySalary = money;
	}

	virtual ~SalaryEmployee()
	{
		std::cout << "~SalaryEmployee" << std::endl;
	}
	// do destructor, getter and setter for salary to do...

	virtual double earnings() const override
	{
		return weeklySalary;
	}
	virtual void raise()
	{
		weeklySalary *= 1.1;
	
	}
	
	virtual void print() const override  // to be done by students....
	{
		std::cout << "[SalaryEmployee] " << std::endl;
		Employee::print();
		std::cout << "Salary: " << earnings() << std::endl;
		std::cout << std::endl;

	}
};

