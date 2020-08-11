#include "SalaryCommissionEmployee.h"

void SalaryCommissionEmployee::WhichBase()
{
	// print the base info
	SalaryEmployee::Employee::print();
	CommissionEmployee::Employee::print();
}