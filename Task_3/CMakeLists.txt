cmake_minimum_required(VERSION 3.5.0)
project(task3 VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread") 
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address") 
add_executable(task3 SumSubstr.cpp input.cpp main.cpp)

