/*
 * Consultant.cpp
 *
 */

#include "Consultant.h"

Consultant::Consultant(int cid, string cname, double base) : Employee{ cid, cname }, baseSalary{ base } {}

double Consultant::getBaseSalary() const { return baseSalary; }

void Consultant::setBaseSalary(double base) { baseSalary = base; }

double Consultant::netSalary(double salary) const {
	double tax[4][2] = { { 40000, 0.02 },{ 40000, 0.07 },{ 40000, 0.12 },{ -1, 0.17 } };
	double s = salary;
	unsigned int lv = 0;
	for (; lv < sizeof(tax) / sizeof(double); lv++) {
		if (tax[lv][0] < 0) break;
		s -= tax[lv][0];
		if (s < 0) break;
	}
	if (lv == 0) return salary;

	double t = 0, line = 0;
	for (unsigned int i = 0; i < lv; i++) {
		t += tax[i][0] * tax[i][1];
		line += tax[i][0];
	}
	t += (salary - line) * tax[lv][1];
	return salary - t;
}

void Consultant::check(Item item) const {
	switch (item) {
	case Item::id:
		cout << "ID: " << this->getID() << endl; break;
	case Item::name:
		cout << "Name: " << this->getName() << endl; break;
	case Item::base_salary:
		cout << "Base Salary: " << this->getBaseSalary() << endl; break;
	case Item::net_salary:
		cout << "Net Salary: " << this->netSalary(this->getBaseSalary()) << endl; break;
	default: cout << "Invalid item." << endl;
	}
}




