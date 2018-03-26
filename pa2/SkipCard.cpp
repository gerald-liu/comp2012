/*
 * SkipCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#include "SkipCard.h"
#include "Player.h"

void SkipCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) {
	currentPlayer = currentPlayer->getNextPlayer();
}