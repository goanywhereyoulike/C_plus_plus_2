#pragma once
#include <string>
#include<memory>
#include "CommisionEmployee.h"
#include "SalaryEmployee.h"
using namespace std;
class SalaryCommissionEmployee : public SalaryEmployee, public CommissionEmployee
{
public:
	SalaryCommissionEmployee(std::string &&f, std::string &&l, std::string &&sin,
		double salary = 0.0, double sale = 0.0, double rate = 0.15) :
		CommissionEmployee(forward<string>(f), forward<string>(l), forward<string>(sin), sale, rate),
		SalaryEmployee(forward<string>(f), forward<string>(l), forward<string>(sin), salary),
		Employee(forward<string>(f), forward<string>(l), forward<string>(sin)) {}


	~SalaryCommissionEmployee();
	
	virtual double earnings() const override; // earning = salary + commission x sale
	void raiseEarning();
	virtual void print() const override; // 

	void WhichBase();
};
