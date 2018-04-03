/*
 * ReverseCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#ifndef REVERSECARD_H_
#define REVERSECARD_H_

#include <typeinfo>
#include "Card.h"

class ReverseCard : public Card {
public:
	ReverseCard(Color color) : Card{ color, POINT_REVERSECARD } {};

	virtual bool operator^(const Card& t) const override { return Card::operator^(t) || typeid(t) == typeid(*this);	}

	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;

	virtual void serialize(ostream& os) const override {
		switch (color) {
		case Color::red: os << 'R'; break;
		case Color::blue: os << 'B'; break;
		case Color::green: os << 'G'; break;
		case Color::yellow: os << 'Y'; break;
		default: break;
		}
		os << 'r';
	}
};

#endif /* REVERSECARD_H_ */
