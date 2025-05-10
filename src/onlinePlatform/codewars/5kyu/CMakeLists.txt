project(5kyu)

add_executable(
        rot13GoogleTest
        rot13GoogleTest.cc
)
target_link_libraries(
        rot13GoogleTest
        GTest::gtest_main
)
gtest_discover_tests(rot13GoogleTest)

add_executable(
        square_matrix_multiplication_google_test
        square_matrix_multiplication_google_test.cc
)
target_link_libraries(
        square_matrix_multiplication_google_test
        GTest::gtest_main
)
gtest_discover_tests(square_matrix_multiplication_google_test)
