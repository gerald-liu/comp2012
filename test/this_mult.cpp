#include <iostream>

using namespace std;

class A {
public:
	A* print_this() { return this; } // print the address stored in the pointer
	//A* print_this_mult(int n) { return this * n; } // invalid operands to binary 'operator*'
	A* print_this_mult(int n) { return reinterpret_cast<A*>(reinterpret_cast<long>(this) * n); }
};

int main() {
	A a;
	cout << a.print_this() << endl;
	cout << a.print_this_mult(2) << endl;
}
