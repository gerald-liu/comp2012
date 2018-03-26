/*
 * NumberCard.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#ifndef NUMBERCARD_H_
#define NUMBERCARD_H_

#include "Card.h"

class NumberCard : public Card {
public:
	NumberCard(int mark, Color color) : Card{ color, mark } {}

	virtual bool operator^(const Card& t) const override {
		if (Card::operator^(t) || t.getPoint() == this->getPoint()) return true;
		else return false;
	}

	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override {}

	virtual void serialize(ostream& os) const override {
		switch (color) {
		case Color::red: os << 'R'; break;
		case Color::blue: os << 'B'; break;
		case Color::green: os << 'G'; break;
		case Color::yellow: os << 'Y'; break;
		default: break;
		}
		os << getPoint();
	}
};

#endif /* NUMBERCARD_H_ */