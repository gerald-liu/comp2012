//do NOT modify this file
//do NOT submit this file

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>
#include <cmath> //the fabs function is needed for floating point number comparison, see the "Product ordering in a shop" section on webpage
using namespace std;

enum ProductType { FOOD, CLOTHING, APPLIANCES, TOYS, PETS };

//Product to be contained in a shop
class Product
{
private:
    string name; //product's name

    ProductType type; //product's type

    float price; //product's price

    int quantity; //product's quantity, should be 0 initially

public:
    //constructor
    //you can assume the given price for the constructor is always positive
    //hint: remember, in C++, uninitialized variables have garbage values! (i.e. not necessarily 0)
    Product(string name, ProductType type, float price);

    //return the name
    string getName();

    //return the type
    ProductType getType();

    //return the price
    float getPrice();

    //return the quantity of the product
    int getQuantity();

    //note that the given price here can be invalid
    //if the given price is valid (i.e. larger than 0), set the price and return true
    //otherwise, do nothing and return false
    bool setPrice(float price);

    //note that the given quantity here can be invalid
    //if the given quantity is valid (i.e. non-negative), set the quantity and return true
    //otherwise, do nothing and return false
    bool setQuantity(int quantity);

    //compare "this" product with "other" product using their prices and names
    //see webpage's "Product ordering in a shop" section for further description and examples
    //this function can be used in sorting/ordering the products in a shop
    //it should return 1 if "this" product is larger than "other" product
    //it should return -1 if "this" product is small than "other" product
    //it should return 0 if "this" product has the same price and name as the "other" product (this case should not happen according to our assumption, and won't be tested)
    //for simplicity, you can assume the parameter always points to a valid product
    int compare(Product* other);
};

#endif /* PRODUCT_H_ */
