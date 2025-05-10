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

add_executable(
        coding_with_squared_strings
        coding_with_squared_strings_google_test.cc
)
target_link_libraries(
        coding_with_squared_strings
        GTest::gtest_main
)
gtest_discover_tests(coding_with_squared_strings)
