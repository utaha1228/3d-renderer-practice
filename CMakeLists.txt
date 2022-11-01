cmake_minimum_required(VERSION 3.16)
project(rendering)

include_directories(include)

set(CMAKE_CXX_STANDARD 14)
set(COMPILE_OPTIONS -Wall)

add_executable(render
        src/main.cpp
        include/color.h
        include/geometry.h
        include/geometry.tpp
        include/objects.h
        src/color.cpp
        src/geometry.cpp
        src/objects.cpp
        src/render.cpp)
target_link_libraries(render ${COMPILE_OPTIONS})

