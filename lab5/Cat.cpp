#include "Cat.h"

Cat::Cat(string name) : Animal{ name } {}

Cat::~Cat() { cout << "~Cat()" << endl; }

void Cat::speak() const {
	Animal::speak();
	cout << " I am a Cat. Meow!\n";
}

void Cat::eat(string food) const { cout << "The cat meows happily and eats " << food <<"!\n"; }