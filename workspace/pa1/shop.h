//do NOT modify this file
//do NOT submit this file

#ifndef SHOP_H_
#define SHOP_H_

#include "product.h"
#include <string>
#include <iostream>
using namespace std;

//Shop has a dynamic array of Product objects
class Shop
{
private:
	string name; //shop name

	int shopNumber; //shop number in the mall

	Product** products; //the pointer that points to the dynamic array of product pointers that point to dynamic product objects
			   	   	    //the array needs to be of the exact size needed to store all the products
			   	   	    //e.g. if there are 3 products, then the size of the array should be exactly 3
			   	   	    //if there is no product, the pointer should point to nullptr

	int productCount; //number of products, i.e., the total number of product objects stored in the dynamic array
					  //note that it is NOT the sum of all product objects' quantities

public:
	//constructor
	//there is no product initially, remember to initialize all the member variables properly!
	Shop(string name, int shopNumber);

	//copy constructor
	//deep copy is required here
	Shop(Shop& another);

	//destructor
	//need to avoid memory leak
	//hint: beware of the difference between "delete" and "delete []"
	~Shop();

	//return the name
	string getName();

	//return the shop number
	int getShopNumber();

	//set the shop name
	//no validation is needed
	void setName(string name);

	//set the shop number
	//no validation is needed
	void setShopNumber(int shopNumber);

	//add some amount of a certain product to the dynamic array
	//for simplicity, you can assume the given parameters are all valid
	//i.e. quantityToAdd and price are always positive, type and price are always consistent with those of an existing item if any
	//you can also assume the resulting quantity would not overflow a signed integer
	//if the array already has the product with the specified name, then just add the specified quantityToAdd to the product item
	//beware that the dynamic array needs to be just big enough to store all the products
	//also the products need to be stored in ascending order by their prices in the array
	//if two products have the same price, they will be ordered by their names 
	//please read the additional specification and examples on the assignment webpage description
	//hint: be careful with potential memory leak as you resize/recreate the array
	void addProduct(string name, ProductType type, float price, int quantityToAdd);

	//remove some amount of a certain product in the dynamic array
	//do nothing and return false if any of the following conditions holds:
	//- quantityToRemove is less than or equal to 0
	//- there is no product that has the name specified in the parameter
	//- the current quantity of the product is less than the specified quantityToRemove
	//if a product reaches 0 in quantity after the quantity adjustment, the product object should be removed from the dynamic array
	//beware that the dynamic array needs to be just big enough to store all the products
	//please read the additional specification and examples on the assignment webpage description
	//hint: be careful with potential memory leak as you resize/recreate the array
	bool removeProduct(string name, int quantityToRemove);

	//find the product according to the specified name, and return the pointer to it
	//if no product has that name, simply return nullptr
	Product* findProduct(string name);

	//update the price of the product as specified by the name
	//do nothing and return false if any of the following conditions holds:
	//- there is no existing product that has the name specified in the parameter
	//- the new price is less than or equal to 0
	//you should make sure that the product array is still sorted correctly after the price update
	bool updatePrice(string name, float price);

	//the following function is used for grading/testing only
	//it is given and already completed
	//just like everything else in this file, do NOT modify
	void printProductArray()
	{
		if(productCount == 0)
		{
			cout << "none.";
		}
		else
		{
			for(int i=0; i<productCount; i++)
			{
				cout << "(\"" << products[i]->getName() << "\"," << products[i]->getType() << "," << products[i]->getPrice() << "," << products[i]->getQuantity() << ") ";
			}
		}
		cout << endl;
	}
};

#endif /* SHOP_H_ */
