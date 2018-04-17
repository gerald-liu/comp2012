//do NOT submit this file
//do NOT modify this file

#ifndef BSTNODE_H_
#define BSTNODE_H_

//BSTNode is the node struct that is used in the BST class
template <typename K, typename V>
struct BSTNode
{
	Pair<K, V> data; //key-value pair
	BST<K, V> left; // left sub-tree or called left child
	BST<K, V> right; // right sub-tree or called right child
	BSTNode(K key, V value) : data(key, value) {};
};

#endif /* BSTNODE_H_ */
