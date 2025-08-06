cmake_minimum_required(VERSION 3.16)
project(GoFPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

option(GOFPP_TEST "Build GoF++ Tests" OFF)
option(BUILD_EXAMPLES "Build example applications" ON)


if(GOFPP_TEST)
# Enable testing
enable_testing()
add_subdirectory(tests)
endif()

if(BUILD_EXAMPLES)
    add_subdirectory(examples/imgui_sdl2_demo)
    add_subdirectory(examples/imgui_calculator_demo)
endif()

# ---- Install ----
# Install entire include/gofpp directory (patterns + umbrella header)
install(DIRECTORY include/gofpp DESTINATION include)

# Also install umbrella header directly (optional convenience)
install(FILES include/gofpp.hpp DESTINATION include)