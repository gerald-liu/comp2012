#include <iostream>

using namespace std;

class B {
private:
	int* arr;
	int arrSize;
public:
	B(int data, int arrSize) : arrSize{ arrSize } {
		arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++) arr[i] = data;
	}
	B(const B& b) : arrSize{ b.arrSize } {
		arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++) arr[i] = b.arr[i];
	}
	~B() { delete[] arr; }

	void print() const {
		cout << arrSize << endl;
		if (arr != nullptr) for (int i = 0; i < arrSize; i++) cout << arr[i] << '\t'; cout << endl;
	}
};

class A {
private:
	int* arr;
	int arrSize;
	B b;
public:
	A(int data, int arrSize, int bData, int bArrSize) : arrSize{ arrSize }, b{ bData, bArrSize } {
		arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++) arr[i] = i;
	}

	A(const A& a) : arrSize{ a.arrSize }, b{ a.b } {
		arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++) arr[i] = a.arr[i];
	}

	~A() { delete[] arr; }

	void print() const {
		cout << arrSize << endl;
		if (arr != nullptr) for (int i = 0; i < arrSize; i++) cout << arr[i] << '\t'; cout << endl;
		b.print();
	}
	void clean() {
		delete[] arr; arr = nullptr;
		arrSize = 0;
	}
};

int main() {
	A a0{ 0, 2, 1, 2 };
	A a1{ a0 };
	A a2 = a0;
	A a3{ 1, 3, 2, 3 };
	
	a0.print(); a1.print(); a2.print();
	a3.print();
	//a3.clean();
	//a3 = a1;
	//a3.print();
    return 0;
}
