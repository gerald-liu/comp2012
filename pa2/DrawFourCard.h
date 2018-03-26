/*
 * DrawFourCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#ifndef DRAWFOURCARD_H_
#define DRAWFOURCARD_H_

#include "WildCard.h"

class DrawFourCard : public WildCard {
public:
	DrawFourCard() = default;

	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;

	virtual void serialize(ostream& os) const override {
		if (color == Color::meta) {
			os << "+4";
			return;
		}
		os << '4';
		switch (color) {
		case Color::red: os << 'R'; break;
		case Color::blue: os << 'B'; break;
		case Color::green: os << 'G'; break;
		case Color::yellow: os << 'Y'; break;
		default: break;
		}
	}
};

#endif /* DRAWFOURCARD_H_ */