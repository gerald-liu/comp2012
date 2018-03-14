#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
    Cat(string name);
	virtual ~Cat();
    virtual void speak() const override;
    virtual void eat(string food) const override;
};

#endif