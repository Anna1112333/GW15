cmake_minimum_required(VERSION 3.10)
project(04)
add_executable(task01.cpp task01.cpp tests.cpp)
add_subdirectory("C:\\Dock\\Cath2\\Catch2" Catch2-build)
#target_link_libraries(test PRIVATE Catch2::Catch2)

find_package(Catch2 3 REQUIRED)
 #These tests can use the Catch2-provided main

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)