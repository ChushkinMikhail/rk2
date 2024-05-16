



cmake_minimum_required(VERSION 3.10)

# Название проекта
project(P1)

add_executable(P1 builder.cpp)

enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(check1 tests/test1.cpp)
target_link_libraries(check1 ${GTEST_LIBRARIES} pthread)

add_executable(check2 tests/test2.cpp)
target_link_libraries(check2 ${GTEST_LIBRARIES} pthread)

add_executable(check3 tests/test3.cpp)
target_link_libraries(check3 ${GTEST_LIBRARIES} pthread)

add_test(NAME check1 COMMAND check1)
add_test(NAME check2 COMMAND check2)
add_test(NAME check3 COMMAND check3)
