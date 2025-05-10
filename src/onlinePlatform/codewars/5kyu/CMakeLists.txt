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
