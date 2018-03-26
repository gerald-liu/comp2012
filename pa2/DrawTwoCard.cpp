/*
 * DrawTwoCard.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#include "DrawTwoCard.h"
#include "Player.h"

void DrawTwoCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) {
	currentPlayer = currentPlayer->getNextPlayer();
	currentPlayer->drawCard(drawPile, discardPile, 2);
}