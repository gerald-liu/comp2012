/*
 * Employee.cpp
 */

#include "Employee.h"

Employee::Employee(int id, string name) : id(id), name(name) {
}

int Employee::getID() const {
	return id;
}

string Employee::getName() const {
	return name;
}

void Employee::check(Item item) const {
	switch(item) {
	case Item::id:
		cout << "ID: " << id <<endl;
		break;
	case Item::name:
		cout << "Name: " << name <<endl ;
		break;
	default:
		cout << "Invalid item." <<endl;
	}

}





