#include <iostream>
#include <cstring>

#include "file.h"

using namespace std;

File::File()
{
	name = nullptr;
}

File::~File()
{
	if (name != nullptr) {
		delete name;
	}
}

File::File(const File &file)
{
	if (file.name != nullptr) {
		name = new char[strlen(file.name) + 1];
		strcpy(name, file.name);
	}
}

File::File(const char *fileName)
{
	name = new char[strlen(fileName) + 1];
	strcpy(name, fileName);
}

bool File::equals(const File &file) const
{
	if (name == nullptr && file.name == nullptr) return true;
	if (name == nullptr || file.name == nullptr) return false;

	return strcmp(name, file.name) == 0;
}

void File::print() const
{
	if (name != nullptr)
		cout << "File " << name << endl;
	else
		cout << "File without name" << endl;
}