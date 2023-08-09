

cmake_minimum_required(VERSION 3.10)

project(main)

add_subdirectory(LinAlgebraLib)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC LinAlgebraLib)

target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}", "${PROJECT_SOURCE_DIR}/LinAlgebraLib")
