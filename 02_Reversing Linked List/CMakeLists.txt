cmake_minimum_required(VERSION 3.0.0)
project(reverse_linklist VERSION 0.1.0)

include(CTest)
enable_testing()

#add_executable(reverse_linklist reverse_linklist.cpp v2.cpp)
add_executable(reverse_linklist reverse_linklist.cpp)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
