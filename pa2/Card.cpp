/*
 * Card.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "Card.h"

bool Card::operator ^(const Card& t) const {
	if (t.color == color)
		return true;
	if (t.color == Color::meta)
		return true;
	return false;
}

Card::Card(Color color, int mark) : color(color), point(mark) {
}

