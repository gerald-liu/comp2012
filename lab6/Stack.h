#include <iostream>

using namespace std;
const int STACK_CAPACITY = 64;

template <typename T>
class Stack {
public:
	Stack() {};
	~Stack() {};

	/****** START YOUR DECLARATION FOR PART 1 HERE ******/

	// ACCESSOR member functions:
	bool empty() const;    // Check if the stack is empty
	bool full() const;	   // Check if the stack is full
	int size() const;	   // Give the number of data currently stored

	// TODO: Overload operator "~" to retrieve the top item from the stack
	T operator~() const;

	// TODO: Overload operator "==" to check the equality of stack objects
	bool operator==(Stack<T>&) const;

	// TODO: Overload operator "<<" to show the items stored in the stack object
	template<class U>
	friend ostream& operator<<(ostream&, Stack<T>&);

	// MUTATOR member functions:
	// TODO: Overload operator "+=" to add a new item to the top
	const Stack<T>& operator+=(const T&);

	// TODO: Overload operator "--" to remove the top item from the stack
	//       and return the new top item (** SYNTAX: Stack<int> A; --stack; **)
	T& operator--();

	// TODO: Overload operator "--" to return the top item and remove it
	//       from the stack (** SYNTAX: Stack<int> A; stack--; **)
	T operator--(int);

	/******* END YOUR DECLARATION FOR PART 1 HERE *******/

private:
	T data[STACK_CAPACITY]; // Use an array to store the data
	int top_index {-1};		// Start from 0; -1 when empty
};

/****** START YOUR IMPLEMENTATION FOR PART 1 HERE ******/

template<typename T>
inline bool Stack<T>::empty() const { return top_index == -1; }

template<typename T>
inline bool Stack<T>::full() const { return top_index == STACK_CAPACITY - 1; }

template<typename T>
inline int Stack<T>::size() const { return top_index + 1; }

template<typename T>
inline T Stack<T>::operator~() const {
	if (!empty()) return data[top_index];	else {
		cerr << "[ERROR] Stack is empty, returning a garbage value\n";
		return T();
	}
}

template<typename T>
inline bool Stack<T>::operator==(Stack<T>& s) const {
	if (top_index != s.top_index) return false;
	Stack<T> temp1, temp2;
	while (!empty()) {
		if (~this* != ~s) return false;
		temp1 += (--this*);
		temp2 += (--s);
	}
	while (!temp1.empty()) {
		this* += (--temp1);
		s += (--temp2);
	}
	return true;
}

template<typename T>
ostream& operator<<(ostream& os, Stack<T>& s) {
	Stack<T> temp;
	while (!empty()) {
		os << ~s << '\n';
		temp += (--s);
	}
	while (!temp.empty()) s += (--temp);
	return os;
}

template<typename T>
inline const Stack<T>& Stack<T>::operator+=(const T& t) {
	data[top_index + 1] = t;
	top_index++;
	return *this;
}

template<typename T>
inline T& Stack<T>::operator--() {
	top_index--;
	return data[top_index];
}

template<typename T>
inline T Stack<T>::operator--(int) {
	int i = top_index;
	top_index--;
	return data[i];
}

/******* END YOUR IMPLEMENTATION FOR PART 1 HERE *******/