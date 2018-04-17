#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cmath>
	
using std::cout;
using std::endl;

const double DOUBLE_THRESHOLD = 0.0001;

class Test {
protected:
	virtual ~Test() = default;
	
	virtual void run() const = 0;

	void assertEquals(double expected, double actual, double threshold) const {
		if (abs(actual - expected) < threshold) {
			cout << "passed. Got " << actual << ". Expected " << expected << endl;
		} else {
			cout << "failed. Got " << actual << ". Expected " << expected << endl;
		}
	}
};

#endif