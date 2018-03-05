/*
 * EducationalConsultant.h
 *
 */

#ifndef EDUCATIONALCONSULTANT_H_
#define EDUCATIONALCONSULTANT_H_

#include "Consultant.h"

class EducationalConsultant : public Consultant
{
public:
	/**
	 * Constructor
	 * @param id: the id of this consultant
	 * @param name: name if this consultant
	 * @param base: the base salary of this consultant
	 * @param wage: wage per hour
	 * @param hour: working hours
	 */
	EducationalConsultant(int id, string name, double base, double wage, int hour);

	/* getter */
	double getWage() const;
	int getHours() const;

	/* setter */
	void setWage(double wage);
	void setHours(int hours);

	/**
	 *  Compute the performance salary
	 *  performance salary = wage per hour * working hours
	 */
	double performanceSalary() const;

	/**
	 *  Compute the net salary after tax
	 *  Total salary before tax for Educational Consultant is (base salary + performance salary)
	 */
	double netSalary() const;

	/**
	 * Check the value of the given item
	 * @param item: a enum class
	 * id, name, base_salary, net_salary and performance_salary are valid items.
	 *
	 */
	void check(Item item) const;

private:
	double wagePerHour;
	int workingHours;
};



#endif /* EDUCATIONALCONSULTANT_H_ */
