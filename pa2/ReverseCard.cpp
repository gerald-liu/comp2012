/*
 * ReverseCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 *				Weiyang Liu
 */

#include "Player.h"

void ReverseCard::castEffect(Player *& currentPlayer, CardPile & drawPile, CardPile & discardPile) {
	Player* curr = currentPlayer;
	while (curr->nextPlayer != currentPlayer) curr = curr->nextPlayer;
	Player* prev = curr;

	curr = currentPlayer;
	Player* next = curr->nextPlayer;
	curr->nextPlayer = prev;
	prev = curr;
	curr = next;

	while (curr != currentPlayer) {
		next = curr->nextPlayer;
		curr->nextPlayer = prev;
		prev = curr;
		curr = next;
	}
}