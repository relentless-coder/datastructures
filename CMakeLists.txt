cmake_minimum_required(VERSION 3.10)
project(MyCProject C)

# Make it easier for the compiler to find headers
include_directories(${PROJECT_SOURCE_DIR}/node)
include_directories(${PROJECT_SOURCE_DIR}/linked-list)

# Create executable for node unit tests
add_executable(node_test.out
    node/node_test.c
    node/node.c
    .lib/munit/munit.c
)

enable_testing()
add_test(NAME NodeTest COMMAND node_test.out)
