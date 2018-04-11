/*
 * WildCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#ifndef WILDCARD_H_
#define WILDCARD_H_

#include "Card.h"

class WildCard : public Card {
public:
	WildCard() : Card{ static_cast<Color>(4), POINT_WILDCARD } {}
	WildCard(int point) : Card{ static_cast<Color>(4), point } {}

	virtual ~WildCard() = default;

	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;

	virtual void init() override { color = Color::meta; }

	virtual void serialize(ostream& os) const override {
		switch (color) {
		case Color::red: os << 'R'; break;
		case Color::blue: os << 'B'; break;
		case Color::green: os << 'G'; break;
		case Color::yellow: os << 'Y'; break;
		case Color::meta: os << "WC"; return;
		}
		os << 'w';
	}
};

#endif /* WILDCARD_H_ */
