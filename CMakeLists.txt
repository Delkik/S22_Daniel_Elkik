cmake_minimum_required(VERSION 3.16)

project(Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DPENG_WINDOWS)
elseif(APPLE)
	add_definitions(-DPENG_MACOS)
elseif(UNIX)
	add_definitions(-DPENG_LINUX)
endif()

add_subdirectory(Game)
add_subdirectory(Peng)
add_subdirectory(glfw)