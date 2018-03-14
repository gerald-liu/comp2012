/*
 * CardPile.h
 *
 *  Created on: Jan 30, 2018
 *      Author: kevinw
 */

#ifndef CARDPILE_H_
#define CARDPILE_H_

#include "Card.h"

class CardPile {
public:

	CardPile& operator+=(Card*);


	int getSize() const {return size;}


	Card* removeCard(int);
	Card* removeTopCard() {return removeCard(size -1); }

	const Card* getTopCard() const { return getCard(size - 1); }
	const Card* getCard(int index) const { if (index < 0 || index >= size) return nullptr; return cards[index]; }

	virtual ~CardPile();
	void shuffle();




private:
	int size = 0;
	Card** cards = nullptr;
};

#endif /* CARDPILE_H_ */
