template <typename KeyType, typename ValueType>
ostream& operator<<(ostream& os, const Container<KeyType, ValueType>& c) {
	c.print(os);
	return os;
}

template <typename KeyType, typename ValueType>
ostream& operator<<(ostream& os, const HashingVault<KeyType, ValueType>& hv) {
	hv.print(os);
	return os;
}