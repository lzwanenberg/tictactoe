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
add_executable(TicTacToe.test src/TicTacToe.test.c)
target_link_libraries(TicTacToe.test unity)
