//do NOT modify this file
//do NOT submit this file

#ifndef NODE_H_
#define NODE_H_

#include "shop.h"

//Node is only used for the shop linked list in Mall
class Node
{
private:
	Shop* shop; //the pointer that points to the shop object that this node carries; it should never point to nullptr

	Node* next; //next pointer; it should point to nullptr if and only if this node is the last in the list

public:
	//constructor
	Node(Shop* shop, Node* next);
	
	//destructor
	//delete the shop object here - this is the only place at which the shop object should be deleted
	~Node(); 

	//return the pointer to the shop object 
	Shop* getShop();

	//return the next pointer
	Node* getNext();

	//set the shop pointer
	void setShop(Shop* shop);

	//set the next pointer
	void setNext(Node* node);
};

#endif /* NODE_H_ */
