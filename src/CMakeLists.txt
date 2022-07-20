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

# create configuration file for embedded intent recognizer
configure_file(
    ${Embedded_Intent_Recognizer_SOURCE_DIR}/config/intent-recognizer.cfg.in
    ${Embedded_Intent_Recognizer_BINARY_DIR}/config/intent-recognizer.cfg
    @ONLY
    NEWLINE_STYLE UNIX
)

# set embedded intent recognizer configuration file path
set(CFG_FILE "intent-recognizer.cfg")
add_definitions("-DCONFIG_FILE_PATH=\"${Embedded_Intent_Recognizer_BINARY_DIR}/config/${CFG_FILE}\"")

# add executable for the project
add_executable(${TARGET_NAME}
    ${EIR_SRCS}
)

# add target include directory
target_include_directories(${TARGET_NAME} PRIVATE
    ${EIR_INCLUDE_DIR}
)