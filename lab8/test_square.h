#ifndef TEST_SQUARE_H
#define TEST_SQUARE_H

#include <iostream>
#include <cmath>

#include "square.h"
#include "test.h"

using std::cout;
using std::endl;

class TestSquare : public Test{
public:
	virtual ~TestSquare() = default;

	void run() const {
		test01();
		test02();
	}

	void test01() const {
		double x = 5.0;
		double y = 2.0;
		double len = 13.0;
		Square s1(x, y, len);

		cout << "Created a square. x = " << x << " y = " << y << " len = " << len << endl;
		cout << "x: ";
		assertEquals(x, getX(s1), DOUBLE_THRESHOLD);
		cout << "y: ";
		assertEquals(y, getY(s1), DOUBLE_THRESHOLD);
		cout << "len: ";
		assertEquals(len, getLen(s1), DOUBLE_THRESHOLD);
		cout << endl;
	}

	void test02() const {
		double x = 5.0;
		double y = 2.0;
		double len = 13.0;
		Square s1(x, y, len);

		cout << "Created a square. x = " << x << " y = " << y << " len = " << len << endl;
		cout << "area(): ";
		assertEquals(len * len, getArea(s1), DOUBLE_THRESHOLD);
		cout << endl;
	}
};

#endif