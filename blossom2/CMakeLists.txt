cmake_minimum_required(VERSION 3.12)
project(blossom2)

set(CMAKE_CXX_STANDARD 14)

add_executable(main1 main.cpp hopcroft.cpp)
add_executable(blossom blossom.cpp)
add_executable(hopcroft2 hopcroft2.cpp)
