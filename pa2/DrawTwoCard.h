/*
 * DrawTwoCard.h
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#ifndef DRAWTWOCARD_H_
#define DRAWTWOCARD_H_

#include "SkipCard.h"
#include "Player.h"

class DrawTwoCard : public SkipCard {
public:
	DrawTwoCard(Color color) : SkipCard{ color } {}

	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) override;

	virtual void serialize(ostream& os) const override {
		switch (color) {
		case Color::red: os << 'R'; break;
		case Color::blue: os << 'B'; break;
		case Color::green: os << 'G'; break;
		case Color::yellow: os << 'Y'; break;
		default: break;
		}
		os << '+';
	}
};

#endif /* DRAWTWOCARD_H_ */