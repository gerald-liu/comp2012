//do NOT modify this file
//do NOT submit this file

#ifndef MALL_H_
#define MALL_H_

#include "shop.h"
#include "node.h"
#include <string>
#include <iostream>

using namespace std;

//Mall has a linked list of Shop objects
class Mall
{
private:
	string name; //the name of the mall

	string address; //the address of the mall

	Node* shopHead; //the pointer that points to the head node of linked list of shops
				 	//the number of nodes (including the head node) in the list should be exactly the same as the number of shops
	 	 	 	 	//it should point to nullptr if there is no shop at all

	//duplicateShopLinkedList returns the head node of a duplicated deep copy of the given linked list
	//of which the head node is pointed by the "node" parameter of this function
	//this function must be implemented as a recursion in noloop.cpp
	//please read the webpage description's "additional notes" section for requirements
	//hint: this helper function, if implemented correctly, can be very useful for the copy constructor
	Node* duplicateShopLinkedList(Node* node);

public:
	//constructor
	//there is no shop initially, remember to initialize all the member variables properly!
	Mall(string name, string address);

	//copy constructor
	//deep copy is required here
	Mall(Mall& another);

	//destructor
	//need to avoid memory leak
	~Mall();

	//set the name of the mall
	//no validation is needed
	void setName(string name);

	//set the address of the mall
	//no validation is needed
	void setAddress(string address);

	//return the name of the mall
	string getName();

	//return the address of the mall
	string getAddress();

	//add a shop with the given name and shop number to the end of the shop linked list
	//if there is already an existing shop that has the shop number, do nothing and return false
	//otherwise, add the shop to the end of the linked list, and return true
	//note: no validation is needed for the shop name, and the shop name doesn't have to be unique in the linked list
	bool addShop(string name, int shopNumber);

	//remove a shop from the shop linked list according to the given shop number
	//if no shop in the list has the specified shop number, simply return false
	//otherwise, remove the shop from the list and return true
	//hint: be careful with potential memory leak
	bool removeShop(int shopNumber);

	//return the shop by the specified shop number
	//if no shop in the list has the specified shop number, simply return nullptr
	Shop* getShop(int shopNumber);

	//the following function is used for grading/testing only
	//it is given and already completed
	//just like everything else in this file, do NOT modify
	void printShopLinkedList()
	{
		Node* current = shopHead;
		while(current != nullptr)
		{
			if(current != shopHead) cout << " -> ";
			cout << "(" <<  current->getShop()->getShopNumber() << ",\"" << current->getShop()->getName() << "\")";
			current = current->getNext();
		}
		if(current != shopHead) cout << " -> ";
		cout << "nullptr" << endl;
	}
};

#endif /* MALL_H_ */
