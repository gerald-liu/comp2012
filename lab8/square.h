#ifndef SQUARE_H
#define SQUARE_H

#include "common.h"

class Square {
public:
	Square(double x, double y, double len) : x(x), y(y), len(len) {};

private:
	double area() const { return len * len; }

	double x;
	double y;
	double len;

	friend double getX(const Square& s) { return s.x; }
	friend double getY(const Square& s) { return s.y; }
	friend double getLen(const Square& s) { return s.len; }
	friend double getArea(const Square& s) { return s.area(); }
};

#endif
