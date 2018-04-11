#include <iostream>
#include "matrix.h"

using namespace std;

bool print_step{ false };

/**
 * Constructor for generating an num_rows * num_cols matrix.
 * The default value for each element is 0.
 * @param num_rows the number of rows
 * @param num_cols the number of columns
 */
Matrix::Matrix(int num_rows, int num_cols) : num_rows{ num_rows }, num_cols{ num_cols } {
    if (print_step) cout << "constructor" << endl;
    ptr = new int[num_rows * num_cols];
    for (int i = 0; i < num_rows * num_cols; i++) ptr[i] = 0;
}

/**
 * Constructor for generating an num_rows * num_cols matrix.
 * The value of elements will be assigned according to given array.
 * @param data the data array
 * @param num_rows the number of rows
 * @param num_cols the number of columns
 */
Matrix::Matrix(int* data, int num_rows, int num_cols) : num_rows{ num_rows }, num_cols{ num_cols } {
    if (print_step) cout << "constructor" << endl;
    ptr = new int[num_rows * num_cols];
    for (int i = 0; i < num_rows * num_cols; i++) ptr[i] = data[i];
}

/**
 * Destructor
 */
Matrix::~Matrix() { if (ptr != nullptr) delete[] ptr; }

/**
 * Copy constructor
 * TODO: To be implemented in Task 1
 * @param mat
 */
Matrix::Matrix(const Matrix& mat) : num_rows{ mat.num_rows }, num_cols{ mat.num_cols } {
    if (print_step) cout << "copy constructor" << endl;
	ptr = new int[num_rows * num_cols];
	for (int i = 0; i < num_rows * num_cols; i++) ptr[i] = mat.ptr[i];
}

/**
 * Move constructor
 * TODO: To be implemented in Task 1
 * @param mat
 */
Matrix::Matrix(Matrix&& mat) : ptr{ mat.ptr }, num_rows{ mat.num_rows }, num_cols{ mat.num_cols } {
    if (print_step) cout << "move constructor" << endl;
	mat.num_rows = 0;
	mat.num_cols = 0;
	mat.ptr = nullptr;
}

/**
 * Assignment operator
 * TODO: To be implemented in Task 1
 * @param mat
 */
const Matrix& Matrix::operator=(const Matrix& mat) {
    if (print_step) cout << "operator =" << endl;
	if (this == &mat) return *this;

	num_rows = mat.num_rows;
	num_cols = mat.num_cols;

	delete[] ptr;
	ptr = new int[num_rows * num_cols];
	for (int i = 0; i < num_rows * num_cols; i++) ptr[i] = mat.ptr[i];

	return *this;
}

/**
 * Move assignment operator
 * TODO: To be implemented in Task 1
 * @param mat
 */
const Matrix& Matrix::operator=(Matrix&& mat) {
    if (print_step) cout << "move operator =" << endl;
	if (this == &mat) return *this;

	num_rows = mat.num_rows;
	num_cols = mat.num_cols;

	delete[] ptr;
	ptr = mat.ptr;

	mat.num_rows = 0;
	mat.num_cols = 0;
	mat.ptr = nullptr;

	return *this;
}

/**
 * Operator + overloading
 * TODO: To be implemented in Task 2; no rvalue is required
 * @param mat the reference of another Matrix
 * @return
 */
Matrix Matrix::operator+(const Matrix& mat) {
    if (print_step) cout << "operator +" << endl;
	Matrix m{ mat.ptr, mat.num_rows, mat.num_cols };
	for (int i = 0; i < num_rows * num_cols; i++) m.ptr[i] += ptr[i];
	return move(m);
}

/**
 * Operator + for rvalue overloading
 * TODO: To be implemented in Task 2
 * @param mat the rvalue reference of another Matrix
 * @return
 */
Matrix& Matrix::operator+(Matrix&& mat) {
    if (print_step) cout << "operator + for rvalue" << endl;
	for (int i = 0; i < num_rows * num_cols; i++) mat.ptr[i] += ptr[i];
	return mat;
}

/**
 * Operator (x, y) for getting the matrix element
 * TODO: To be implemented in Task 2
 * @return the value at x-th row and y-th column
 */
int Matrix::operator()(int x, int y) const { return ptr[x * num_cols + y]; }

/* Print the elements of the matrix */
void Matrix::print() const {
    for (int i = 0; i < num_rows; i++) {
        cout << (i == 0 ? "[" : " ");
        for (int j = 0; j < num_cols; j++) {
            cout << ptr[i * num_cols + j];
            if (j != num_cols - 1) cout << ", ";
        }
        cout << (i == num_rows - 1 ? "]" : ";");
        cout << endl;
    }
}

/* Switcher for result printing.
 * Please do not modify the following methods. */
void enable_print_step() { print_step = true; }

void disable_print_step() { print_step = false; }