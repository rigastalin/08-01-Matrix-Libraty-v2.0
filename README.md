# Matrix Library v2.0

Implementation of the _matrix_oop.h library.

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
    2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
    3.1. [Part 1](#part-1-implementation-of-the-_matrix_ooph-library-functions)


## Chapter I
## Introduction

In this project, you I implemented the matrix library project, but this time you I used the object-oriented approach. The object-oriented approach allows to implement a library for matrices as a separate class whose objects have defined operations, that can be represented both as methods and as standard operators +, -, *, etc.


## Chapter II

## Information

### C++ and C

C++ is a programming language based on the C language for implementing programs using an object-oriented approach. This means that the C++ syntax rules are directly derived from C, and so, most of the C code can be copied into programs with C++ and successfully compiled.
For the most part, C++ only adds new opportunities for the programmer or modifies them rather than removes something, so when it comes to C++, it's easier to talk about the differences (see materials) than the similarities.


### A reminder of the matrix basics

Matrix is a rectangular table of numbers arranged in m rows and n columns

You can get the desired element using indices as follows A[1,1] = 1, where the first index is the row number, the second is the column number.

The order of a matrix is the number of its rows or columns. \
The main diagonal of a square matrix is the diagonal from the upper left to the lower right corner. \

A rectangular matrix (B) is a matrix with the number of rows not equal to the number of columns. \
A square matrix (A) is a matrix with the number of rows equal to the number of columns.

## Matrix operations

There is a brief description of the matrix operations below that need to be implemented in the developing library.
They are similar to the operations you performed earlier in «structured programming», so you can see a more detailed description of them there.
Note that some operations have exceptional situations that require special handling using the exception mechanism.

| Operation | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `bool eq_matrix(const Matrix& other)` | Checks matrices for equality with each other |  |
| `void sum_matrix(const Matrix& other)` | Adds the second matrix to the current one | different matrix dimensions |
| `void sub_matrix(const Matrix& other)` | Subtracts another matrix from the current one | different matrix dimensions |
| `void mul_number(const double num) ` | Multiplies the current matrix by a number |  |
| `void mul_matrix(const Matrix& other)` | Multiplies the current matrix by the second matrix | the number of columns of the first matrix is not equal to the number of rows of the second matrix |
| `Matrix transpose()` | Creates a new transposed matrix from the current one and returns it |  |
| `Matrix calc_complements()` | Calculates the algebraic addition matrix of the current one and returns it | the matrix is not square |
| `double determinant()` | Calculates and returns the determinant of the current matrix | the matrix is not square |
| `Matrix inverse_matrix()` | Calculates and returns the inverse matrix | matrix determinant is 0 |

Apart from those operations, you also need to implement constructors and destructors:

| Method | Description |
| ----------- | ----------- |
| `Matrix()` | A basic constructor that initialises a matrix of some predefined dimension |  
| `Matrix(int rows, int cols) ` | Parametrized constructor with number of rows and columns |
| `Matrix(const Matrix& other)` | Copy constructor |
| `Matrix(Matrix&& other)` | Move constructor |
| `~Matrix()` | Destructor |

And you also need to overload the following operators, partly corresponding to the operations above:

| Operator | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `+`      | Addition of two matrices | different matrix dimensions |
| `-`   | Subtraction of one matrix from another | different matrix dimensions |
| `*`  | Matrix multiplication and matrix multiplication by a number | the number of columns of the first matrix does not equal the number of rows of the second matrix |
| `==`  | Checks for matrices equality (`eq_matrix`) | |
| `=`  | Assignment of values from one matrix to another one | |
| `+=`  | Addition assignment (`sum_matrix`) | different matrix dimensions |
| `-=`  | Difference assignment (`sub_matrix`) | different matrix dimensions |
| `*=`  | Multiplication assignment (`mul_matrix`/`mul_number`) | the number of columns of the first matrix does not equal the number of rows of the second matrix |
| `(int i, int j)`  | Indexation by matrix elements (row, column) | index is outside the matrix |


## Chapter III

## Part 1. Implementation of the _matrix_oop.h library functions

- The program must be developed in C++ language of C++17 standard using gcc compiler
- The program code must be located in the src folder
- Implement the matrix as an `Matrix` class
- Use only the `matrix`, `rows` and `columns` fields as private
- Implement the access to private fields `rows` and `columns` via accessor and mutator
- Make it as a static library (with _matrix_oop.h header file)
- Implement the operations described [above](#matrix-operations)
- Overload the operators according to the table in the chapter [above](#matrix-operations)
- Prepare full coverage of library functions code with unit-tests using the GTest library
- Provide a Makefile for building the library and tests (with targets all, clean, test, _matrix_oop.a)

