template <typename KeyType, typename ValueType>
BST<KeyType, ValueType>::BST(const BST& another) : size{another.size} {
	if (another.isEmpty()) return;
	root = new BSTNode<KeyType, ValueType>(*another.root);
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::isEmpty() const { return (root == nullptr); }

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType>* BST<KeyType, ValueType>::findMin() const {
	if (isEmpty()) return nullptr;
	const BST<KeyType, ValueType>* t = this;
	while (!t->leftSubtree().isEmpty()) t = &t->leftSubtree();
	return t;
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType>& BST<KeyType, ValueType>::rightSubtree() const { return root->right; }

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType>& BST<KeyType, ValueType>::leftSubtree() const { return root->left; }

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::add(KeyType key, ValueType value) {
	bool added = false;
	if (isEmpty()) {
		root = new BSTNode<KeyType, ValueType>(key, value);
		added = true;
	}
	else if (key < root->data.key) added = root->left.add(key, value);
	else if (key > root->data.key) added = root->right.add(key, value);
	else return false;
	if (added) size++;
	return added;
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::remove(KeyType key) {
	bool removed = false;
	if (isEmpty()) return false;
	else if (key < root->data.key) removed = root->left.remove(key);
	else if (key > root->data.key) removed = root->right.remove(key);
	else if (root->left.root && root->right.root) {
		root->data = root->right.findMin()->root->data;
		removed = root->right.remove(root->data.key);
	}
	else {
		BSTNode<KeyType, ValueType>* toDelete = root;
		root = root->left.isEmpty() ? root->right.root : root->left.root;
		toDelete->left.root = toDelete->right.root = nullptr;
		delete toDelete;
		removed = true;
	}
	if (removed) size--;
	return removed;
}

template <typename KeyType, typename ValueType>
ValueType BST<KeyType, ValueType>::get(KeyType key) const {
	if (isEmpty()) return (typeid(ValueType) == typeid(int)) ? 0 : ValueType();
	else if (key < root->data.key) return root->left.get(key);
	else if (key > root->data.key) return root->right.get(key);
	else return root->data.value;
}

template <typename KeyType, typename ValueType>
int BST<KeyType, ValueType>::count() const { return size; }

template <typename KeyType, typename ValueType>
int BST<KeyType, ValueType>::height() const {
	if (isEmpty()) return 0;
	else if (!root->left.root && !root->right.root) return 0;
	else {
		int leftHeight = root->left.height();
		int rightHeight = root->right.height();
		return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
	}
}

template <typename KeyType, typename ValueType>
const Pair<KeyType, ValueType>* BST<KeyType, ValueType>::operator[](int n) const {
	if (n < 0 || n >= size || isEmpty()) return nullptr;
	else if (size == 1) return &root->data;
	else if (n < root->left.size) return root->left[n];
	else if (n > root->left.size) return root->right[n - root->left.size - 1];
	else return &root->data;
}

template <typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::print(ostream& os) const {
	if (isEmpty()) return;
	root->left.print(os);
	os << '(' << root->data.key << ',' << root->data.value << ')';
	root->right.print(os);
}