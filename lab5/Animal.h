#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
using namespace std;

class Animal {
public:
    Animal(string name);
    /* TODO1: Fill in the three missing declaratons here */
	virtual ~Animal();
    virtual void speak() const;
    virtual void eat(string food) const;
private:
    string name;
};

#endif