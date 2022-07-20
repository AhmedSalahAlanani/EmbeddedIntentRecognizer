cmake_minimum_required(VERSION 3.16)

# set project name
set(PROJECT_NAME "Embedded_Intent_Recognizer" VERSION 1.0.0)

project(${PROJECT_NAME})

# set target compilation options
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)
set (CMAKE_CXX_EXTENSIONS FALSE)

# add subdirectory for the source files
add_subdirectory(src)

# add subdirectory for the source files
add_subdirectory(unit-tests)

# add subdirectory for Doxygen generation
add_subdirectory(docs)