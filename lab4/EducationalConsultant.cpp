#include "EducationalConsultant.h"

EducationalConsultant::EducationalConsultant(int id, string name, double base, double wage, int hour) :
	Consultant{ id, name, base }, wagePerHour{ wage }, workingHours{ hour } {}

double EducationalConsultant::getWage() const { return wagePerHour; }

int EducationalConsultant::getHours() const { return workingHours; }

void EducationalConsultant::setWage(double wage) { wagePerHour = wage; }

void EducationalConsultant::setHours(int hours) { workingHours = hours; }

double EducationalConsultant::performanceSalary() const { return wagePerHour * workingHours; }

double EducationalConsultant::netSalary() const { return Consultant::netSalary(this->getBaseSalary() + this->performanceSalary()); }

void EducationalConsultant::check(Item item) const {
	switch (item) {
	case Item::id:
		cout << "ID: " << this->getID() << endl; break;
	case Item::name:
		cout << "Name: " << this->getName() << endl; break;
	case Item::base_salary:
		cout << "Base Salary: " << this->getBaseSalary() << endl; break;
	case Item::net_salary:
		cout << "Net Salary: " << this->netSalary() << endl; break;
	case Item::performance_salary:
		cout << "Net Salary: " << this->performanceSalary() << endl; break;
	default: cout << "Invalid item." << endl;
	}
}