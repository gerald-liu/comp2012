#ifndef BST_H_
#define BST_H_

using namespace std;

/*
 *   **** You should not modify this file! ****
 */
template <typename KT, typename VT>
class BST {
public:
    struct BSTnode {
    	KT key;
        VT value;
        BST left;
        BST right;
        BSTnode(const KT& k, const VT& v) : key(k), value(v), left(), right() { }
        ~BSTnode() { }
    };
    BSTnode* root = nullptr;

    BST() = default;
    ~BST() { delete root; }

    bool is_empty() const { return root == nullptr; }
    void print(int depth = 0) const {
    	if (is_empty()) return;
		root->right.print(depth+1);
		for (int j = 0; j < depth; j++)
			cout << '\t';
		cout << "(" << root->key << "," << root->value << ")" << endl;
		root->left.print(depth+1);
    }

    void insert(const KT& k, const VT& v) {
    	if (is_empty())
			root = new BSTnode(k, v);
		else if (k < root->key)
			root->left.insert(k, v);
		else if (k > root->key)
			root->right.insert(k, v);
    }
};

#endif /* BST_H_ */
