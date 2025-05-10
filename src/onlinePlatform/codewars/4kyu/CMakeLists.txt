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
