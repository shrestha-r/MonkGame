cmake_minimum_required(VERSION 3.10)
project(MonkGame)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(MonkGame main.cpp ${SOURCES})