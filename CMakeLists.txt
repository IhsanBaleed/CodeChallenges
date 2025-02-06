cmake_minimum_required(VERSION 3.0)

project(Challenge)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Strings)
add_subdirectory(HackerRank)
add_subdirectory(Arrays)
add_subdirectory(CodeWars)
add_subdirectory(Codility)
add_subdirectory(LeetCode)


add_executable(Challenge main.cpp)

target_link_libraries(Challenge PUBLIC HackerRank
                                       Strings
                                       Arrays
                                       CodeWars
                                       Codility
                                       LeetCode)

