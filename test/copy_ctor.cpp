#include <iostream>

using namespace std;

class Person {
public:
	Person() { cout << "Person()" << endl; }
	Person(Person& p) { cout << "Person(Person& p)" << endl; }
	// Person(const Person& p) { cout << "Person(const Person& p)" << endl; }
};

int main() {
	const Person r;
	Person s(r);
	return 0;
}