/*
 * Employee.h
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
using namespace std;

enum class Item {id, name, base_salary, net_salary, performance_salary};

class Employee
{
public:
	/**
	 * Constructor
	 * @param id: the id of this employee
	 * @param name: name if this employee
	 */
	Employee(int id, string name);

	/* getter */
	int getID() const;
	string getName() const;

	/**
	 * Check the value of the given item
	 * @param item: a enum class
	 */
	void check(Item item) const;

private:
	int id;
	string name;
};



#endif /* EMPLOYEE_H_ */
