cmake_minimum_required(VERSION 3.5.0)
project(task5 VERSION 0.1.0 LANGUAGES C CXX)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address") 
add_executable(task5 input.cpp main.cpp solve.cpp)

