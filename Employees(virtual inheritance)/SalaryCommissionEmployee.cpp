#include "SalaryCommissionEmployee.h"

SalaryCommissionEmployee::~SalaryCommissionEmployee()
{
	std::cout << "~SalaryCommissionEmployee: " << Employee::getFirstName() << ", " <<
		Employee::getLastName() << std::endl;
}

double SalaryCommissionEmployee::earnings() const
{
	return SalaryEmployee::earnings()+CommissionEmployee::earnings();
}

void SalaryCommissionEmployee::raiseEarning()
{
	SalaryEmployee::weeklySalary *= 1.1;
	CommissionEmployee::commission += 0.01;
}

void SalaryCommissionEmployee::print() const
{
	cout << "Salary Commission Employee: " << Employee::getLastName() << "," << Employee::getFirstName() << endl;
	cout << "Commision : " << CommissionEmployee::getCommission() << " Gross Sale : "
		<< CommissionEmployee::getGrossSale()<<"Salary : "<<SalaryEmployee::earnings() << " Earning: " << earnings()<<endl;
}

void SalaryCommissionEmployee::WhichBase()
{
	// print the base info
	SalaryEmployee::Employee::print();
	CommissionEmployee::Employee::print();
}
