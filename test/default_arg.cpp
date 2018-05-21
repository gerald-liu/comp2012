#include <iostream>

using namespace std;

class Vector {
public:
	Vector(double a = 0, double b = 0) : x(a), y(b) { }
	double getx() const { return x; }
	double gety() const { return y; }
private:
	double x, y;
};

int main() {
	Vector v = 1;
	cout << v.getx() << '\t' << v.gety() << endl;
}
