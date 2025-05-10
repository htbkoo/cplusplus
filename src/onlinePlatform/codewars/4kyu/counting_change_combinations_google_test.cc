#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "counting_change_combinations.cc"

TEST(CountingChangeCombinations, countChange_test) {
    EXPECT_EQ(countChange(4, {1,2}), 3);

    EXPECT_EQ(countChange(10, {5,2,3}), 4);
}
