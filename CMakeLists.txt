# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.2.1)

# Project's name

project(TrafficSign)
# Set the output folder where your program will be created
#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)
include_directories(include ${PROJECT_SOURCE_DIR} ${OpenCV_INCLUDE_DIRS})
add_library(tsr traffic_sign.cpp)
target_link_libraries(tsr ${OpenCV_LIBS})
add_executable(traffic_sign main.cpp) #lane_detect.cpp
add_executable(test1 test1.cpp)
target_link_libraries(traffic_sign tsr ${OpenCV_LIBS})
target_link_libraries(test1 ${OpenCV_LIBS})
# The following folder will be included
#include_directories("${PROJECT_SOURCE_DIR}")
