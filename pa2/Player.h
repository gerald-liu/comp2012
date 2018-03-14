/*
 * Player.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "NumberCard.h"
#include "ReverseCard.h"
#include "DrawFourCard.h"
#include "CardPile.h"
#include <iostream>
#include <string>

using namespace std;

class Player : private CardPile {

	friend void ReverseCard::castEffect(Player*&, ::CardPile&, ::CardPile&);
	friend void DrawFourCard::castEffect(Player*&, ::CardPile&, ::CardPile&);
	friend ostream& operator<<(ostream& os, const Player& h);

public:
	Player(string name, Player* previous = nullptr);

	// It add number_of_cards cards from the drawPile to Player’s cards. As mentioned above,
	// in case there is not enough card in the drawPile to draw, we need to put back card from
	// discardPile to drawPile and shuffle. If the sum of discardPile and drawPile are still not enough,
	// this function should draw all possible cards for the player.
	//
	// For example, if the drawPile has 1 card, discardPile has 3 cards. Four cards need to be drawn.
	// The player will first draw the card in the discardPile. Then 2 card from the discardPile
	// (excluding the top card of the discardPile) are placed back to the drawPile. Shuffle the drawPile.
	// The player draw the remaining two card from the drawPile.
	void drawCard(CardPile& drawPile, CardPile& discardPile, int number_of_cards);

	//The player try to play the index-th card from his Card arrays (cards) after the Card topCard.
	//The function shall return nullptr without doing anything if either:
	//     1) The play is invalid; or
	//	   2) The index is out of bound (no such card).
	//Otherwise, the card being played is removed from the Player's hand and the function returns the
	//address of the card. Remember to change both variable cards and size.
	Card* playCardAfter(const Card* topCard, int index);


	//When a DrawFourCard is played, the next player (who need to draw four) can appeal and ask to review
	//the player's hand. If the current player (the player being reviewed) does have a card to play, we say
	//this play is illegal. In this case,
	//1) the next player would NOT need to draw four cards, and
	//2) the next player would NOT need to skip his turn, and
	//3) the current player need to draw four cards.
	//If the play is legal (the current player has no other playable card in this hand other than DrawFourCard),
	//1) the next player will need to draw an additional two cards, totally 6 cards,
	//2) the next player will skip his turn just like what it should be.
	//
	//Regardless the play is legal or not, the current player can choose a color of his wish.
	//
	//When an appeal is made, this function bool appealDrawFour() has to be called. It would be nextPlayer->appealDrawFour(),
	//not currentPlayer->appealDrawFour().
	//
	//When we are grading your work, this inline function will be replaced by some other code to make sure you really
	//call this function. Therefore if you copy the code here to where it is needed, you wound't pass the test cases.
	virtual bool appealDrawFour() const {
		char input;
		do {
			cout << name;
			cout << ": Do you want to appeal and review your previous's player hand? (Y/N)" << endl;
			cin >> input;
			if (input == 'Y') return true;
			if (input == 'N') return false;
		} while (1);
	}

	//For WildCard and DrawFourCard, player should be able to pick their color after playing the card (even if
	//DrawFourCard is not played legally). You need to call this function whenever you want to ask a user to select
	//a color. The player can only choose among Red, Yellow, Blue, and Green (no meta color is allowed).
	//
	//When we are grading your work, this inline function will be replaced by some other code to make sure you really
	//call this function. Therefore if you copy the code here to where it is needed, you wound't pass the test cases.
	virtual Color chooseColor() const {
		do {
			char input;
			cout << name;
			cout << ": After playing a function card you need to choose a color: (R, B, G, Y)." << endl;
			cin >> input;
			switch (input) {
			case 'R' : return Color::red;
			case 'Y' : return Color::yellow;
			case 'B' : return Color::blue;
			case 'G' : return Color::green;
			}
		} while (1);
	}

	Player* getNextPlayer() const {return nextPlayer; };

	bool win() const { return getSize() == 0; }

	virtual ~Player() {
		cout << "destructor of " << name << endl;
	}

	int getScore() const;

private:

	Player* nextPlayer;
	string name;

};



#endif /* PLAYER_H_ */
