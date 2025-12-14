# CMaken minimiversio
cmake_minimum_required(VERSION 3.20)

# Projektin nimi ja kieli
project(enigma_demo LANGUAGES CXX)

# Moduuli, jolla haetaan kirjastoja
include(FetchContent)

# Raylibin m‰‰ritykset
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib
    GIT_TAG 5.5
)

# Lataa raylib (jos ei jo ole)
FetchContent_MakeAvailable(raylib)

# Luo suoritettava tiedosto (exe)
add_executable(enigma_demo
    src/main.cpp
 )

# Helpompi t‰‰lt‰ lis‰t‰ buildiin
add_library(enigma_libs STATIC
    src/dummy.cpp
)

# Linkit‰ raylib
target_link_libraries(enigma_demo PRIVATE raylib enigma_libs)

# C++ Standardi projektiin
set_target_properties(enigma_demo PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

# Catch2 m‰‰ritykset
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.11.0
)

# Lataa catch2 (jos ei ole jo)
FetchContent_MakeAvailable(catch2)

add_executable(tests_enigma
    tests/test_dummy.cpp
)

# Linkit‰ Catch2
target_link_libraries(tests_enigma PRIVATE Catch2::Catch2WithMain enigma_libs)

# C++ Stantardi testeill‰
set_target_properties(tests_enigma PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
)

include(CTest)
include(Catch)
catch_discover_tests(tests_enigma)