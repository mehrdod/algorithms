cmake_minimum_required(VERSION 3.17)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(segtree_max_sub "data structures/segment_tree_max_subarray.cpp" "data structures/segment_tree_max_sum.cpp")
add_executable(segtree_max_sum "data structures/segment_tree_max_sum.cpp" "data structures/segment_tree_max_sum.cpp")
add_executable(pair pair.cpp pair.cpp)
add_executable(cnk_by_modulo cnk_by_modulo.cpp cnk_by_modulo.cpp)