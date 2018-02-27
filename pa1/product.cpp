//Submit this file
#include "product.h"
//You are NOT allowed to include any additional library

Product::Product(string name, ProductType type, float price) : name{ name }, type{ type }, price{ price }, quantity{ 0 } {}

string Product::getName() { return name; }

ProductType Product::getType() { return type; }

float Product::getPrice() { return price; }

int Product::getQuantity() { return quantity; }

bool Product::setPrice(float price) {
	if (price > 0) {
		this->price = price;
		return true;
	}
	else return false;
}

bool Product::setQuantity(int quantity) {
	if (quantity >= 0) {
		this->quantity = quantity;
		return true;
	}
	else return false;
}

int Product::compare(Product* other) {
	if (price - other->getPrice() >= 0.01f) return 1;
	else if (price - other->getPrice() <= -0.01f) return -1;
	else {
		if (name > other->getName()) return 1;
		else if (name < other->getName()) return -1;
		else return 0;
	}
}