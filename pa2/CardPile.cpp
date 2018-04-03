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

	// Bug, Credit @HarryWan
	// ref: https://www.facebook.com/groups/481228118923366/permalink/599536547092522/
	// When the CardPile resize to 0 it will not delete the array and cause memory leak.
	//
	// if (cards == nullptr || size == 0) {
	//
	// fixed as
	//
	// if (cards == nullptr) {
	if (cards == nullptr) {
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
	if (size == 0) {
		delete [] cards;
		cards = nullptr;
	}
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
	//Bug. Credit @Yuki Lee
	//ref: https://www.facebook.com/groups/481228118923366/permalink/601233966922780/
	//If the pile contain only one card and that card is a WildCard or a DrawFour, the card would not be reset.
	//Although it is possible to reset it in Player.cpp, it is indeed an unintended bug and shall be fixed as below
	//
	//if (size <= 1)
	//
	//fixed as
	//
	// if (size < 1)

	if (size < 1)
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
