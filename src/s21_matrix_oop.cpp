#include "s21_matrix_oop.h"


// <------------------------ CONSTRUCTOR ------------------------>
void S21Matrix::memoryAllocation() {
    matrix = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        matrix[i] = new double[nCols] {0};
    }
}

S21Matrix::S21Matrix() {
    mRows = 0;
    nCols = 0;
    matrix = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) : mRows(rows), nCols(cols) {
    if (!isValid(rows, cols)) {
        throw std::out_of_range("Values must be bigger than 0");
    }
    memoryAllocation();
}

S21Matrix::S21Matrix(const S21Matrix& other) : mRows(other.mRows), nCols(other.nCols) {
    memoryAllocation();
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

S21Matrix::S21Matrix(S21Matrix&& other) : S21Matrix(other) {
    other.mRows = other.nCols = 0;
    other.matrix = nullptr;
}

// <------------------------ DECONSTRUCTOR ------------------------>
void S21Matrix::memoryFree() {
    for (int i = 0; i < mRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

S21Matrix::~S21Matrix() {
    if (matrix) {
        memoryFree();
        mRows = 0;
        nCols = 0;
    }
}


void S21Matrix::sum_matrix(const S21Matrix& other) {
    if (mRows != other.mRows || nCols != other.nCols) {
        throw std::out_of_range("Matrixes are not eaual");
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            matrix[i][j] += other.matrix[i][j];
        }
    }
}

bool S21Matrix::eq_matrix(const S21Matrix& other) {
    bool res = false;
    if (mRows == other.mRows || nCols == other.nCols) {
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                fabs(matrix[i][j] - other.matrix[i][j]) > EPS ? res = false : res = true;
            }
        }
    }
    return res;
}

void S21Matrix::sub_matrix(const S21Matrix& other) {
    if (mRows != other.mRows || nCols != other.nCols) {
        throw std::out_of_range("Matrixes are not eaual");
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
}

void S21Matrix::mul_number(const double number) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            matrix[i][j] *= number;
        }
    }
}

void S21Matrix::mul_matrix(const S21Matrix& other) {
    if (nCols != other.mRows) {
        throw std::out_of_range("Matrix are not equal size");
    }
    S21Matrix res(mRows, nCols);
    for (int i = 0; i < res.mRows; ++i) {
        for (int j = 0; j < res.nCols; ++j) {
            for (int c = 0; c < nCols; ++c) {
                res.matrix[i][j] += matrix[i][c] * other.matrix[c][j];
            }
        }
    }
    *this = res;
}

S21Matrix S21Matrix::transpose() {
    S21Matrix res(nCols, mRows);
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            res.matrix[j][i] = matrix[i][j];
        }
    }
    return res;
}

S21Matrix S21Matrix::calc_complements() {
    S21Matrix res(mRows, nCols);
    if (mRows != nCols) {
        throw std::out_of_range("Matrixes are not square");
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            S21Matrix minor = minorMatrix(i, j);
            res.matrix[i][j] = pow(-1, (i + j)) * minor.determinant();
        }
    }
    return res;
}

double S21Matrix::determinant() {
    double determinant = 0.0;
    if (mRows != nCols) {
        throw std::out_of_range("Matrixes are not square");
    }
    int degree = 1;
    if (mRows == 1) {
        determinant = matrix[0][0];
    } else if (mRows == 2) {
        determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else if (mRows > 2) {
        for (int i = 0; i < mRows; ++i) {
            S21Matrix minor = minorMatrix(0, i);
            determinant += degree * matrix[0][i] * minor.determinant();
            degree = -degree;
        }
    }
    return determinant;
}

S21Matrix S21Matrix::inverse_matrix() {
    double det = determinant();
    if (fabs(this->determinant()) < EPS) {
        throw std::out_of_range("Error! Incorrect input");
    }
    S21Matrix calc = calc_complements();
    S21Matrix matTrans = calc.transpose();
    matTrans.mul_number(1.0 / det);
    return matTrans;
}

// <--------------- OPERATORS OVERLOAD ------------------>
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
    S21Matrix res(*this);
    res.sum_matrix(other);
    return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
    S21Matrix res(*this);
    res.sub_matrix(other);
    return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
    S21Matrix res(*this);
    res.mul_matrix(other);
    return res;
}

S21Matrix S21Matrix::operator*(const double number) {
    S21Matrix res(*this);
    res.mul_number(number);
    return res;
}

bool S21Matrix::operator==(const S21Matrix other) {
    return eq_matrix(other);
}

S21Matrix S21Matrix::operator=(const S21Matrix& other) {
    if (this != &other) {
        memoryFree();
        mRows = other.mRows;
        nCols = other.nCols;
        memoryAllocation();
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
    sum_matrix(other);
    return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
    sub_matrix(other);
    return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
    mul_matrix(other);
    return *this;
}

S21Matrix S21Matrix::operator*=(const double number) {
    mul_number(number);
    return *this;
}
// <---------------------- INDEXES ---------------------->
int S21Matrix::getRow() {
    return mRows;
}

int S21Matrix::getCol() {
    return nCols;
}

void S21Matrix::setRow(int rows) {
    if (rows <= 0) {
        throw std::out_of_range("Error! Input must be positive");
    }
    if (mRows > rows) {
        mRows = rows;
    } else {
        S21Matrix temp(rows, nCols);
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                temp.matrix[i][j] = matrix[i][j];
            }
        }
        memoryFree();

        mRows = rows;
        memoryAllocation();
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                matrix[i][j] = temp.matrix[i][j];
            }
        }
        temp.memoryFree();
    }
}


void S21Matrix::setCol(int cols) {
    if (cols <= 0) {
        throw std::out_of_range("Error! Input must be positive");
    }
    if (nCols > cols) {
        nCols = cols;
    } else {
        S21Matrix temp(mRows, cols);
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                temp.matrix[i][j] = matrix[i][j];
            }
        }
        memoryFree();
        nCols = cols;
        memoryAllocation();
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < nCols; ++j) {
                matrix[i][j] = temp.matrix[i][j];
            }
        }
        temp.memoryFree();
    }
}


// <--------------------- PROTECTED --------------------->
bool S21Matrix::isValid(int rows, int cols) {
    return rows > 0 && cols > 0;
}

// <------------------------ SUB ------------------------>
S21Matrix S21Matrix::minorMatrix(int rows, int cols) {
    S21Matrix res(mRows - 1, nCols - 1);
    int tempRows = 0;
    for (int i = 0 ; i < res.mRows; ++i) {
        if (i == rows) {
            tempRows = 1;
        }
        int tempCols = 0;
        for (int j = 0; j < res.nCols; ++j) {
            if (j == cols) {
                tempCols = 1;
            }
            res.matrix[i][j] = matrix[i + tempRows][j + tempCols];
        }
    }
    return res;
}

S21Matrix::S21Matrix(int rows, int cols, double data[]) : mRows(rows), nCols(cols) {
    memoryAllocation();
    int l = 0;
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            matrix[i][j] = data[l];
            l++;
        }
    }
}

// void S21Matrix::print() {
//     std::cout << "\n";
//     for (int i = 0; i < mRows; ++i) {
//         for (int j = 0; j < nCols; ++j) {
//             std::cout << matrix[i][j] << "  ";
//         }
//         std::cout << "\n";
//     }
//     std::cout << "\n";
// }
