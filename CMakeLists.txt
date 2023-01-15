cmake_minimum_required(VERSION 3.23)

project(FalseKing VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS TRUE)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(BUILD_SHARED_LIBRARIES OFF CACHE BOOL "" FORCE)

set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/box2d)

add_subdirectory(deps/sdl)

include_directories(${CMAKE_SOURCE_DIR}
                    deps/box2d/include
                    deps/entt/single_include
                    deps/rtm/includes
                    deps/sdl/include
                    ${CMAKE_BINARY_DIR}/deps/sdl/include-config-$<CONFIG>
                    ${CMAKE_BINARY_DIR}/deps/sdl/include-config-
                    deps/spdlog/include)

set(GLOBAL_HEADERS aliases.hpp
                   falseking.hpp
                   types.hpp)
add_library(Headers INTERFACE ${GLOBAL_HEADERS})
target_precompile_headers(Headers INTERFACE falseking.hpp)

set(CORE_HEADERS core/window.hpp)
set(CORE_SOURCES core/window.cpp)
add_library(Core STATIC ${CORE_HEADERS} ${CORE_SOURCES})

set(GAME_HEADERS game/instance.hpp)
set(GAME_SOURCES game/instance.cpp)
add_library(Game STATIC ${GAME_HEADERS} ${GAME_SOURCES})

set(MAIN_SOURCES main.cpp)
add_executable(FalseKing ${MAIN_HEADERS} ${MAIN_SOURCES})
target_link_libraries(FalseKing PRIVATE Core Game Headers)
target_link_libraries(FalseKing PRIVATE box2d SDL3-static)

set_property(GLOBAL PROPERTY VS_STARTUP_PROJECT FalseKing)
