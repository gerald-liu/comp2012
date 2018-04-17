#ifndef TEST_RECTANGLE_H
#define TEST_RECTANGLE_H

#include <iostream>
#include <cmath>

#include "rectangle.h"
#include "test.h"

using std::cout;
using std::endl;

class TestRectangle : public Test{
public:
	virtual ~TestRectangle() = default;
	
	void run() const {
		test01();
		test02();
	}

	void test01() const {
		double x = 5.0;
		double y = 2.0;
		double x_len = 13.0;
		double y_len = 1.0;
		Rectangle r1(x, y, x_len, y_len);

		cout << "Created a rectangle. x = " << x << " y = " << y << " x_len = " << x_len << " y_len = " << y_len << endl;
		cout << "x: ";
		assertEquals(x, getX(r1), DOUBLE_THRESHOLD);
		cout << "y: ";
		assertEquals(y, getY(r1), DOUBLE_THRESHOLD);
		cout << "x_len: ";
		assertEquals(x_len, getXLen(r1), DOUBLE_THRESHOLD);
		cout << "y_len: ";
		assertEquals(y_len, getYLen(r1), DOUBLE_THRESHOLD);
		cout << endl;
	}

	void test02() const {
		double x = 5.0;
		double y = 2.0;
		double x_len = 13.0;
		double y_len = 1.0;
		Rectangle r1(x, y, x_len, y_len);

		cout << "Created a rectangle. x = " << x << " y = " << y << " x_len = " << x_len << " y_len = " << y_len << endl;
		cout << "area(): ";
		assertEquals(x_len * y_len, getArea(r1), DOUBLE_THRESHOLD);
		cout << endl;
	}
};

#endif
