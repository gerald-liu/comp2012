#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"
using namespace std;

/* This function checks whether a string token is numeric. Do not modify anything! */
bool isNumeric(const string& token) {
	if (token.empty() || ((!isdigit(token[0])) && (token[0] != '-') && (token[0] != '+'))) return false;
	char* p; strtod(token.c_str(), &p);
	return (*p == 0);
}

double evaluatePostfixExpression(const string& expression, char delim=' ') {
	/****** START YOUR IMPLEMENTATION FOR PART 2 HERE ******/

	stringstream ss(expression);
	string token;
	while (getline(ss, token, delim)) {
		// HINT: The variable "token" here is storing either
		//       an operand or an operator scanning from left to right.



	}
	return 0.0;

	/******* END YOUR IMPLEMENTATION FOR PART 2 HERE *******/
}

int main() {
	cout << "======================================" << endl;
	cout << "Part A: Implementation" << endl;
	cout << "======================================" << endl;

	Stack<int> stack_1, stack_2;
	stack_1 += 10; // stack_1 => [10]
	stack_1 += 5;  // stack_1 => [10, 5]
	stack_2 += 10; // stack_2 => [10]
	stack_2 += 10; // stack_2 => [10, 10]

	cout << boolalpha << (stack_1 == stack_2) << endl; // [10, 5] == [10, 10] ?
	stack_2--;    // stack_2 => [10]
	stack_2 += 5; // stack_2 => [10, 5]
	cout << boolalpha << (stack_1 == stack_2) << endl; // [10, 5] == [10, 5] ?
	stack_1--; // stack_1 => [10]
	stack_1--; // stack_1 => []
	stack_1--; // stack_1 => [] ** EMPTY ERROR x1
	cout << boolalpha << stack_1.empty() << endl; // [] == empty ?

	cout << stack_2 << endl;        // stack_2 => [10, 5] displays:
									// 5
									// 10

	cout << ~stack_2 << endl;       // 5
	cout << stack_2.size() << endl; // size of [10, 5]
	cout << stack_2.full() << endl; // [10, 5] == full?
	for (int i = 0; i < STACK_CAPACITY; i++) stack_2 += i;  // [10, 5, 0, 1, 2, ..., 61]  ** FULL ERROR x2
	cout << stack_2.size() << endl; // size of [10, 5, 0, 1, 2, ..., 61]
	cout << stack_2.full() << endl; // [10, 5, 0, 1, 2, ..., 61] == full ?

	stack_1 += 1; 			   // stack_1 => [1]
	cout << --stack_1 << endl; // [] ** EMPTY ERROR x1
	cout << endl;

	cout << "======================================" << endl;
	cout << "Part B: Postfix Expression Calculator " << endl;
	cout << "======================================" << endl;

	// Infix expression = (10 / 5) * (7 - 2) = 10
	cout << "(1) " << "10 5 / 7 2 - *              = " << evaluatePostfixExpression("10 5 / 7 2 - *") << endl;
	// Infix expression = (2.5 * (8 + (60 / 3)) / 2) + 2 = 37
	cout << "(2) " << "2.5 8 60 3 / + * 2 / 2 +    = " << evaluatePostfixExpression("2.5 8 60 3 / + * 2 / 2 +") << endl;
	// Infix expression = ((((2 * 30) + (10 / 2)) * 3) - 9) / 4
	cout << "(3) " << "2 30 * 10 2 / + 3 * 9 - 4 / = " << evaluatePostfixExpression("2 30 * 10 2 / + 3 * 9 - 4 /") << endl;

	return 0;
}
