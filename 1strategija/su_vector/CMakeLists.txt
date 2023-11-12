cmake_minimum_required(VERSION 3.10)
project(su_vekt)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(su_vekt ${SOURCES})

