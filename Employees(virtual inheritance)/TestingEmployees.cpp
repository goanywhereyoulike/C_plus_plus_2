
#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include "Employee.h"
#include "SalaryEmployee.h"
#include "CommisionEmployee.h"
#include "SalaryCommissionEmployee.h"
#include "Organization.h" // header file to represent an organization which have some employees. 
						  // It should contain a vector of employee shared pointers. It should have
							// method to add an employee, to set salary and/or commission for employees as 
                         // it is relevant, a method to compute total wages paid, and a method to remove an employee
						// from the vector. Remember that we keep all employees in one single vector of pointers
						// as explained above.

using namespace std;

int main()
{
	cout << fixed << setprecision(2);


	SalaryEmployee sEmployee1("John", "Smith", "111-111-111");
	sEmployee1.setWeeklySalary(100.);
	SalaryEmployee sEmployee2("Johnson", "Smith", "111-111-112");
	sEmployee2.setWeeklySalary(200.);
	SalaryEmployee sEmployee3("John1", "Smith", "111-111-111");
	sEmployee3.setWeeklySalary(300.);
	SalaryEmployee sEmployee4("John2", "Smith", "111-111-111");
	sEmployee4.setWeeklySalary(400.);
	SalaryEmployee sEmployee5("John3", "Smith", "111-111-111");
	sEmployee5.setWeeklySalary(500.);
	CommissionEmployee cEmployee1("Sue", "Jones", "222-222-222");
	cEmployee1.setGrossSale(150.);
	SalaryCommissionEmployee scEmployee1("Bob", "Lewis", "333-333-333");
	scEmployee1.setGrossSale(150.);
	scEmployee1.setWeeklySalary(50);

	Organization MyCompany;
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee1));
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee2));
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee3));
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee4));
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee5));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee1));
	MyCompany.addEmployee(make_shared<SalaryCommissionEmployee>(scEmployee1));

	MyCompany.print();
	MyCompany.printWage();

	MyCompany.raiseEearning();
	MyCompany.print();
	MyCompany.printWage();

	// start an organization named MyCompany. Add 5 salaries employees, 10 commissioned employees, and 3 salaried commissioned ones.
	//......
	// make sure give each employee some salary or sale, so their earnings in meaningful.

	// output each employee info and earnings through support from MyCompany. For example implement a
	// function in MyCompany in which you do the following for printing:
	// virtual function calls through base class pointers.
	//for (auto e : employees)
	//	e->print();
	// .....

	// bellow is the example of adding employees to MyCompany
	/// second way add them to a vector and print the through dynamic binding
	//vector<Employee*> employees;
	//employees.push_back(&sEmployee1);
	//employees.push_back(&cEmployee1);
	//employees.push_back(&scEmployee1);

	// set some sales and salary for each employee
	// ..............

	// compute and print the total wage paid by MyCompany
	//.....

	// provide virtual support in employee hierarchy to raise salaries and commission appropriately.
	// raise base salary of each employee by 10 percent base salary. For commissioned ones, increase 
	// the commission by 1 percent. 
	// print employees info
	// compute total company's wage and print it again.
	
	system("pause");
	return 0;
}