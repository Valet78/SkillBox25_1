cmake_minimum_required(VERSION 3.27)
project(SkillBox25_1)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
include_directories(src)

set(SOURCES src/main_25-1.cpp include/25.4-1.h)

add_executable(SkillBox25_1 ${SOURCES})
