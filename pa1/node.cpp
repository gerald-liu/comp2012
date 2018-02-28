//Submit this file
#include "node.h"
//You are NOT allowed to include any additional library

Node::Node(Shop* shop, Node* next) : shop{ shop }, next{ next } {}

Node::~Node() { delete shop; }

Shop* Node::getShop() { return shop; }

Node* Node::getNext() { return next; }

void Node::setShop(Shop* shop) { this->shop = shop; }

void Node::setNext(Node* node) { this->next = node; }