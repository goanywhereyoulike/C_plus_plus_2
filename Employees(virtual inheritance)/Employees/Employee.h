#pragma once
#include <string>
using namespace std;
class Employee
{
private:
	string firstName, lastName, SIN;
public:
	Employee(std::string &&f, std::string &&l, std::string &&sin) :
		firstName(forward<string>(f)), lastName(forward<string>(l)), SIN(forward<string>(sin))
	{}


	string getfirstName() const
	{
		return firstName;
	}
	string getlastName() const
	{
		return lastName;
	}
	void setfirstName(string name)
	{
		firstName = name;
	}
	void setlastName(string name)
	{
		lastName = name;
	}
	string getSIN() const
	{
		return SIN;
	}
	void setSIN(string SN)
	{
		SIN = SN;
	}
	virtual double earnings() const = 0; // pure virtual, so this class is abstract now
	virtual void print() const;
	virtual void raise() = 0;
	virtual ~Employee();

};

