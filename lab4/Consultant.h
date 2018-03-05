/*
 * Consultant.h
 *
 */

#ifndef CONSULTANT_H_
#define CONSULTANT_H_

#include "Employee.h"

class Consultant : public Employee {
public:
	/**
	 * Constructor
	 * @param cid: the id of this consultant
	 * @param cname: name if this consultant
	 * @param base: the base salary of this consultant
	 */
	Consultant(int cid, string cname, double base);

	/* getter */
	double getBaseSalary() const;

	/* setter */
	void setBaseSalary(double base);

	/**
	 * Compute the net salary
	 * @param salary: total salary before tax
	 */
	double netSalary(double salary) const;

	/**
	 * Check the value of the given item
	 * @param item: a enum class
	 * Only id, name, base_salary and net_salary are valid items for Consultant.
	 */
	void check(Item item) const;

private:
	double baseSalary;
};

#endif /* CONSULTANT_H_ */