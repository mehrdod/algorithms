cmake_minimum_required(VERSION 3.17)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(segtree_max_sub segment_tree_max_subarray.cpp segment_tree_max_sum.cpp)
add_executable(segtree_max_sum segment_tree_max_sum.cpp segment_tree_max_sum.cpp)