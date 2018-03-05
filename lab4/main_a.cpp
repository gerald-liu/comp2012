/*
 * main_a.cpp
 *
 */

#include "Employee.h"
#include "Consultant.h"

void printEmployee(Employee e)
{
	cout << "Employee information:" << '\n';
	cout << "ID: " << e.getID() << '\t';
	cout << "Name: " << e.getName();
	cout << endl;
}

int main()
{
	Employee employee(10001, "Karen Lam");
	printEmployee(employee);
	cout<<endl;

	Consultant consultant(20001, "Connie Wong", 40000);
	consultant.check(Item::id);
	consultant.check(Item::name);
	consultant.check(Item::base_salary);
	consultant.check(Item::net_salary);
	cout<<endl;

	printEmployee(consultant);

	return 0;
}


