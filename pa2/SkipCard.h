/*
 * SkipCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#ifndef SKIPCARD_H_
#define SKIPCARD_H_

#include <typeinfo>
#include "Card.h"

class SkipCard : public Card {
public:
	SkipCard(Color color) : Card{ color, POINT_SKIPCARD } {}

	virtual ~SkipCard() = default;

	virtual bool operator^(const Card& t) const override { return Card::operator^(t) || typeid(t) == typeid(*this); }

	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;

	virtual void serialize(ostream& os) const override {
		switch (color) {
		case Color::red: os << 'R'; break;
		case Color::blue: os << 'B'; break;
		case Color::green: os << 'G'; break;
		case Color::yellow: os << 'Y'; break;
		default: break;
		}
		os << 's';
	}
};

#endif /* SKIPCARD_H_ */