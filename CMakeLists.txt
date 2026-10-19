# CMakeLists.txt
cmake_minimum_required(VERSION 3.14)
project(UnitTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(run_tests
    test_queue.cpp
    test_heap.cpp
    test_binary_tree.cpp
)

target_link_libraries(run_tests GTest::gtest GTest::gtest_main)

gtest_discover_tests(run_tests)