#include "CellularPhone.h"

CellularPhone::CellularPhone(const string& vendor, int num) : vendor{ vendor }, num{ num } {}

CellularPhone::~CellularPhone() {}

void CellularPhone::turn_on() {
	status = true;
	cout << "The phone is on.\n";
}

void CellularPhone::turn_off() {
	status = false;
	cout << "The phone is off.\n";
}

void CellularPhone::call(int num) {
	if (this->is_available()) {
		cout << "Make phone call from " << this->get_num() << " to " << num << ".\n";
		this->set_battery(this->get_battery() - 0.01f);
	}
	else cout << "Cannot make phone calls when the phone is unavailable.\n";
}

bool CellularPhone::is_available() const { return status && this->get_battery() > 0; }

void CellularPhone::print() const {
	cout << "This is a phone from " << &this->get_vendor()[0] << "! The phone number is " << this->get_num()
		<< ". The battery life is " << static_cast<int>(this->get_battery() * 100) << "%.\n";
}

string CellularPhone::get_vendor() const { return vendor; }

int CellularPhone::get_num() const { return num; }

float CellularPhone::get_battery() const { return battery; }

void CellularPhone::set_battery(float battery) { this->battery = battery; }