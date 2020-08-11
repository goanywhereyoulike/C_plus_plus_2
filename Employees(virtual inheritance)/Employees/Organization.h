#pragma once
#include<iostream>
#include<vector>
#include "Employee.h"
using namespace std;
// header file to represent an organization which have some employees. 
// It should contain a vector of employee shared pointers. It should have
// method to add an employee, to set salary and/or commission for employees as 
// it is relevant, a method to compute total wages paid, and a method to remove an employee
// from the vector. Remember that we keep all employees in one single vector of pointers
// as explained above.

class Organization
{
	vector<shared_ptr<Employee>> Employees;

public:

	Organization() {}
	~Organization() {}
	void addEmployee(shared_ptr<Employee> employee)
	{


		Employees.push_back(employee);


	}

	double totalwage()
	{
		double wage = 0;
		for (auto it : Employees)
		{
			wage += it->earnings();
		}
		return wage;
	}
	void raise()
	{
		for (auto it : Employees)
		{
			it->raise();
		}
	
	}
	void removeemployee(shared_ptr<Employee> employee)
	{
	
		for (auto it = Employees.begin(); it != Employees.end();)
		{
			if (*it == employee)
			{
				it = Employees.erase(it);
			}
			else
				it++;
		}
	}


	void print()
	{
		for (auto it : Employees)
		{
			it->print();

		}

	}
};
