//do NOT submit this file
//do NOT modify this file

#ifndef CONTAINER_H
#define CONTAINER_H

#include "pair.h"
#include "containerCounter.h"
//it is the abstract base class for the containers used in HashingVault
template <typename KeyType, typename ValueType>
class Container
{
private:
	ContainerCounter counter;
public:
	//destructor
	virtual ~Container() = default;

	//add a (key, value) pair item to the container
	//it should do nothing and return false when there is already an item that has the same key
	//otherwise, it should add the item and return true
	virtual bool add(KeyType key, ValueType value) = 0;

	//remove an item from the the container, according to the given key
	//if the key is found, it should remove the item and return true
	//otherwise, return false
	virtual bool remove(KeyType key) = 0;

	//return the value given a key
	//if the key is not found in the container, you should use the following code in the derived class's implementation of this function:
	//		if (typeid(ValueType) == typeid(int))
	//			return 0;
	//		else
	//			return ValueType();
	virtual ValueType get(KeyType key) const = 0;

	//return the number of items this container has
	virtual int count() const = 0;

	//output the content, i.e., all the pair items in this container, to the given ostream
	//pair items are outputted in ascending order of keys in a very specific format
	//refer to the webpage for detailed description
	virtual void print(ostream& os) const = 0;

	//return the pointer to the pair item that has the (n+1)-th smallest key
	//for example, if n is 0, you should return the pointer to the smallest item (i.e. first smallest item)
	//for example, if n is 1, you should return the pointer to the second smallest item
	//for example, if n is the same as count()-1, you should return the pointer to the biggest item
	//if n is too small (i.e. <0) or too big, you should return nullptr
	virtual const Pair<KeyType, ValueType>* operator[] (int n) const = 0;
};

#endif /* CONTAINER_H */
