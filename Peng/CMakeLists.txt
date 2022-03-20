set(HEADER_FILES
	Peng.h
	PengApp.h
	PengUtil.h
	GameWindow.h
	WindowImplementation.h
	specificGLFW/GlfwWindow.h
	)

set(SOURCE_FILES 
	PengApp.cpp
	GameWindow.cpp
	specificGLFW/GlfwWindow.cpp
	)

add_library(Peng SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DPENG_LIB)
add_definitions(-DPENG_DEBUG)

include_directories(../glfw/include)
include_directories(../Peng)

target_precompile_headers(Peng PRIVATE pch.h)

target_link_libraries(Peng glfw)