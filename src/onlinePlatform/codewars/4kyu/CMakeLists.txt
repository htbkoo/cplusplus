project(5kyu)

add_executable(
        matrix_determinant_google_test
        matrix_determinant_google_test.cc
)
target_link_libraries(
        matrix_determinant_google_test
        GTest::gtest_main
)
gtest_discover_tests(matrix_determinant_google_test)

add_executable(
        counting_change_combinations_google_test
        counting_change_combinations_google_test.cc
)
target_link_libraries(
        counting_change_combinations_google_test
        GTest::gtest_main
)
gtest_discover_tests(counting_change_combinations_google_test)
