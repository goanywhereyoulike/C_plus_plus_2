#include "Organization.h"



void Organization::addEmployee(string&& type, string&& firstName, string&& LastName,string&& sin)
{
	if (type == "Commission")
	{
		employeeList.push_back(make_shared<CommissionEmployee>(CommissionEmployee(forward<string>(firstName), forward<string>(LastName), forward<string>(sin))));
	}
	if (type == "Salary")
	{
		employeeList.push_back(make_shared<SalaryEmployee>(SalaryEmployee(forward<string>(firstName), forward<string>(LastName),forward<string> (sin))));
	}
	if (type == "SalaryCommission")
	{
		employeeList.push_back(make_shared<SalaryCommissionEmployee>(SalaryCommissionEmployee(forward<string>(firstName), forward<string>(LastName), forward<string>(sin))));
	}
}

void Organization::addEmployee(shared_ptr<Employee>  employee)
{
	employeeList.push_back(employee);

}

void Organization::print()
{
	int i = 0;
	while (i<employeeList.size())
	{
		employeeList[i]->print();
		i++;
	}
}

void Organization::printWage()
{
	double wage = 0;
	int i = 0;
	while (i < employeeList.size())
	{
		wage += employeeList[i]->earnings();
		i++;
	}
	cout << "toal wages paid: " << wage << endl;
}

void Organization::raiseEearning()
{
	for (int i = 0; i < employeeList.size(); i++)
		employeeList[i]->raiseEarning();
}


Organization::Organization()
{
}


Organization::~Organization()
{
}
