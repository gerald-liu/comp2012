#include "Animal.h"

Animal::Animal(string name) : name{ name } {}

Animal::~Animal() { cout << "~Animal()" << endl; }

void Animal::speak() const { cout << "My name is " << name << "!"; }

void Animal::eat(string food) const {}