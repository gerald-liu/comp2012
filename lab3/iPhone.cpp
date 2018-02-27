#include "iPhone.h"

iPhone::iPhone(int num) : SmartPhone{ "Apple", num, "iOS", 10 } {}

iPhone::~iPhone() { delete this->get_os(); }