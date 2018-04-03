/*
 * WildCard.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#include "Player.h"

void WildCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile) {
	color = currentPlayer->chooseColor();
}