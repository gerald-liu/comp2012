/*
 * testDrawFourCard.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: kevinw
 */


#include "DrawFourCard.h"
#include "NumberCard.h"
#include "Player.h"

class MyPlayer : public Player {
public:
	MyPlayer(string s, Player* a = nullptr) : Player(s, a) {}
	virtual bool appealDrawFour() const {
		return false;
	}
	virtual Color chooseColor() const {
		return Color::red;
	}
};

int main() {
/**
 * Sample Output
 *
+4
+4
+4
R1 play after G1? true
R2 play after R1? true
G1 play after R2? true
DrawPile Size:5
DiscardPile Size:1
CurrentPlayer: p1:
NextPlayer: p2:

After Player the card:

DrawPile Size:1
DiscardPile Size:1
CurrentPlayer: p2:+4 +4 +4 WC
NextPlayer: p3:
destructor of p1
destructor of p2
destructor of p3

 *
 */
	DrawFourCard r1;
	DrawFourCard r2;
	DrawFourCard g1;

	cout << r1 << endl;
	cout << r2 << endl;
	cout << g1 << endl;

	cout << "R1 play after G1? " << boolalpha << (g1 ^ r1) << endl;
	cout << "R2 play after R1? " << boolalpha << (r1 ^ r2) << endl;
	cout << "G1 play after R2? " << boolalpha << (r2 ^ g1) << endl;

	Player* p1 = new MyPlayer("p1");
	Player* p2 = new MyPlayer("p2", p1);
	Player* p3 = new MyPlayer("p3", p2);
	Player* currentPlayer = p1;

	WildCard* dummy1 = new WildCard();
	WildCard* dummy2 = new WildCard();
	WildCard* dummy3 = new DrawFourCard();
	WildCard* dummy4 = new DrawFourCard();
	WildCard* dummy5 = new DrawFourCard();

	NumberCard* dummy = new NumberCard(5, Color::red);

	CardPile drawPile;
	CardPile discardPile;



	discardPile += dummy;
	drawPile += dummy1;
	drawPile += dummy2;
	drawPile += dummy3;
	drawPile += dummy4;
	drawPile += dummy5;

	cout << "DrawPile Size:" << drawPile.getSize() << endl;
	cout << "DiscardPile Size:" << discardPile.getSize() << endl;
	cout << "CurrentPlayer: " << *currentPlayer << endl;
	cout << "NextPlayer: " << *currentPlayer->getNextPlayer() << endl;

	r1.castEffect(currentPlayer, drawPile, discardPile);

	cout << endl << "After Player the card:" << endl << endl;
	cout << "DrawPile Size:" << drawPile.getSize() << endl;
	cout << "DiscardPile Size:" << discardPile.getSize() << endl;
	cout << "CurrentPlayer: " << *currentPlayer << endl;
	cout << "NextPlayer: " << *currentPlayer->getNextPlayer() << endl;

	delete p1;
	delete p2;
	delete p3;

}



