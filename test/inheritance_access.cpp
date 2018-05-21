#include <iostream>
using namespace std;

class A {
private: int a;
protected: int b;
public: int c;
};

// "has-a" relationship achieved using composition
class B {
private: 
	A objA;
public:
	void func() {
		// objA.a = 10; // illegal
		// objA.b = 20; // illegal
		objA.c = 30; // legal
	}
};

// "has-a" relationship achieved using private inheritance
class C : private A {
public:
	void func() {
		a = 10; // illegal
		b = 20; // legal
		c = 30; // legal
	}
};
int main() {
	A obj1;
	B obj2;
	C obj3;
	return 0;
}