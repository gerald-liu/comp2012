/*
 * testplayer.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: kevinw
 */



#include <iostream>
#include "Player.h"
#include "NumberCard.h"
#include "SkipCard.h"
#include "ReverseCard.h"
#include "DrawTwoCard.h"
#include "DrawFourCard.h"
#include "WildCard.h"

using namespace std;
int main() {

	CardPile drawPile;
	CardPile discardPile;

	for (int i = 0; i < 9; i++) {
		drawPile += new NumberCard(i, Color::red);
		drawPile += new NumberCard(i, Color::blue);
		drawPile += new NumberCard(i, Color::green);
		drawPile += new NumberCard(i, Color::yellow);
	}

	//draw a number card to the discard pile.
	drawPile.shuffle();
	Card* topCard = drawPile.removeTopCard();
	discardPile += topCard;

	drawPile += new ReverseCard(Color::red);
	drawPile += new ReverseCard(Color::blue);
	drawPile += new ReverseCard(Color::green);
	drawPile += new ReverseCard(Color::yellow);

	drawPile += new SkipCard(Color::red);
	drawPile += new SkipCard(Color::blue);
	drawPile += new SkipCard(Color::green);
	drawPile += new SkipCard(Color::yellow);

	drawPile += new DrawTwoCard(Color::red);
	drawPile += new DrawTwoCard(Color::blue);
	drawPile += new DrawTwoCard(Color::green);
	drawPile += new DrawTwoCard(Color::yellow);

	drawPile += new WildCard();
	drawPile += new WildCard();
	drawPile += new WildCard();
	drawPile += new WildCard();

	drawPile += new DrawFourCard();
	drawPile += new DrawFourCard();
	drawPile += new DrawFourCard();
	drawPile += new DrawFourCard();

	drawPile.shuffle();

	int num_of_player;
	do {
		cout << "How many player to play? (enter 1-4)" << endl;
		cin >> num_of_player;
	} while (num_of_player < 1 || num_of_player > 4);


	Player** players = new Player*[num_of_player];

	const string PLAYERNAME[4] = {"Player 0", "Player 1", "Player 2", "Player 3"};

	players[0] = new Player(PLAYERNAME[0]);
	for (int i = 1; i < num_of_player; i++)
		players[i] = new Player(PLAYERNAME[i], players[i - 1]);

	for (int i = 0; i < num_of_player; i++)
		players[i]->drawCard(drawPile, discardPile, 5);


	Player* currentPlayer = players[0];
	Card* cardToPlay = nullptr;
	bool no_one_win = true;

	while (no_one_win) {
		cout << "TopCard: " << *topCard << endl;
		cout << *currentPlayer << endl;
		int input;
		do {
			cout << "Pick a card by typing the index (start with 0) or type -1 for draw one card" << endl;
			cin >> input;
			if (input == -1) {
				currentPlayer->drawCard(drawPile, discardPile, 1);
				cardToPlay = nullptr;
			} else {
				cardToPlay = currentPlayer->playCardAfter(topCard, input);
				if (cardToPlay != nullptr)
					cout << "I play: " <<*cardToPlay << endl;
			}

		} while (input != -1 && cardToPlay == nullptr);
		//cast the effect of the card. A NumberCard has no effect. Only function cards might have effects.
		if (cardToPlay != nullptr) {
			cardToPlay->castEffect(currentPlayer, drawPile, discardPile); //it is important that the effect is casted before it replaces the topCard
			topCard = cardToPlay;
			discardPile += topCard;
		}
		currentPlayer = currentPlayer->getNextPlayer();

		for (int i = 0; i < num_of_player; i++)
			no_one_win = no_one_win & !players[i]->win();
	}
	for (int i = 0; i < num_of_player; i++) {

		if (players[i]->win())
			cout << "Winner!\t\t";
		else
			cout << "Score: " << players[i]->getScore() << "\t";
		cout  << *players[i]  << endl;

		delete players[i];
	}
	delete [] players;
}
