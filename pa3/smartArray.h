//do NOT submit this file
//do NOT modify this file

#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

//SmartArray is smart in the sense that the underlying array will automatically expand or shrink as needed
template <typename KeyType, typename ValueType>
class SmartArray : public Container<KeyType, ValueType>
{
private:
	Pair<KeyType, ValueType>** data; //data represents a dynamic array of pointers to dynamic Pair objects;
				//the size of the array is always just big enough to contain all the items
				//the items inside should always be sorted in ascending order of their keys
				//should point to nullptr initially

	int size; //the exact size of the data array, i.e., the exact number of items in the array
			  //should be 0 initially

public:
	//constructor: set data to nullptr and size to 0
	SmartArray();

	//destructor: avoid memory leak
	virtual ~SmartArray() override;

	//if the given key already can be found in the array, do nothing and return false
	//add the given (key, value) item to a proper location of the array 
	//(to maintain the ascending order of the keys) and return true
	//for adding a new item, you will need to increase the size of the array by 1
	virtual bool add(KeyType key, ValueType value) override;

	//if there exists an item with the given key, remove the item from the array and return true
	//otherwise, do nothing and return false
	//when an item is removed, you need to resize the array so that the array is just big enough to contain all the remaining items
	//hint: be careful with memory leak as you resize the array
	virtual bool remove(KeyType key) override;

	//return the value by the given key
	//if the key is not found in the array, refer to Container for the code that you should use
	virtual ValueType get(KeyType key) const override;

	//return the number of items in the array (which is also the exact size of the array)
	virtual int count() const override;

	//as described in the Container class
	virtual const Pair<KeyType, ValueType>* operator[] (int n) const override;

	//as described in the Container class
	//refer to the webpage for detailed description
	virtual void print(ostream& os) const override;

	//return true if the array contains an item with the specified key
	//return false otherwise
	bool has(KeyType key) const;
};

#include "smartArray.tpp"
#endif
