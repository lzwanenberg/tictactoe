cmake_minimum_required (VERSION 3.8)

include(FetchContent)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TicTacToe")

add_executable (TicTacToe "src/TicTacToe.c")

# TEST SUITE
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TicTacToe PROPERTY CXX_STANDARD 20)
endif()

FetchContent_Declare(unity
                     GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
                     GIT_TAG        v2.5.2)

FetchContent_MakeAvailable(unity)

# Create a separate target for running tests
# Find all test source files in the top-level src directory
file(GLOB TEST_SOURCE_FILES_TOPLEVEL "src/*.test.c")

# Find all test source files recursively within the src directory and its subdirectories
file(GLOB_RECURSE TEST_SOURCE_FILES_SUBDIRS "src/**/*.test.c")

# Concatenate the lists
set(TEST_SOURCE_FILES ${TEST_SOURCE_FILES_TOPLEVEL} ${TEST_SOURCE_FILES_SUBDIRS})

# Create executables for each test source file
foreach(TEST_SOURCE_FILE IN LISTS TEST_SOURCE_FILES)
    get_filename_component(TEST_EXECUTABLE_NAME ${TEST_SOURCE_FILE} NAME_WE)
    add_executable(${TEST_EXECUTABLE_NAME}.test ${TEST_SOURCE_FILE})
    target_link_libraries(${TEST_EXECUTABLE_NAME}.test unity)
endforeach()