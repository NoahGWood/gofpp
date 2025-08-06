cmake_minimum_required(VERSION 3.16)
project(GoFPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

option(GOFPP_TEST "Build GoF++ Tests" OFF)

if(GOFPP_TEST)
# Enable testing
enable_testing()
add_subdirectory(tests)
endif()


# ---- Install ----
# Install entire include/gofpp directory (patterns + umbrella header)
install(DIRECTORY include/gofpp DESTINATION include)

# Also install umbrella header directly (optional convenience)
install(FILES include/gofpp.hpp DESTINATION include)