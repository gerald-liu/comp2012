#include <iostream>

using namespace std;

void printInt(int&& i) { cout << i << endl; }

int main() {
	int* p = new int;
	*p = 1;
	// printInt(*p);
	printInt(move(*p));
}