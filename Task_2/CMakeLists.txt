cmake_minimum_required(VERSION 3.5.0)
project(task2 VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread") 
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address") 
add_executable(task2 binary.cpp input.cpp main.cpp reverse.cpp sumdop.cpp)

