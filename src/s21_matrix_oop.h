#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <iostream>
#include <cstring>
#include <cmath>
#include <exception>

#define EPS 1e-6

class S21Matrix {
 private:
  double **matrix;
  int mRows, nCols;
  void memoryAllocation();
  void memoryFree();

 public:
  S21Matrix();
  ~S21Matrix();

  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  void sum_matrix(const S21Matrix& other);
  bool eq_matrix(const S21Matrix& other);
  void sub_matrix(const S21Matrix& other);
  void mul_number(const double number);
  void mul_matrix(const S21Matrix& other);

  S21Matrix transpose();
  S21Matrix calc_complements();
  double determinant();
  S21Matrix inverse_matrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(double number);
  bool operator==(const S21Matrix other);
  S21Matrix operator=(const S21Matrix& other);
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(double number);

  int getRow();
  int getCol();
  void setRow(int rows);
  void setCol(int cols);

  // SUB
  S21Matrix minorMatrix(int rows, int cols);
  S21Matrix(int rows, int cols, double data[]);
  // void print();

 protected:
  bool isValid(int rows, int cols);
};

#endif  // SRC_S21_MATRIX_OOP_H_
