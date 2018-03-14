#include "Dog.h"

Dog::Dog(string name) : Animal{ name } {}

Dog::~Dog() { cout << "~Dog()" << endl; }

void Dog::speak() const {
	Animal::speak();
	cout << " I am a Dog. Woof!\n";
}

void Dog::eat(string food) const { cout << "The dog swings its tail furiously and eats " << food << "!\n"; }

void Dog::swim() const { cout << "The dog swims freely!\n"; }