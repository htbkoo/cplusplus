cmake_minimum_required(VERSION 3.25)
project(cplusplus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

###
# START - For setting up Google Test
# Reference: https://google.github.io/googletest/quickstart-cmake.html#set-up-a-project
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Reference: https://google.github.io/googletest/quickstart-cmake.html#create-and-run-a-binary
enable_testing()

add_executable(
        hello_test
        hello_test.cc
)
target_link_libraries(
        hello_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

# END  - For setting up Google Test
###

add_executable(cplusplus main.cpp)
add_subdirectory(src)
