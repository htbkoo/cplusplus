#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "square_matrix_multiplication.cc"

void square_matrix_assert_eq(std::vector<std::vector<int>> &actual,
                             std::vector<std::vector<int>> &expected, int n) {
  // Assert that the two matrices are equal
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // Assert::That(actual[i][j], Equals(expected[i][j]));
      EXPECT_EQ(actual[i][j], expected[i][j]);
    }
  }
}

TEST(SquareMatrixMultiplication, should_work_for_the_example_provided_in_the_description) {
  std::vector<std::vector<int>> a(2, std::vector<int>(2)),
      b(2, std::vector<int>(2)), expected(2, std::vector<int>(2)), actual;
  /*
        1  2
    A =
        3  2
  */
  // Assuming Row->Col, means storage is row-wise
  a[0][0] = 1;
  a[0][1] = 2;
  a[1][0] = 3;
  a[1][1] = 2;
  /*
        3  2
    B =
        1  1
  */
  b[0][0] = 3;
  b[0][1] = 2;
  b[1][0] = 1;
  b[1][1] = 1;
  /*
              5    4
    A × B  =
              11   8
  */
  expected[0][0] = 5;
  expected[0][1] = 4;
  expected[1][0] = 11;
  expected[1][1] = 8;

  actual = matrix_multiplication(a, b, 2);
  square_matrix_assert_eq(actual, expected, 2);
}