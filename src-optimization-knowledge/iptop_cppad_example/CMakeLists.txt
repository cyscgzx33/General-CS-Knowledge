#project(ipopt_cppad_tutorial_example)
#project(cppad_index_sort_example)
project(ipopt_example)

cmake_minimum_required (VERSION 3.5)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

#set(sources src/ipopt_solve_get_started.cpp)
#set(sources src/cppad_index_sort.cpp)
set(sources src/ipopt_without_cppad_example.cpp)

#include_directories(/usr/local/include)
include_directories(/usr/local/include/coin)
link_directories(/usr/local/lib)

#add_executable(ipopt_cppad_tutorial_example ${sources})
#add_executable(cppad_index_sort_example ${sources})
add_executable(ipopt_example ${sources})

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#target_link_libraries(ipopt_cppad_tutorial_example ipopt python2.7)
#target_link_libraries(cppad_index_sort_example ipopt python2.7)
target_link_libraries(ipopt_example ipopt python2.7)
else()
#target_link_libraries(ipopt_cppad_tutorial_example ipopt python)
#target_link_libraries(cppad_index_sort_example ipopt python)
target_link_libraries(ipopt_example ipopt python)
endif()
