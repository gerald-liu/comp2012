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
		int drawPileSize = drawPile.getSize();
		for (int i = 0; i < drawPileSize; i++) *this += drawPile.removeTopCard();
		int discardPileSize = discardPile.getSize();
		for (int i = 0; i < discardPileSize - 1; i++) drawPile += discardPile.removeCard(0);
		drawPile.shuffle();
		int newDrawPileSize = drawPile.getSize();
		if (numCards - drawPileSize <= newDrawPileSize)
			for (int i = 0; i < numCards - drawPileSize; i++) *this += drawPile.removeTopCard();
		else for (int i = 0; i < newDrawPileSize; i++) *this += drawPile.removeTopCard();
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