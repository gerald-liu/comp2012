/*
 * Player.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#include "Player.h"

ostream& operator<<(ostream& os, const Player& h) {
	os << h.name << ":";
	for (int i = 0; i < h.getSize(); i++) {
		os << *h.getCard(i) << " ";
	}
	return os;
}

Player::Player(string name, Player * previous) : name{ name } {
	if (previous == nullptr) nextPlayer = this;
	else {
		nextPlayer = previous->nextPlayer;
		previous->nextPlayer = this;
	}
}

void Player::drawCard(CardPile & drawPile, CardPile & discardPile, int numCards) {
	if (numCards <= drawPile.getSize()) for (int i = 0; i < numCards; i++) *this += drawPile.removeTopCard();
	else {
		int rest = numCards - drawPile.getSize();
		for (int i = 0; i < drawPile.getSize(); i++) *this += drawPile.removeTopCard();
		for (int i = 0; i < discardPile.getSize() - 1; i++) drawPile += discardPile.removeCard(discardPile.getSize() - 2);
		drawPile.shuffle();
		if (rest <= drawPile.getSize()) for (int i = 0; i < rest; i++) *this += drawPile.removeTopCard();
		else for (int i = 0; i < drawPile.getSize(); i++) *this += drawPile.removeTopCard();
	}
}

Card * Player::playCardAfter(const Card * topCard, int index) {
	if (!(*topCard ^ *getCard(index))) return nullptr;
	else if (getSize() == 1 && getCard(index)->getPoint() > 9) return nullptr;
	else return removeCard(index);
}

int Player::getScore() const {
	int score = 0;
	for (int i = 0; i < getSize(); i++) score += getCard(i)->getPoint();
	return score;
}