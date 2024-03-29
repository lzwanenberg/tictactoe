﻿cmake_minimum_required (VERSION 3.8)
project(TicTacToe C)

set(MODULES
    src/support/Byte/Byte.c
    src/models/Board/Board.c
    src/view/GameView/GameView.c
    src/view/BoardView/BoardView.c
    src/services/InputBuffer/InputBuffer.c
    src/services/MoveInputParser/MoveInputParser.c
    src/services/GameStatusAnalyzer/GameStatusAnalyzer.c
    src/services/MoveValidator/MoveValidator.c
    src/services/AppService/AppService.c
)

# Add an executable target
add_executable(TicTacToe ${MODULES} "src/main.c")

# Optionally, set output directory
set_target_properties(TicTacToe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# TEST SUITE
# -----------------------------------------------------------------------------
include(FetchContent)
message(STATUS "Value of CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TicTacToe PROPERTY CXX_STANDARD 20)
endif()

FetchContent_Declare(unity
                     GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
                     GIT_TAG        v2.5.2)

FetchContent_MakeAvailable(unity)

# Find all test source files
file(GLOB_RECURSE TEST_SOURCE_FILES "src/*.test.c")

set(TEST_MODULES
    stubs/Board/Board.c
)

# Create executables for each test source file
foreach(TEST_SOURCE_FILE IN LISTS TEST_SOURCE_FILES)
    get_filename_component(TEST_EXECUTABLE_NAME ${TEST_SOURCE_FILE} NAME_WE)
    get_filename_component(TEST_SOURCE_DIR ${TEST_SOURCE_FILE} DIRECTORY)

    # Generate relative path for output directory
    file(RELATIVE_PATH TEST_RELATIVE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src" "${TEST_SOURCE_DIR}")

    string(REPLACE "/" "_" NAMESPACE_ID "${TEST_RELATIVE_SOURCE_DIR}")
    set(EXECUTABLE_ID "${NAMESPACE_ID}__${TEST_EXECUTABLE_NAME}")

    # Generate output directory
    set(TEST_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/Tests/${TEST_RELATIVE_SOURCE_DIR}")

    add_executable(${EXECUTABLE_ID} ${MODULES} ${TEST_MODULES} ${TEST_SOURCE_FILE})
    target_link_libraries(${EXECUTABLE_ID} unity)
    set_target_properties(${EXECUTABLE_ID} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${TEST_OUTPUT_DIR}"
        OUTPUT_NAME "${TEST_EXECUTABLE_NAME}.test"
    )
    target_compile_definitions(${EXECUTABLE_ID} PRIVATE UNIT_TESTING)
endforeach()
