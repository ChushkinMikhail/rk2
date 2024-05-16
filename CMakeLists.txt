



cmake_minimum_required(VERSION 3.10)

# Название проекта
project(P1)

add_executable(P1 builder.cpp)

# Добавить тесты
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(check tests/test.cpp)
target_link_libraries(check ${GTEST_LIBRARIES} pthread)

add_test(NAME check COMMAND check)
