
#include <iostream>
#include <vector>
#include <iomanip>
#include "Employee.h"
#include "SalaryEmployee.h"
#include "CommissionEmployee.h"
#include "SalaryCommissionEmployee.h"
#include "Organization.h" 

using namespace std;

int main()
{
	cout << fixed << setprecision(2);
	Organization MyCompany;

	SalaryEmployee sEmployee1("John", "Smith", "111-111-111", 800.);
	SalaryEmployee sEmployee2("Tom", "Hall", "222-111-111", 700.);
	SalaryEmployee sEmployee3("Jame", "Allen", "333-111-111", 600.);
	SalaryEmployee sEmployee4("Jim", "Reed", "444-111-111", 500.);
	SalaryEmployee sEmployee5("Tony", "King", "555-111-111", 0.);
	//CommissionEmployee cEmployee1("Sue", "Jones", "222-222-222");
	//SalaryCommissionEmployee scEmployee1("Bob", "Lewis", "333-333-333");
	sEmployee5.setsalary(400.);
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee1));
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee2));
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee3));
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee4));
	MyCompany.addEmployee(make_shared<SalaryEmployee>(sEmployee5));

	//MyCompany.print();
	CommissionEmployee cEmployee1("Sue", "Jones", "222-111-222",3000,0.5);
	CommissionEmployee cEmployee2("Jack", "Allen", "222-222-222",2000,0.6);
	CommissionEmployee cEmployee3("Smith", "Young", "222-333-222",4000,0.4);
	CommissionEmployee cEmployee4("Ava", "Brown", "222-444-222",5000,0.5);
	CommissionEmployee cEmployee5("Sophie", "Davis", "222-555-222",6000,0.3);
	CommissionEmployee cEmployee6("Linda", "Miller", "222-666-222",7000,0.9);
	CommissionEmployee cEmployee7("Emily", "Wilson", "222-777-222",8000,0.8);
	CommissionEmployee cEmployee8("Megan", "Moore", "222-888-222",9000,0.7);
	CommissionEmployee cEmployee9("Jessica", "Taylor", "222-999-222",10000,0.6);
	CommissionEmployee cEmployee10("Mia", "Bell", "222-000-222",11111,0.3);
	cEmployee10.setgrossSale(10000);


	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee1));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee2));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee3));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee4));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee5));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee6));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee7));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee8));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee9));
	MyCompany.addEmployee(make_shared<CommissionEmployee>(cEmployee10));
	
	SalaryCommissionEmployee scEmployee1("Bob", "Lewis", "333-000-333",300,10000,0.5);
	SalaryCommissionEmployee scEmployee2("Ava", "Wright", "333-111-333",400,20000,0.5);
	SalaryCommissionEmployee scEmployee3("Charlotte", "Lopez", "333-222-333",500,30000,0.5);

	MyCompany.addEmployee(make_shared<SalaryCommissionEmployee>(scEmployee1));
	MyCompany.addEmployee(make_shared<SalaryCommissionEmployee>(scEmployee2));
	MyCompany.addEmployee(make_shared<SalaryCommissionEmployee>(scEmployee3));

	MyCompany.print();

	cout << "The total wage paid by MyCompany: " << MyCompany.totalwage() << endl;


	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Raise base salary of each employee by 10 percent base salary and increase the commission by 1 percent" << endl;
	cout << endl;
	MyCompany.raise();
	MyCompany.print();

	cout << "The total wage paid by MyCompany: " << MyCompany.totalwage() << endl;
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