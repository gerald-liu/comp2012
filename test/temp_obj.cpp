#include <iostream>

using namespace std;

class A {
public:
	int i;
	
	A(int i) : i{i} { cout << i << "\tconversion constructor\n"; } // conversion
	A(const A& a) : i{a.i} { cout << i << "\tcopy constructor\n"; } // copy
	A(A&& a) : i{a.i} { cout << i << "\tmove constructor\n"; } // move
	~A() { cout << i << "\tdestructor\n"; }
	
	A operator+(const A& a) {
		cout << '\n' << i << "\toperator+\t" << a.i << endl;
		// return A(i + a.i);
		A ret(*this);
		ret.i += a.i;
		cout << "End of operator+\n";
		return ret; // return by move if move constructor is defined, else return by copy
	}
};

int main() {
	// cout << "a0:\n"; A a0{0};
	// cout << "a1:\n"; A a1 = 1;
	// cout << "a2:\n"; A a2 = a0;
	// cout << "a3:\n"; A a3 = move(a0);
	
	const A& i0 = 0;
	A i1(1); A i2(2);
	A i3 = i1 + 3 + i2;
	cout << "\nIn the end:\n";
}
