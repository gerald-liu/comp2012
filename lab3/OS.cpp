
#include "OS.h"


OS::OS() {}

OS::OS(const string& name, int version) : name(name), version(version) {}

void OS::upgrade() {
    int prev_version = version;
    version += 1;
    cout << "Operating system is upgraded from " << prev_version << " to " << version << "." << endl;
}

void OS::print() const {
    cout << "The current operating sytem is " << name << " with version " << version << "." << endl;
}

string OS::get_name() const {
    return name;
}

int OS::get_version() const {
    return version;
}
