cmake_minimum_required(VERSION 3.16)

# set target name
set(TARGET_NAME "intent-recognizer")

# set executable source files
set(EIR_SRCS
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

# set include directory
set(EIR_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src)

# add executable for the project
add_executable(${TARGET_NAME}
    ${EIR_SRCS}
)

# add target include directory
target_include_directories(${TARGET_NAME} PRIVATE
    ${EIR_INCLUDE_DIR}
)