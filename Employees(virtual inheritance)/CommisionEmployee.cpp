#include "CommisionEmployee.h"
#include <iostream>
CommissionEmployee::~CommissionEmployee()
{
	std::cout << "~CommissionEmployee: " << Employee::getFirstName() << ", " <<
		Employee::getLastName() << std::endl;
}
void CommissionEmployee::raiseEarning()
{
	commission += 0.01;
}
double CommissionEmployee::earnings() const
{
	return grossSale * commission;
}

void CommissionEmployee::print() const
{
	cout << "Commission Employee: " << endl;
	Employee::print();
	cout << "Commision : " << commission << " Gross Sale : "
		<< grossSale << " Earning: " << earnings()<<endl;

}
