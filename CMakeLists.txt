cmake_minimum_required(VERSION 3.20)
project(calc_math LANGUAGES CXX)

add_library(calc_math INTERFACE)

target_include_directories(calc_math INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
