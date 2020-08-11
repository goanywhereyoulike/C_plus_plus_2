#pragma once
#include <string>
#include "CommissionEmployee.h"
#include "SalaryEmployee.h"
using namespace std;
class SalaryCommissionEmployee : public SalaryEmployee, public CommissionEmployee
{
public:
	SalaryCommissionEmployee(std::string &&f, std::string &&l, std::string &&sin,
		double salary = 0.0, double sale = 0.0, double rate = 0.15) :
		CommissionEmployee(forward<string>(f), forward<string>(l), forward<string>(sin), sale,rate),
		SalaryEmployee(forward<string>(f), forward<string>(l), forward<string>(sin), salary),
		Employee(forward<string>(f), forward<string>(l), forward<string>(sin)) {}


	~SalaryCommissionEmployee()
	{
		std::cout << "~SalaryCommissionEmployee" << std::endl;
	}

	virtual double earnings() const override
	{
		return weeklySalary + grossSale * commission;


	}// earning = salary + commission x sale
	virtual void print() const override
	{

		std::cout << "[SalaryCommissionEmployee]" << std::endl;
		Employee::print();
		cout << "commision : " << CommissionEmployee::getcommission() << " grosssale : "<< CommissionEmployee::getgrossSale() << " salary : " << SalaryEmployee::earnings() << " earning: " << earnings() << endl;
		cout << endl;


	}// 
	virtual void raise()
	{
		CommissionEmployee::commission += 0.01;
		SalaryEmployee::weeklySalary *= 1.1;
	}
	void WhichBase();

};
