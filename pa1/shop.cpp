//Submit this file
#include "shop.h"
//You are NOT allowed to include any additional library

Shop::Shop(string name, int shopNumber) : name{ name }, shopNumber{ shopNumber }, products{ nullptr }, productCount{ 0 } {}

Shop::Shop(Shop& another) : name{ another.name }, shopNumber{ another.shopNumber }, productCount{ another.productCount } {
	if (productCount == 0) products = nullptr;
	else {
		products = new Product* [productCount];
		for (int i = 0; i < productCount; i++) {
			products[i] = new Product(another.products[i]->getName(), another.products[i]->getType(), another.products[i]->getPrice());
			products[i]->setQuantity(another.products[i]->getQuantity());
		}
	}
}

Shop::~Shop() {
	for (int i = 0; i < productCount; i++) delete products[i];
	delete[] products;
	products = nullptr;
}

string Shop::getName() { return name; }

int Shop::getShopNumber() { return shopNumber; }

void Shop::setName(string name) { this->name = name; }

void Shop::setShopNumber(int shopNumber) { this->shopNumber = shopNumber; }

void Shop::addProduct(string name, ProductType type, float price, int quantityToAdd) {
	if (productCount == 0) {
		products = new Product* [1];
		products[0] = new Product(name, type, price);
		if (!products[0]->setQuantity(quantityToAdd)) {
			delete products[0];
			delete[] products;
		}
		productCount++;
		return;
	}
	
	for (int i = 0; i < productCount; i++) {
		if (products[i]->getName() == name) {
			products[i]->setQuantity(products[i]->getQuantity() + quantityToAdd);
			return;
		}
	}

	Product** temp = new Product* [productCount + 1];
	Product* newProduct = new Product(name, type, price);
	if (!newProduct->setQuantity(quantityToAdd)) {
		delete newProduct;
		for (int i = 0; i < productCount + 1; i++) delete temp[i];
		delete[] temp;
	}
	int j = 0;
	for (; j < productCount; j++) {
		if (products[j]->compare(newProduct) == -1) {
			temp[j] = new Product(products[j]->getName(), products[j]->getType(), products[j]->getPrice());
			temp[j]->setQuantity(products[j]->getQuantity());
			delete products[j];
		}
		else break;
	}
	temp[j] = newProduct;
	productCount++;
	for (j++; j < productCount; j++) {
		temp[j] = new Product(products[j - 1]->getName(), products[j - 1]->getType(), products[j - 1]->getPrice());
		temp[j]->setQuantity(products[j - 1]->getQuantity());
		delete products[j - 1];
	}
	delete[] products;
	products = temp;
}

bool Shop::removeProduct(string name, int quantityToRemove) {
	if (quantityToRemove <= 0) return false;

	int j = 0;
	for (; j < productCount; j++) if (products[j]->getName() == name) break;
	if (j == productCount) return false;

	if (products[j]->getQuantity() < quantityToRemove) return false;
	else if (products[j]->getQuantity() > quantityToRemove) products[j]->setQuantity(products[j]->getQuantity() - quantityToRemove);
	else {
		Product** temp = new Product* [productCount];
		for (int i = 0; i < j; i++) {
			temp[i] = new Product(products[i]->getName(), products[i]->getType(), products[i]->getPrice());
			temp[i]->setQuantity(products[i]->getQuantity());
			delete products[i];
		}
		delete products[j];
		productCount--;
		for (int i = j; i < productCount; i++) {
			temp[i] = new Product(products[i + 1]->getName(), products[i + 1]->getType(), products[i + 1]->getPrice());
			temp[i]->setQuantity(products[i + 1]->getQuantity());
			delete products[i + 1];
		}
		delete[] products;
		products = temp;
	}
	return true;
}

Product* Shop::findProduct(string name) {
	int j = 0;
	for (; j < productCount; j++) if (products[j]->getName() == name) return products[j];
	return nullptr;
}

bool Shop::updatePrice(string name, float price) {
	if (price <= 0) return false;

	int j = 0;
	for (; j < productCount; j++) if (products[j]->getName() == name) break;
	if (j == productCount) return false;

	float oldPrice = products[j]->getPrice();
	if (!products[j]->setPrice(price)) return false;
	Product* updated = products[j];
	if (price > oldPrice) {
		int k = j + 1;
		for (; k < productCount; k++) if (products[k]->compare(updated) == 1) break;
		for (int i = j + 1; i < k; i++) products[i - 1] = products[i];
		products[k - 1] = updated;
	}
	else {
		int k = j - 1;
		for (; k >=0; k--) if (products[k]->compare(updated) == -1) break;
		for (int i = j - 1; i > k; i--) products[i + 1] = products[i];
		products[k + 1] = updated;
	}
	return true;
}