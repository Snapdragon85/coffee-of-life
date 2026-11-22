cmake_minimum_required(VERSION 3.26)

project(COfLife C)

find_package(SDL3 REQUIRED)

add_executable(c-of-life main.c)

target_link_libraries(c-of-life PRIVATE SDL3::SDL3)