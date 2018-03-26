#include "DrawFourCard.h"
#include "Player.h"

void DrawFourCard::castEffect(Player *& currentPlayer, CardPile & drawPile, CardPile & discardPile) {
	color = currentPlayer->chooseColor();

	if (currentPlayer->getNextPlayer()->appealDrawFour()) {
		bool legal = true;
		for (int i = 0; i < currentPlayer->getSize(); i++) {
			if (*discardPile.getTopCard() ^ *currentPlayer->getCard(i)) {
				legal = false;
				break;
			}
		}
		if (legal) {
			currentPlayer = currentPlayer->getNextPlayer();
			currentPlayer->drawCard(drawPile, discardPile, 6);
		}
		else currentPlayer->drawCard(drawPile, discardPile, 4);
	}
	else {
		currentPlayer = currentPlayer->getNextPlayer();
		currentPlayer->drawCard(drawPile, discardPile, 4);
	}
}