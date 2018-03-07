/*
 * main_c.cpp
 *
 */

#include "EducationalConsultant.h"

void printEmployee(Employee e)
{
	cout << "Employee information:" << '\n';
	cout << "ID: " << e.getID() << '\t';
	cout << "Name: " << e.getName();
	cout << endl;
}

int main()
{
	EducationalConsultant *econ = new EducationalConsultant(30001, "Jhon Turing", 40000, 600, 0);
	printEmployee(*econ);
	econ->check(Item::base_salary);
	econ->check(Item::performance_salary);
	econ->check(Item::net_salary);

	cout<<endl;
	econ->setBaseSalary(35000);
	econ->check(Item::base_salary);
	econ->setHours(115);
	cout<<"Wage per hour: " << econ->getWage() << '\t';
	cout<<"Working hours: " << econ->getHours() << endl;
	econ->check(Item::performance_salary);
	econ->check(Item::net_salary);
	cout<<endl;

	Consultant *consultantPtr = nullptr;
	consultantPtr = econ;
	consultantPtr->check(Item::id);
	consultantPtr->check(Item::name);
	//consultantPtr->setWage(650);
	//consultantPtr->setHours(90);
	consultantPtr->check(Item::base_salary);
	consultantPtr->check(Item::performance_salary);
	consultantPtr->check(Item::net_salary);
	cout<<endl;

	Employee& employeeRef = *econ;
	employeeRef.check(Item::id);
	employeeRef.check(Item::name);
	//employeeRef.setBaseSalary(20000);
	employeeRef.check(Item::base_salary);
	employeeRef.check(Item::performance_salary);
	employeeRef.check(Item::net_salary);


	delete econ;
	return 0;
}