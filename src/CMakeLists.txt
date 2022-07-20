cmake_minimum_required(VERSION 3.16)

# set target name
set(TARGET_NAME "intent-recognizer")

# set executable source files
set(EIR_SRCS
    ${CMAKE_SOURCE_DIR}/src/main.cpp

    ${CMAKE_SOURCE_DIR}/src/EmbeddedIntentRecognizer.cpp
    ${CMAKE_SOURCE_DIR}/src/ConfigManager.cpp
    ${CMAKE_SOURCE_DIR}/src/InputStrategyContext.cpp
    ${CMAKE_SOURCE_DIR}/src/TextProcessor.cpp

    ${CMAKE_SOURCE_DIR}/src/concrete-input-strategies/CliInput.cpp
    ${CMAKE_SOURCE_DIR}/src/concrete-input-strategies/TouchScreenInput.cpp
    ${CMAKE_SOURCE_DIR}/src/concrete-input-strategies/VoiceInput.cpp

    ${CMAKE_SOURCE_DIR}/src/output-devices/CliOutput.cpp
    ${CMAKE_SOURCE_DIR}/src/output-devices/TouchScreenOutput.cpp
    ${CMAKE_SOURCE_DIR}/src/output-devices/VoiceOutput.cpp
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