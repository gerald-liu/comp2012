//do NOT submit this file
//do NOT modify this file

#ifndef BST_H_
#define BST_H_

#include "container.h"
#include <typeinfo>
using namespace std;

template <typename KeyType, typename ValueType>
class BST;
#include "bstNode.h"

//BST is a Binary Search Tree class
template <typename KeyType, typename ValueType>
class BST : public Container<KeyType, ValueType>
{
private:
	BSTNode<KeyType, ValueType>* root = nullptr; //the root node; empty tree's root is nullptr
    int size = 0; //the number of nodes in the tree including the root node; it will not be checked when we grade your work, 
				 //but correctly maintaining this number may be useful for your implementation in certain member functions
				 //it should have the same value as the returned value of count()
	
public:
    //constructor
    BST() = default;

    //destructor
    //given; do not modify
    virtual ~BST() override { delete root; }

    //deep copy constructor
    BST(const BST& another);
	
    //return true if the tree is empty (i.e. no node at all)
    //return false otherwise
    bool isEmpty() const;

    //return the subtree that has the minimum-value node as its root node
    //return nullptr if the tree is empty
    const BST* findMin() const;

	//return the reference to the right subtree
	const BST& rightSubtree() const;

	//return the reference to the left subtree
	const BST& leftSubtree() const;

	//add a node to the tree, according to the given key and value
	//you have to use the exact algorithm described in the lecture notes
	//you should have the exact same result as our sample output
	//it should do nothing to the tree and return false when there is already a node that has the same key
	//otherwise, it should add the node and return true
	virtual bool add(KeyType key, ValueType value) override;

	//remove a node from the tree, according to the given key
	//if the key is found, it should remove the node and return true
	//otherwise, return false
	//note: you have to use the exact algorithm described in the lecture notes
	//when you need to delete a node that has 2 children,
	//you must replace the deleted node with the minimum node in its right sub-tree
	virtual bool remove(KeyType key) override;

	//return the node's value given a key
	//if the key is not found in the tree, refer to Container for the code that you should use
	virtual ValueType get(KeyType key) const override;

	//return the number of nodes in this tree
	virtual int count() const override;

	//return the height of this tree
	//tree height is defined in the lecture notes
	//also, height of an empty tree (i.e. no node at all) is 0
	//and that of a single-node tree (i.e. only the root node exists) is 0
	int height() const;

	//as described in the Container class
	virtual const Pair<KeyType, ValueType>* operator[] (int n) const override;

	//as described in the Container class
	//refer to the webpage for detailed description
	virtual void print(ostream& os) const override;

	//print the tree to the console
	//note that displayed tree is rotated 90 degree clockwise
	//given; do not modify
	void printTree(int depth=0) const
	{
	    if (isEmpty())
	       return;

        root->right.printTree(depth+1);

	    for (int j = 0; j < depth; j++)
	        cout << "\t\t";
	    cout << "(" << root->data.key << "," << root->data.value << ")" << endl;

        root->left.printTree(depth+1);
	}
};

#include "bst.tpp"

#endif
