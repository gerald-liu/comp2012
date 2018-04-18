template <typename KeyType, typename ValueType>
SmartArray<KeyType, ValueType>::SmartArray() : data{nullptr}, size{0} {}

template <typename KeyType, typename ValueType>
SmartArray<KeyType, ValueType>::~SmartArray() {
	for (int i = 0; i < size; i++) delete data[i];
	delete[] data;
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::add(KeyType key, ValueType value) {
	int i = 0;
	for (; i < size; i++) {
		if (data[i]->key == key) return false;
		if (data[i]->key > key) break;
	}
	Pair<KeyType, ValueType>** temp = new Pair<KeyType, ValueType>* [++size];
	for (int j = 0; j < i; j++) temp[j] = data[j];
	temp[i] = new Pair<KeyType, ValueType>(key, value);
	for (int j = i + 1; j < size; j++) temp[j] = data[j - 1];
	delete[] data;
	data = temp;
	return true;
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::remove(KeyType key) {
	for (int i = 0; i < size; i++) {
		if (data[i]->key == key) {
			Pair<KeyType, ValueType>** temp = new Pair<KeyType, ValueType>* [--size];
			for (int j = 0; j < i; j++) temp[j] = data[j];
			delete data[i];
			for (int j = i; j < size; j++) temp[j] = data[j + 1];
			delete[] data;
			data = temp;
			return true;
		}
	}
	return false;
}

template <typename KeyType, typename ValueType>
ValueType SmartArray<KeyType, ValueType>::get(KeyType key) const {
	for (int i = 0; i < size; i++) if (data[i]->key == key) return data[i]->value;
	return (typeid(ValueType) == typeid(int)) ? 0 : ValueType();
}

template <typename KeyType, typename ValueType>
int SmartArray<KeyType, ValueType>::count() const { return size; }

template <typename KeyType, typename ValueType>
const Pair<KeyType, ValueType>* SmartArray<KeyType, ValueType>::operator[](int n) const {
	return (n >=0 && n < size) ? data[n] : nullptr;
}

template <typename KeyType, typename ValueType>
void SmartArray<KeyType, ValueType>::print(ostream& os) const {
	for (int i = 0; i < size; i++) os << '(' << data[i]->key << ',' << data[i]->value << ')';
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::has(KeyType key) const {
	for (int i = 0; i < size; i++) if (data[i]->key == key) return true;
	return false;
}