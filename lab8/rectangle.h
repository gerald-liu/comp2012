#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "common.h"

class Rectangle {
public:
	Rectangle(double x, double y, double x_len, double y_len) : x(x), y(y), x_len(x_len), y_len(y_len) {};

private:
	double area() const { return x_len * y_len; }

	double x;
	double y;
	double x_len;
	double y_len;

	friend double getX(const Rectangle& r) { return r.x; }
	friend double getY(const Rectangle& r) { return r.y; }
	friend double getXLen(const Rectangle& r) { return r.x_len; }
	friend double getYLen(const Rectangle& r) { return r.y_len; }
	friend double getArea(const Rectangle& r) { return r.area(); }
};

#endif
