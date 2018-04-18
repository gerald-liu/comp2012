template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::HashingVault(int size, Container<KeyType, ValueType>** table, int (*fun)(KeyType))
	: table{table}, size{size}, fun{fun} {}

template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::~HashingVault() {
	for (int i = 0; i < size; i++) delete table[i];
	delete[] table;
}

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::add(KeyType key, ValueType value) {
	Container<KeyType, ValueType>* c = table[fun(key)];
	if (c->get(key) != ValueType()) return false;
	else c->add(key, value);
	return true;
}

template <typename KeyType, typename ValueType>
ValueType HashingVault<KeyType, ValueType>::get(KeyType key) const { return table[fun(key)]->get(key); }

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::remove(KeyType key) {
	Container<KeyType, ValueType>* c = table[fun(key)];
	if (c->get(key) == ValueType()) return false;
	else c->remove(key);
	return true;
}

template <typename KeyType, typename ValueType>
void HashingVault<KeyType, ValueType>::rehash(int size, Container<KeyType, ValueType>** table, int (*fun)(KeyType)) {
	for (int i = 0; i < this->size; i++) {
		while (this->table[i]->count() != 0) {
			const Pair<KeyType, ValueType>* data = (*this->table[i])[0];
			table[fun(data->key)]->add(data->key, data->value);
			this->table[i]->remove(data->key);
		}
		delete this->table[i];
	}
	delete[] this->table;
	this->table = table;
	this->size = size;
	this->fun = fun;
}