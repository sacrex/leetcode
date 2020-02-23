cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(LongestSubstringWithoutRepeatingCharacters)
add_subdirectory(7ReverseInteger)
add_subdirectory(9PalindromeNumber)