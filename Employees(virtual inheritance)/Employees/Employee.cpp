#include <iostream>
#include "Employee.h"

void Employee::print() const
{
	std::cout << "Employee: " << firstName << " " <<
		lastName << ", " << SIN << std::endl;
}

Employee::~Employee()
{
	std::cout << "~Employee: " << firstName << ", " <<
		lastName << std::endl;
}

