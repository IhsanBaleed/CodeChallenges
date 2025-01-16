cmake_minimum_required(VERSION 3.0)

project(Challenge)

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

