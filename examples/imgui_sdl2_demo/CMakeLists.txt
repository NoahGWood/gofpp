cmake_minimum_required(VERSION 3.16)
project(GoFPP_ImGui_SDL2_Demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# ImGui (vendored)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/vendor/imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends)

# GoF++ include
include_directories(${CMAKE_SOURCE_DIR}/../../include)

add_executable(imgui_sdl2_demo main.cpp ${IMGUI_SOURCES})
target_link_libraries(imgui_sdl2_demo ${SDL2_LIBRARIES} GL)
