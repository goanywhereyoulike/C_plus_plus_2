#pragma once
#include "Employee.h"
#include "SalaryEmployee.h"
#include "CommisionEmployee.h"
#include "SalaryCommissionEmployee.h"
#include <vector>
#include <memory>
using namespace std;
class Organization
{
private:
	vector<shared_ptr<Employee>> employeeList;
public:
	void addEmployee(string&& type, string&& firstName, string&& LastName,string&& sin);
	void addEmployee(shared_ptr<Employee> employee);
	void print();
	void printWage();
	void raiseEearning();
	Organization();
	~Organization();
};

