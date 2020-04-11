cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory("Longest Substring Without Repeating Characters")
add_subdirectory("Reverse Integer")
add_subdirectory("Palindrome Number")
add_subdirectory("Dynamic Programming")
add_subdirectory("Depth-first Search")