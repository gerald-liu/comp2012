//Submit this file
#include "mall.h"
//You are NOT allowed to include any additional library
//NOTE: Mall::duplicateShopLinkedList must NOT be implemented here

Mall::Mall(string name, string address) {
	this->name = name;
	this->address = address;
	shopHead = nullptr;
}

Mall::Mall(Mall& another) {
	name = another.name;
	address = another.address;
	shopHead = duplicateShopLinkedList(another.shopHead);
}

Mall::~Mall() {
	Node* curr = shopHead;
	Node* next = nullptr;
	while (curr != nullptr) {
		next = curr->getNext();
		delete curr;
		curr = next;
	}
	shopHead = nullptr;
}

void Mall::setName(string name) { this->name = name; }

void Mall::setAddress(string address) { this->address = address; }

string Mall::getName() { return name; }

string Mall::getAddress() { return address; }

bool Mall::addShop(string name, int shopNumber) {
	Node* n = shopHead;
	for (; n != nullptr; n = n->getNext()) {
		if (n->getShop()->getShopNumber() == shopNumber) return false;
		if (n->getNext() == nullptr) break;
	}
	Shop* newShop = new Shop(name, shopNumber);
	Node* newNode = new Node(newShop, nullptr);
	if (shopHead == nullptr) shopHead = newNode;
	else n->setNext(newNode);
	return true;
}

bool Mall::removeShop(int shopNumber) {
	if (shopHead == nullptr) return false;

	if (shopHead->getShop()->getShopNumber() == shopNumber) {
		Node* newHead = shopHead->getNext();
		delete shopHead;
		shopHead = newHead;
		return true;
	}
	Node* prev = shopHead;
	Node* curr = shopHead->getNext();
	for (; curr != nullptr; curr = curr->getNext(), prev = prev->getNext()) {
		if (curr->getShop()->getShopNumber() == shopNumber) {
			prev->setNext(curr->getNext());
			delete curr;
			curr = nullptr;
			return true;
		}
	}
	return false;
}

Shop* Mall::getShop(int shopNumber) {
	if (shopHead == nullptr) return nullptr;
	for (Node* n = shopHead; n != nullptr; n = n->getNext()) if (n->getShop()->getShopNumber() == shopNumber) return n->getShop();
	return nullptr;
}
