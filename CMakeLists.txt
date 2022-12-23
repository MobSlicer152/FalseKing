cmake_minimum_required(VERSION 3.23)

project(FalseKing VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS TRUE)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(BUILD_SHARED_LIBRARIES OFF CACHE BOOL "" FORCE)

set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/box2d)

set(SDL_STATIC_PIC ON CACHE BOOL "" FORCE)
add_subdirectory(deps/sdl)

include_directories(${CMAKE_SOURCE_DIR}
                    deps/box2d/include
                    deps/rtm/includes
                    deps/sdl/include
                    ${CMAKE_BINARY_DIR}/deps/sdl/include-config-$<CONFIG>
                    ${CMAKE_BINARY_DIR}/deps/sdl/include-config-
                    deps/spdlog/include)

set(GAME_HEADERS Game/game.hpp)
set(GAME_SOURCES Game/game.cpp)
add_library(Game STATIC ${GAME_HEADERS} ${GAME_SOURCES})

set(MAIN_HEADERS falseking.hpp
                 types.hpp)
set(MAIN_SOURCES main.cpp)
add_executable(FalseKing ${MAIN_HEADERS} ${MAIN_SOURCES})
target_link_libraries(FalseKing PRIVATE Game)
target_link_libraries(FalseKing PRIVATE box2d SDL3-static)

set_property(GLOBAL PROPERTY VS_STARTUP_PROJECT FalseKing)
