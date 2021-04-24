cmake_minimum_required(VERSION 3.17)
project(OOP_4_1_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(OOP_4_1_1 main.cpp Base.cpp Application.cpp Future.cpp)