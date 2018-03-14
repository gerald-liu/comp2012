#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
	Dog(string name);
	virtual ~Dog();
	virtual void speak() const override;
	virtual void eat(string food) const override;
	void swim() const;
};

#endif