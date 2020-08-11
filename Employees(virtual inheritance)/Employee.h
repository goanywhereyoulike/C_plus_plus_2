#pragma once
#include <string>

using namespace std;
class Employee
{
private:
	std::string firstName, lastName, SIN;
public:
	Employee(std::string &&f, std::string &&l, std::string &&sin) :
		firstName(f), lastName(l), SIN(sin) {}

	// various getters and setters missing...
	string getFirstName() const { return firstName; }
	string getLastName()const { return lastName; }
	void setFirstName(string name) { firstName = name; }
	void setLastName(string name) { lastName = name; }
	/*virtual double getGrossSale() const = 0;
	virtual double getCommission() const = 0;
	virtual void setGrossSale(double sale) = 0;
	virtual void setCommision(double com) = 0;
	virtual double getWeeklySalary() const = 0;
	virtual double setWeeklySalary(double salary) = 0;*/
	virtual double earnings() const = 0; // pure virtual, so this class is abstract now
	virtual void print() const;
	virtual void raiseEarning()=0;

	virtual ~Employee();

};
