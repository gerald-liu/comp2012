/*
 * testSkipCard.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */



#include "SkipCard.h"
#include "Player.h"
int main() {

/**
 * Sample Output

Rs
Rs
Gs
R1 play after G1? true
R2 play after R1? true
G1 play after R2? true
DrawPile Size:0
DiscardPile Size:1
CurrentPlayer: p1:

After Player the card:

DrawPile Size:0
DiscardPile Size:1
CurrentPlayer: p2:
destructor of p1
destructor of p2
destructor of p3


 */


	SkipCard r1(Color::red);
	SkipCard r2(Color::red);
	SkipCard g1(Color::green);

	cout << r1 << endl;
	cout << r2 << endl;
	cout << g1 << endl;

	cout << "R1 play after G1? " << boolalpha << (g1 ^ r1) << endl;
	cout << "R2 play after R1? " << boolalpha << (r1 ^ r2) << endl;
	cout << "G1 play after R2? " << boolalpha << (r2 ^ g1) << endl;

	Player* p1 = new Player("p1");
	Player* p2 = new Player("p2", p1);
	Player* p3 = new Player("p3", p2);
	Player* currentPlayer = p1;



	SkipCard* dummy = new SkipCard(Color::yellow);

	CardPile drawPile;
	CardPile discardPile;

	discardPile += dummy;

	cout << "DrawPile Size:" << drawPile.getSize() << endl;
	cout << "DiscardPile Size:" << discardPile.getSize() << endl;
	cout << "CurrentPlayer: " << *currentPlayer << endl;

	r1.castEffect(currentPlayer, drawPile, discardPile);

	cout << endl << "After Player the card:" << endl << endl;
	cout << "DrawPile Size:" << drawPile.getSize() << endl;
	cout << "DiscardPile Size:" << discardPile.getSize() << endl;
	cout << "CurrentPlayer: " << *currentPlayer << endl;

	delete p1;
	delete p2;
	delete p3;

}


