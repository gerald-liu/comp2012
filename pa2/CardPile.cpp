/*
 * CardPile.cpp
 *
 *  Created on: Jan 30, 2018
 *      Author: kevinw
 */

#include "CardPile.h"

CardPile& CardPile::operator +=(Card* newCard) {
	if (newCard == nullptr)
		return *this;
	if (cards == nullptr || size == 0) {
		cards = new Card*[1];
	} else {
		Card** tmp = new Card*[1 + size];
		for (int i = 0; i < size; i++)
			tmp[i] = cards[i];
		delete[] cards;
		cards = tmp;
	}

	cards[size] = newCard;
	size++;
	return *this;
}

Card* CardPile::removeCard(int index) {
	if (index >= size || index < 0)
		return nullptr;

	Card* result = cards[index];
	for (int i = index; i < size - 1; i++)
		cards[i] = cards[i + 1];
	size--;
	return result;
}

CardPile::~CardPile() {
	for (int i = 0; i < size; i++)
		delete cards[i];

	delete [] cards;

	size = 0;
	cards = nullptr;
}

void CardPile::shuffle()
{
	if (size <= 1)
		return;

	for (int i = 0; i < size; i++)
		cards[i]->init();

	for (int i = 0; i < size * 2; i++) {
		Card* tmp;
		int swap = rand() % size;
		tmp = cards[swap];
		cards[swap] = cards[i % size];
		cards[i % size] = tmp;
	}
}
