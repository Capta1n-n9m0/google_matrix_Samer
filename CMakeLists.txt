cmake_minimum_required(VERSION 3.22)
project(google_matrix_Samer C)

set(CMAKE_C_STANDARD 11)

add_executable(wholelinks_to_selectedlinks_index_modified
        wholelinks_to_selectedlinks_index_modified.c)
add_executable(merge merge.c)
add_executable(pagerank pagerank.c)
add_executable(pr_test pr_test.c)
add_executable(test_proj_Gpr test_proj_Gpr.c)
add_executable(test_proj_Gqr test_proj_Gqr.c)
add_executable(my_test my_test.c)