#ifndef BSTEXERCISES_H_
#define BSTEXERCISES_H_

#include <cmath>
#include "BST.h"

// ******************* DO NOT MODIFY THIS FUNCTION *******************
// Calculate the height of a binary tree. The height of a tree is the
// number of nodes on the longest downward path between the root and
// a leaf.
template <typename KT, typename VT>
int treeHeight(const BST<KT, VT>& bst) {
	if (bst.is_empty()) return 0;
	return 1 + max(treeHeight(bst.root->left), treeHeight(bst.root->right));
}

// Determine whether the binary tree is balanced. An empty tree is
// height-balanced. A non-empty binary tree is balanced if the heights of
// the two subtrees of any of its nodes differ at most one. Conceptually,
// a binary tree is balanced if
//     1) the left subtree is balanced
//     2) the right subtree is balanced
//     3) the difference between heights of left subtree and right subtree
//		  is not more than 1
template <typename KT, typename VT>
bool isBalanced(const BST<KT, VT>& bst) {
	/****** START YOUR IMPLEMENTATION FOR PART A1 HERE ******/

	if (bst.is_empty()) return true;
	return isBalanced(bst.root->left) && isBalanced(bst.root->right)
		&& (abs(treeHeight(bst.root->left) - treeHeight(bst.root->right)) <= 1);

	/******* END YOUR IMPLEMENTATION FOR PART A1 HERE *******/
}

// Calculate the number of nodes on the longest path between two leaves.
// Conceptually, the diameter of a tree is the maximum of
//     1) the diameter of the left tree
//     2) the diameter of the right tree
//     3) the longest path between leaves that goes through the root of the tree
//        (HINT: You can compute it using the heights of the subtrees)
template <typename KT, typename VT>
int diameter(const BST<KT, VT>& bst) {
	/****** START YOUR IMPLEMENTATION FOR PART A2 HERE ******/

	if (bst.is_empty()) return 0;
	return max(max(diameter(bst.root->left),diameter(bst.root->right)),
		treeHeight(bst.root->left) + treeHeight(bst.root->right) + 1);

	/****** START YOUR IMPLEMENTATION FOR PART A2 HERE ******/
}

// Decode the morse code symbol. You can use an asterisk (*) to be the
// default result (you need to return something when you encounter an
// error such as syntax error or empty bst although they will not occur
// under our assumptions).
char decode(const BST<int, char>& bst, const string& symbol, unsigned int index = 0) {
	/****** START YOUR IMPLEMENTATION FOR PART B2 HERE ******/

	if (bst.is_empty()) return '*';
	const BST<int, char>* result = &bst;
	for (string::const_iterator it = symbol.begin(); it < symbol.end(); it++)
		result = (*it == '.') ? &result->root->left : &result->root->right;
	return result->root->value;

	/******* END YOUR IMPLEMENTATION FOR PART B2 HERE *******/
}

#endif /* BSTEXERCISES_H_ */
