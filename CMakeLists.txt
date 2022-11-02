cmake_minimum_required(VERSION 3.16)
project(rendering)

find_package(OpenCV REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)
set(COMPILE_OPTIONS -Wall)

add_executable(render
        src/main.cpp
        include/color.h
        include/geometry.h
        include/geometry.tpp
        include/objects.h
        include/viewer.h
        src/color.cpp
        src/geometry.cpp
        src/objects.cpp
        src/render.cpp
        src/viewer.cpp)
target_link_libraries(render ${COMPILE_OPTIONS} ${OpenCV_LIBS})

# add_executable(viewer
#         include/viewer.h
#         include/color.h
#         src/viewer.cpp
#         src/color.cpp)
# target_link_libraries(viewer ${COMPILE_OPTIONS} ${OpenCV_LIBS})

