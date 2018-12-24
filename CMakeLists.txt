# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.5.1)
# Project's name
project(TrafficSign)
# Set the output folder where your program will be created
#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

find_package(OpenCV REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

include(CMakeToolsHelpers OPTIONAL)
include_directories(include ${PROJECT_SOURCE_DIR} ${OpenCV_INCLUDE_DIRS})

#sources
file(GLOB SOURCES "src/*.cpp")

add_library(tsr ${SOURCES})
target_link_libraries(tsr ${OpenCV_LIBS})

add_executable(traffic_sign ${SOURCES})
#add_executable(test1 test1.cpp)
target_link_libraries(traffic_sign tsr ${OpenCV_LIBS})
#target_link_libraries(test1 ${OpenCV_LIBS})
# The following folder will be included
#include_directories("${PROJECT_SOURCE_DIR}")
