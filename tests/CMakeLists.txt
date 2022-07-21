cmake_minimum_required(VERSION 3.16)

# set target name
set(TARGET_NAME "intent-recognizer-unit-tests")

include(FetchContent)
FetchContent_Declare(GTest
    QUIET
    URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)

# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(GTest)

# set embedded intent recognizer configuration file path
set(CFG_FILE "intent-recognizer.cfg")
add_definitions("-DCONFIG_FILE_PATH=\"${Embedded_Intent_Recognizer_BINARY_DIR}/config/${CFG_FILE}\"")

# set executable source files
set(EIR_TEST_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbeddedIntentRecognizerTest.cpp

    ${CMAKE_SOURCE_DIR}/src/EmbeddedIntentRecognizer.cpp
    ${CMAKE_SOURCE_DIR}/src/ConfigManager.cpp
    ${CMAKE_SOURCE_DIR}/src/InputStrategyContext.cpp
    ${CMAKE_SOURCE_DIR}/src/TextProcessor.cpp

    ${CMAKE_SOURCE_DIR}/src/concrete-input-strategies/CliInput.cpp
    ${CMAKE_SOURCE_DIR}/src/concrete-input-strategies/TouchScreenInput.cpp
    ${CMAKE_SOURCE_DIR}/src/concrete-input-strategies/VoiceInput.cpp

    ${CMAKE_SOURCE_DIR}/src/concrete-input-language-strategies/CliEnglishInput.cpp

    ${CMAKE_SOURCE_DIR}/src/output-devices/CliOutput.cpp
    ${CMAKE_SOURCE_DIR}/src/output-devices/TouchScreenOutput.cpp
    ${CMAKE_SOURCE_DIR}/src/output-devices/VoiceOutput.cpp
)

# set include directory
set(EIR_TEST_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src)

# add executable for the project
add_executable(${TARGET_NAME}
    ${EIR_TEST_SRCS}
)

# add target include directory
target_include_directories(${TARGET_NAME} PRIVATE
    ${EIR_TEST_INCLUDE_DIR}
)

# add target link libraries
target_link_libraries(${TARGET_NAME} PRIVATE
    gtest
    gmock
)