cmake_minimum_required(VERSION 3.16)

# set target name
set(TARGET_NAME "intent-recognizer-unit-tests")

include(FetchContent)
FetchContent_Declare(GTest
    QUIET
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG 58d77fa8070e8cec2dc1ed015d66b454c8d78850 # release-1.12.1
)

# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(GTest)

# set embedded intent recognizer configuration file path
set(CFG_FILE "intent-recognizer.cfg")
add_definitions("-DCONFIG_FILE_PATH=\"${Embedded_Intent_Recognizer_BINARY_DIR}/config/${CFG_FILE}\"")

# set embedded intent recognizer dataset files' path
set(DATA_SET_1 "data-set1")
set(DATA_SET_2 "data-set2")
set(DATA_SET_3 "data-set3")
set(DATA_SET_4 "data-set4")
set(DATA_SET_5 "data-set5")

add_definitions(
    "-DENGLISH_DATA_SET1_FILE_PATH=\"${CMAKE_SOURCE_DIR}/data/english-dataSet/${DATA_SET_1}\""
    "-DENGLISH_DATA_SET2_FILE_PATH=\"${CMAKE_SOURCE_DIR}/data/english-dataSet/${DATA_SET_2}\""
    "-DENGLISH_DATA_SET3_FILE_PATH=\"${CMAKE_SOURCE_DIR}/data/english-dataSet/${DATA_SET_3}\""
    "-DENGLISH_DATA_SET4_FILE_PATH=\"${CMAKE_SOURCE_DIR}/data/english-dataSet/${DATA_SET_4}\""
    "-DENGLISH_DATA_SET5_FILE_PATH=\"${CMAKE_SOURCE_DIR}/data/english-dataSet/${DATA_SET_5}\""
)

# define several configuration files for unit tests
set(TEST_INVALID_FORMAT1_CFG_FILE "invalid-format1.cfg")
set(TEST_INVALID_FORMAT2_CFG_FILE "invalid-format2.cfg")
set(TEST_INVALID_FORMAT3_CFG_FILE "invalid-format3.cfg")
set(TEST_INVALID_FORMAT4_CFG_FILE "invalid-format4.cfg")
set(TEST_VALID_FORMAT1_CFG_FILE "valid-format1.cfg")
set(TEST_VALID_FORMAT2_CFG_FILE "valid-format2.cfg")
set(TEST_VALID_FORMAT3_CFG_FILE "valid-format3.cfg")
set(TEST_VALID_FORMAT4_CFG_FILE "valid-format4.cfg")

add_definitions(
    "-DTEST_INVALID_FORMAT1_FILE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/test-artifacts/${TEST_INVALID_FORMAT1_CFG_FILE}\""
    "-DTEST_INVALID_FORMAT2_FILE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/test-artifacts/${TEST_INVALID_FORMAT2_CFG_FILE}\""
    "-DTEST_INVALID_FORMAT3_FILE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/test-artifacts/${TEST_INVALID_FORMAT3_CFG_FILE}\""
    "-DTEST_INVALID_FORMAT4_FILE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/test-artifacts/${TEST_INVALID_FORMAT4_CFG_FILE}\""
    "-DTEST_VALID_FORMAT1_FILE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/test-artifacts/${TEST_VALID_FORMAT1_CFG_FILE}\""
    "-DTEST_VALID_FORMAT2_FILE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/test-artifacts/${TEST_VALID_FORMAT2_CFG_FILE}\""
    "-DTEST_VALID_FORMAT3_FILE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/test-artifacts/${TEST_VALID_FORMAT3_CFG_FILE}\""
    "-DTEST_VALID_FORMAT4_FILE_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}/test-artifacts/${TEST_VALID_FORMAT4_CFG_FILE}\""
)

# set executable source files
set(EIR_TEST_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/EmbeddedIntentRecognizerTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TextProcessorTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ConfigManagerTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InputStrategiesTest.cpp

    ${CMAKE_SOURCE_DIR}/src/EmbeddedIntentRecognizer.cpp
    ${CMAKE_SOURCE_DIR}/src/ConfigManager.cpp
    ${CMAKE_SOURCE_DIR}/src/InputStrategyContext.cpp
    ${CMAKE_SOURCE_DIR}/src/TextProcessor.cpp

    ${CMAKE_SOURCE_DIR}/src/concrete-input-strategies/CliInput.cpp
    ${CMAKE_SOURCE_DIR}/src/concrete-input-strategies/TouchScreenInput.cpp
    ${CMAKE_SOURCE_DIR}/src/concrete-input-strategies/VoiceInput.cpp

    ${CMAKE_SOURCE_DIR}/src/concrete-input-language-strategies/CliEnglishInput.cpp

    ${CMAKE_SOURCE_DIR}/src/intent-recognition-models/EnglishLanguageModel.cpp

    ${CMAKE_SOURCE_DIR}/src/output-devices/CliOutput.cpp
    ${CMAKE_SOURCE_DIR}/src/output-devices/TouchScreenOutput.cpp
    ${CMAKE_SOURCE_DIR}/src/output-devices/VoiceOutput.cpp

    ${CMAKE_SOURCE_DIR}/src/concrete-output-language-strategies/CliEnglishOutput.cpp
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