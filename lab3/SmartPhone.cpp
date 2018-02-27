#include "SmartPhone.h"

SmartPhone::SmartPhone(const string & vendor, int num) : CellularPhone{ vendor, num } {}

SmartPhone::SmartPhone(const string & vendor, int num, const string & os_name, int os_ver) : 
	CellularPhone{ vendor, num }, os{ new OS{ os_name, os_ver } } {}

SmartPhone::~SmartPhone() { delete os; os = nullptr; }

void SmartPhone::browse_web(const string & url) {
	if (this->is_available()) {
		cout << "Visit a website at " << &url[0] << ".\n";
		this->set_battery(this->get_battery() - 0.01f);
	}
	else cout << "Cannot browse the website when the phone is unavailable.\n";
}

void SmartPhone::upgrade_os() {
	os->upgrade();
	this->set_battery(this->get_battery() - 0.01f);
}

const OS * SmartPhone::get_os() const { return os; }