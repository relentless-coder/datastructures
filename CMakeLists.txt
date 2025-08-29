set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
cmake_minimum_required(VERSION 3.10)
project(Datastructures C)

# Make it easier for the compiler to find headers
include_directories(${PROJECT_SOURCE_DIR}/node)
include_directories(${PROJECT_SOURCE_DIR}/linked-list)
include_directories(${PROJECT_SOURCE_DIR}/trees)
include_directories(${PROJECT_SOURCE_DIR}/trees/binary_tree)

# Create executable for node unit tests
add_executable(node_test.out node/node_test.c node/node.c .lib/munit/munit.c)

add_executable(binary_tree_test.out
trees/binary_tree/binary_tree_test.c
trees/binary_tree/binary_tree.c
node/node.c
.lib/munit/munit.c)

enable_testing()
add_test(NAME NodeTest COMMAND node_test.out)
add_test(NAME BinaryTreeTest COMMAND binary_tree_test.out)
