cmake_minimum_required(VERSION 3.24)
project(abseil_proj1)

set(CMAKE_CXX_STANDARD 17)

add_executable(abseil_proj1 main.cpp)

find_package(absl CONFIG REQUIRED)

target_include_directories(abseil_proj1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(abseil_proj1 absl::strings)