#include <iostream>

using namespace std;

template <typename T>
class A_Tree {
private:
	struct A_Node { A_Tree tree; };
	A_Node* root;
};

template <typename T>
class B_Tree {
private:
	struct B_Node {
		B_Tree tree; 
		B_Node(const B_Tree& b_tree) : tree{b_tree} {}
	};
	B_Node* root;

public:	
	B_Tree(const A_Tree<T>& a) {
		B_Tree* b_tree = new B_Tree(a.root->tree);
		root = new B_Node(*b_tree);
	}
};

int main() {
	A_Tree<int> a_tree;
	B_Tree<int> b_tree(a_tree);
}
