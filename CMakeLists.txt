cmake_minimum_required(VERSION 3.16)

# set project name
set(PROJECT_NAME "Embedded_Intent_Recognizer" VERSION 1.0.0)

project(${PROJECT_NAME})

# set target compilation options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

# add subdirectory for the source files
add_subdirectory(src)

# option for building unit tests
option(BUILD_TESTS "Option to turn On/OFF building tests" ON)

if(BUILD_TESTS)
    message(STATUS "Building Tests: Enabled")

    # add subdirectory for the source files
    add_subdirectory(tests)
else()
    message(STATUS "Building Tests: Disabled")
endif()

# option for generating Doxygen
option(BUILD_DOCS "Option to turn On/OFF generating Doxygen" ON)

if(BUILD_DOCS)
    message(STATUS "Generating Doxygen: Enabled")

    # add subdirectory for Doxygen generation
    add_subdirectory(docs)
else()
    message(STATUS "Generating Doxygen: Disabled")
endif()