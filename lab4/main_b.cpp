/*
 * main.cpp
 *
 */

#include "EducationalConsultant.h"

int main()
{
	EducationalConsultant *econ = new EducationalConsultant(30001, "Jhon Turing", 40000, 600, 0);
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

	delete econ;
	return 0;
}


