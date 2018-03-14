/*
 * Card.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>
#include <iostream>

#include "enumAndConst.h"

using namespace std;

class CardPile;
class Player;

class Card {

	friend ostream& operator<<(ostream& os, const Card& c) {
		c.serialize(os);
		return os;
	}

public:
	// Return true if playing the card t after this card is valid. False if vice-versa.
	// e.g. "(a ^ b)" should return true if b can be played after a.
	virtual bool operator^(const Card& t) const;

	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) = 0;

	Card(Color color, int mark);
	virtual ~Card() = default;

	// return the mark of the card
	int getPoint() const {return point;}

	// does not do anything here for most of the card. This will be called when the deck is re-shuffled.
	// WildCard and DrawFourCard assigned with specific color should restore its color to Color::meta in this function.
	virtual void init() {}

protected:
	// Print the card
	virtual void serialize(ostream& os) const = 0;

	Color color;


private:
	const int point;

};

#endif /* CARD_H_ */
