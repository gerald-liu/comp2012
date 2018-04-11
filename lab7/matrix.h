#ifndef LAB7_MATRIX_H
#define LAB7_MATRIX_H

class Matrix {
public:
    /**
     * Default constructor
     */
	Matrix() {}

	/**
     * Constructor for generating an num_rows * num_cols matrix.
     * The default value for each element is 0.
     * @param num_rows the number of rows
     * @param num_cols the number of columns
     */
    Matrix(int num_rows, int num_cols);

    /**
     * Constructor for generating an num_rows * num_cols matrix.
     * The value of elements will be assigned according to given array.
     * @param data the data array
     * @param num_rows the number of rows
     * @param num_cols the number of columns
     */
    Matrix(int* data, int num_rows, int num_cols);

    /**
     * Destructor
     */
    ~Matrix();

    /**
     * Copy constructor
     * TODO: To be implemented in Task 1
     * @param mat
     */
    Matrix(const Matrix& mat);

    /**
     * Move constructor
     * TODO: To be implemented in Task 1
     * @param mat
     */
    Matrix(Matrix&& mat);

    /**
     * Assignment operator
     * TODO: To be implemented in Task 1
     * @param mat
     */
    const Matrix& operator=(const Matrix& mat);

    /**
     * Move assignment operator
     * TODO: To be implemented in Task 1
     * @param mat
     */
    const Matrix& operator=(Matrix&& mat);

    /**
     * Operator + overloading for adding two matrices
     * TODO: To be implemented in Task 2; no rvalue is required
     * @param mat
     * @return a new Matrix object of the result
     */
    Matrix operator+(const Matrix& mat);

    /**
     * Operator + for rvalue overloading for adding two matrices
     * TODO: To be implemented in Task 2
     * @param mat
     * @return the reference of the result
     */
    Matrix& operator+(Matrix&& mat);

    /**
     * Operator (x, y) for getting the matrix element
     * TODO: To be implemented in Task 2
     * @return the value at x-th row and y-th column
     */
    int operator()(int x, int y) const;

    /* Print the elements of the matrix */
    void print() const;

private:
    int* ptr {nullptr};
    int num_rows {0}, num_cols {0};
};

/* Switcher for result printing.
 * Please do not modify the following functions. */
void enable_print_step();

void disable_print_step();

#endif //LAB7_MATRIX_H
