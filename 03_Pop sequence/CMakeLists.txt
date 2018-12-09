cmake_minimum_required(VERSION 3.0.0)
project(pop_sequence VERSION 0.1.0)

include(CTest)
enable_testing()
add_definitions(-std=c++11)
add_executable(pop_sequence main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
