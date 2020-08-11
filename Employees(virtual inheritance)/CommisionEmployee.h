#pragma once

#include <string>
#include "Employee.h"

class CommissionEmployee : virtual public Employee
{
protected:
	double grossSale; // gross weekly sale
	double commission; // commission percentage
public:
	CommissionEmployee(std::string &&f, std::string &&l, std::string &&sin,
		double gs = 0.0, double rate = 0.15) :
		Employee(std::forward<std::string>(f),
			std::forward<std::string>(l),
			std::forward<std::string>(sin)), grossSale(gs), commission(rate)
	{}
	/*CommissionEmployee(std::string const &f, std::string const &l, std::string const &sin,
		double gs = 0.0, double rate = 0.15);*/

	virtual ~CommissionEmployee();
	double getGrossSale() const{ return grossSale; }
	double getCommission() const { return commission; }
	void setGrossSale(double sale) { grossSale = sale; }
	void setCommision(double com) { commission = com; }
	virtual void raiseEarning();
	// getter and setter for grossSale and commission.... to be done

	virtual double earnings() const override; // to be done (multiply sale by commission)
	virtual void print() const override; // to be done
};
