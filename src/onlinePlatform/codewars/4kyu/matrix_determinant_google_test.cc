#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "matrix_determinant.cc"

TEST(MatrixDeterminant, should_work_for_a_few_simple_square_matrices) {
    EXPECT_EQ(determinant(vector<vector<long long> >{
                  vector<long long>{1}
                  }), 1);

    EXPECT_EQ(determinant(vector<vector<long long> >{
                  vector<long long>{1, 3},
                  vector<long long>{2, 5}
                  }), -1);

    EXPECT_EQ(determinant(vector<vector<long long> >{
                  vector<long long>{2, 5, 3},
                  vector<long long>{1, -2, -1},
                  vector<long long>{1, 3, 4}
                  }), -20);
}
