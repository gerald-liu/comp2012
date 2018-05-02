template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::HashingVault(int size, Container<KeyType, ValueType>** table, int (*fun)(KeyType))
	: table{table}, size{size}, fun{fun} {}

template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::~HashingVault() {
	for (int i = 0; i < size; i++) delete table[i];
	delete[] table;
}

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::add(KeyType key, ValueType value) { return table[fun(key)]->add(key, value); }

template <typename KeyType, typename ValueType>
ValueType HashingVault<KeyType, ValueType>::get(KeyType key) const { return table[fun(key)]->get(key); }

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::remove(KeyType key) { return table[fun(key)]->remove(key); }

template <typename KeyType, typename ValueType>
void HashingVault<KeyType, ValueType>::rehash(int size, Container<KeyType, ValueType>** table, int (*fun)(KeyType)) {
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->table[i]->count(); j++) {
			const Pair<KeyType, ValueType>* data = (*this->table[i])[j];
			table[fun(data->key)]->add(data->key, data->value);
		}
		delete this->table[i];
	}
	delete[] this->table;
	this->table = table;
	this->size = size;
	this->fun = fun;
}
