cmake_minimum_required(VERSION 3.23)

project(FalseKing VERSION 0.0.0 LANGUAGES CXX)

set(BUILD_SHARED_LIBRARIES OFF CACHE BOOL "" FORCE)

set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/box2d)

set(SDL_STATIC_PIC ON CACHE BOOL "" FORCE)
add_subdirectory(deps/sdl)

add_subdirectory(deps/spdlog)

set(MAIN_SOURCES main.cpp)
add_executable(FalseKing ${MAIN_HEADERS} ${MAIN_SOURCES})
target_link_libraries(FalseKing PRIVATE box2d SDL3-static)

