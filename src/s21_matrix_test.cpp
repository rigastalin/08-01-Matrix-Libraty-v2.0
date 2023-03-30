#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(contructor, T1) {
    S21Matrix matrix1;
    S21Matrix matrix2(3, 3);
    S21Matrix matrix3(matrix2);
    S21Matrix matrix4(matrix3);
    ASSERT_TRUE(matrix3 == matrix2);
}

TEST(contructor1, T1) {
    S21Matrix matrix1(4, 4);
    S21Matrix matrix2((matrix1));
    ASSERT_TRUE(matrix1.eq_matrix(matrix2));
}

TEST(sum, T1) {
    try {
        double fillMatrix1[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        double fillMatrix2[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        double result[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        S21Matrix matrix1(3, 3, fillMatrix1);
        S21Matrix matrix2(3, 3, fillMatrix2);
        S21Matrix matrix3(3, 3, result);
        S21Matrix res = matrix1 + matrix2;
        ASSERT_TRUE(matrix3 == res);
    } catch (std::exception & ex) {
        std::cout << ex.what();
    }
}

TEST(sub, T1) {
    try {
        double fillMatrix1[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        double fillMatrix2[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        double result[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        S21Matrix matrix1(3, 3, fillMatrix1);
        S21Matrix matrix2(3, 3, fillMatrix2);
        S21Matrix matrix3(3, 3, result);
        S21Matrix res = matrix1 - matrix2;
        ASSERT_TRUE(matrix3 == res);
    } catch (std::exception & ex) {
        std::cout << ex.what();
    }
}

TEST(eq, T1) {
    try {
        double fillMatrix1[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        double fillMatrix2[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        double result[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        S21Matrix matrix1(3, 3, fillMatrix1);
        S21Matrix matrix2(3, 3, fillMatrix2);
        S21Matrix res(3, 3, result);
        ASSERT_TRUE(matrix2.eq_matrix(res));
    } catch (std::exception & ex) {
        std::cout << ex.what();
    }
}

TEST(eqFalse, T1) {
    try {
        double fillMatrix1[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        double fillMatrix2[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        double result[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        S21Matrix matrix1(3, 3, fillMatrix1);
        S21Matrix matrix2(3, 2, fillMatrix2);
        S21Matrix res(3, 3, result);
        ASSERT_TRUE(matrix2.eq_matrix(res));
    } catch (std::exception & ex) {
        std::cout << ex.what();
    }
}

TEST(mulMatrix, T1) {
    try {
        double fillMatrix1[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
        double fillMatrix2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        double result[9] = {24, 30, 36, 24, 30, 36, 24, 30, 36};
        S21Matrix matrix1(3, 3, fillMatrix1);
        S21Matrix matrix2(3, 3, fillMatrix2);
        S21Matrix res(3, 3, result);
        matrix1.mul_matrix(matrix2);
        ASSERT_TRUE(matrix1 == res);
    } catch (std::exception & ex) {
        std::cout << ex.what();
    }
}


TEST(mulNumber, T1) {
    try {
        double fillMatrix1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        double result[9] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
        S21Matrix matrix1(3, 3, fillMatrix1);
        S21Matrix res(3, 3, result);
        matrix1.mul_number(5);
        ASSERT_TRUE(res == matrix1);
    } catch (std::exception & ex) {
        std::cout << ex.what();
    }
}

TEST(transpose, T1) {
    try {
        S21Matrix matrix1(3, 4);
        S21Matrix matrix2(matrix1.transpose());
        S21Matrix res(4, 3);
        ASSERT_TRUE(res == matrix2);
    } catch (std::exception & ex) {
        std::cout << ex.what();
    }
}

TEST(inverse, T1) {
    double fillMatrix1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    double fillMatrix2[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
    S21Matrix matrix1(3, 3, fillMatrix1);
    S21Matrix matrix2(3, 3, fillMatrix2);
    S21Matrix res = matrix1.inverse_matrix();
    bool check = res.eq_matrix(matrix2);
    EXPECT_EQ(check, true);
}

TEST(determinantOne, T1) {
    S21Matrix matrix1(1, 1);
    ASSERT_EQ(matrix1.determinant(), 0);
}

TEST(getters, T1) {
    S21Matrix matrix1(3, 3);
    ASSERT_EQ(matrix1.getRow(), 3);
    ASSERT_EQ(matrix1.getCol(), 3);
}

TEST(setters, T1) {
    double fillMatrix1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    S21Matrix matrix1(3, 3, fillMatrix1);
    matrix1.setCol(4);
    matrix1.setRow(4);
    ASSERT_EQ(matrix1.getCol(), 4);
    ASSERT_EQ(matrix1.getRow(), 4);
}

TEST(operatorMultEq, T1) {
    double fillMatrix1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    double fillMatrix2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double fillMatrix3[9] = {71, 85, 99, 46, 59, 72, -24, -24, -24};
    S21Matrix matrix1(3, 3, fillMatrix1);
    S21Matrix matrix2(3, 3, fillMatrix2);
    S21Matrix res(3, 3, fillMatrix3);
    matrix1 *= matrix2;
    bool ch = matrix1.eq_matrix(res);
    EXPECT_EQ(ch, true);
}

TEST(operatorMinusEq, T1) {
    double fillMatrix1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    double fillMatrix2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double fillMatrix3[9] = {1, 3, 4, 2, -2, -2, -2, -10, -12};
    S21Matrix matrix1(3, 3, fillMatrix1);
    S21Matrix matrix2(3, 3, fillMatrix2);
    S21Matrix res(3, 3, fillMatrix3);
    matrix1 -= matrix2;
    bool ch = matrix1.eq_matrix(res);
    EXPECT_EQ(ch, true);
}

TEST(operatorPlusEq, T1) {
    double fillMatrix1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    double fillMatrix2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double fillMatrix3[9] = {3, 7, 10, 10, 8, 10, 12, 6, 6};
    S21Matrix matrix1(3, 3, fillMatrix1);
    S21Matrix matrix2(3, 3, fillMatrix2);
    S21Matrix res(3, 3, fillMatrix3);
    matrix1 += matrix2;
    bool ch = matrix1.eq_matrix(res);
    EXPECT_EQ(ch, true);
}

TEST(operatorMultMatrix, T1) {
    double fillMatrix1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    double fillMatrix2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double fillMatrix3[9] = {71, 85, 99, 46, 59, 72, -24, -24, -24};
    S21Matrix matrix1(3, 3, fillMatrix1);
    S21Matrix matrix2(3, 3, fillMatrix2);
    S21Matrix res1(3, 3);
    S21Matrix res(3, 3, fillMatrix3);
    res1 = matrix1 * matrix2;
    bool ch = res1.eq_matrix(res);
    EXPECT_EQ(ch, true);
}

TEST(operatorMultNumber, T1) {
    double fillMatrix1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    double fillMatrix3[9] = {10, 25, 35, 30, 15, 20, 25, -10, -15};
    S21Matrix matrix1(3, 3, fillMatrix1);
    S21Matrix matrix2(3, 3);
    S21Matrix res(3, 3, fillMatrix3);
    matrix2 = matrix1 * 5;
    bool ch = matrix2.eq_matrix(res);
    EXPECT_EQ(ch, true);
}

TEST(operatorMultNumberAndEq, T1) {
    double fillMatrix1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
    double fillMatrix3[9] = {10, 25, 35, 30, 15, 20, 25, -10, -15};
    S21Matrix matrix1(3, 3, fillMatrix1);
    S21Matrix matrix2(3, 3);
    S21Matrix res(3, 3, fillMatrix3);
    matrix2 = matrix1 *= 5;
    bool ch = matrix2.eq_matrix(res);
    EXPECT_EQ(ch, true);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
