#include <typeinfo>
#include "Dog.h"
#include "Cat.h"

using namespace std;

int main()
{
    Animal* animals[4];
    animals[0] = new Dog("Blackie");
    animals[1] = new Dog("Mark");
    animals[2] = new Cat("Snow");
    animals[3] = new Cat("Kate");

    string foods[4] = {"Bone", "Steak", "Catnip", "Fish"};

    for(int i=0; i<4; i++)
    {
        animals[i]->speak();
        animals[i]->eat(foods[i]);
		
        if(string(typeid(*animals[i]).name()).find("Dog") != string::npos)
        {
            dynamic_cast<Dog*>(animals[i])->swim();
        }
    }

    for(int i=0; i<4; i++)
    {
        delete animals[i];
    }

    return 0;
}