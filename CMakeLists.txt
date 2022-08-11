cmake_minimum_required(VERSION 3.0.0)
project(advent-of-code2021 VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

file(GLOB source_files *.cpp *.h)
add_executable(advent-of-code2021 ${source_files})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
