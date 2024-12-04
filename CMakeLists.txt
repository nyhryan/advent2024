CMAKE_MINIMUM_REQUIRED(VERSION 3.30)

project("Advent of code 2024")

add_executable(main
    # src/day1/main.cpp
    # src/day2/main.cpp
    src/day3/main.cpp
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
# target_compile_options(main PRIVATE -std=c++20)
target_compile_options(main PRIVATE /std:c++20)