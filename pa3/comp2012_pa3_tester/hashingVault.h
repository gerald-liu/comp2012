//do NOT submit this file
//do NOT modify this file

#ifndef HASHING_VAULT_H_
#define HASHING_VAULT_H_

#include "container.h"
#include "hashingVaultCounter.h"
//HashingVault is a highly customizable hash table that uses separate chaining
//instead of using linked lists for the chains, some general containers are used
//a container can be a binary search tree or a smart array or actually any class that implements the Container class
template <typename KeyType, typename ValueType>
class HashingVault
{
private:
	Container<KeyType, ValueType>** table; //the hash table
											//it is a pointer that points to a dynamic array of dynamic Container objects
	int size; //the number of slots the hash table has
	int (*fun)(KeyType); //the function pointer that points to the hash function
	HashingVaultCounter counter;

public:
	//constructor
	//create the hash table
	//you can assume the table is already properly created outside (see main.cpp)
	HashingVault(int size, Container<KeyType, ValueType>** table, int (*fun)(KeyType));

	//destructor
	//while the table (2d array) was created outside
	//you should delete the table completely here
	~HashingVault();

	//add (key, value) pair to the hash table and return true if the key is not already there
	//use the hash function to find which slot to add the item
	//add to the Container at that slot (i.e. table[x] where x is obtained by
	//    applying the hash function to the given key) with Container's add function
	//do nothing and return false if key already exists
	bool add(KeyType key, ValueType value);

	//return the value that is associated with the key in the hash table
	//if key is not found, this function would return whatever value returned by the Container's get function for the key-not-found situation
	ValueType get(KeyType key) const;

	//if the specified key exists, remove the item that has it and return true
	//if key is not found, this function would return false
	bool remove(KeyType key);

	//update the size, containers/table, and the hash function
	//put the items into the new table using the new function
	//make sure you delete the old table completely by the end
	void rehash(int size, Container<KeyType, ValueType>** table, int (*fun)(KeyType));

	//print the hash table, showing all items in each of the slots, to the given ostream
	//given; do not modify
	void print(ostream& os) const
	{
		os << "--------------------------" << endl;
		for(int i=0; i<size; i++)
		{
			os << "table[" << i << "]: " << endl;
			if (table[i]->count() == 0)
				os << "(empty)" << endl;
			else
				os << *table[i] << endl;
		}
		os << "--------------------------" << endl;
	}
};

#include "hashingVault.tpp"

#endif
