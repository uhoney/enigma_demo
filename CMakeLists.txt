# ==============================================================================
# PROJECT CONFIGURATION
# ==============================================================================

# CMake required version
cmake_minimum_required(VERSION 3.20)

# Project name and language
project(enigma_demo LANGUAGES CXX)

# C++ standard for project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Show detailed build output
set(CMAKE_VERBOSE_MAKEFILE ON)

# ==============================================================================
# EXTERNAL DEPENDENCIES
# ==============================================================================

include(FetchContent)

# Raylib
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib
    GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

# Catch2 (unit test library)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.11.0
)
FetchContent_MakeAvailable(catch2)

# ==============================================================================
# LIBRARY TARGET
# ==============================================================================

# Enigma-library (shared between main build and tests)
add_library(enigma_libs STATIC
    "src/core/rotorbutton.cpp"
    "src/core/reflector.cpp"
    "src/core/key.cpp"
    "src/core/keyboard.cpp"
    "src/core/rotor.cpp"
    "src/core/lampboard.cpp"
    "src/core/lamp.cpp"
    "src/core/controller.cpp"
    "src/core/log.cpp"
    "src/ui/fonts.cpp"
    "src/ui/layout.cpp"
)

target_link_libraries(enigma_libs PUBLIC raylib)

set_target_properties(enigma_libs PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

# ==============================================================================
# MAIN EXECUTABLE
# ==============================================================================

# Main build
add_executable(enigma_demo
    src/main.cpp
)

target_link_libraries(enigma_demo PRIVATE enigma_libs)

set_target_properties(enigma_demo PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

# ==============================================================================
# TEST EXECUTABLE
# ==============================================================================

# Test build
add_executable(tests_enigma
    tests/test_controller.cpp    
    tests/test_dummy.cpp
    tests/test_keyboard.cpp
    #tests/test_lamp.cpp            # Can not really test visual components
    #tests/test_lampboard.cpp       # Can not really test visual components
    tests/test_reflector.cpp
    tests/test_rotor.cpp
    
)

target_link_libraries(tests_enigma PRIVATE 
    Catch2::Catch2WithMain 
    enigma_libs
)

set_target_properties(tests_enigma PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

# CTest-integration for Catch2
include(CTest)
include(Catch)
catch_discover_tests(tests_enigma)

# ==============================================================================
# ASSET COPY TASK
# ==============================================================================

add_custom_command(TARGET enigma_demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:enigma_demo>/assets
)