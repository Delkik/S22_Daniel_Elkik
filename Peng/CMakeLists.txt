set(HEADER_FILES
	Peng.h
	PengApp.h
	PengUtil.h
	GameWindow.h
	WindowImplementation.h
	specificGLFW/GlfwWindow.h
	Sprite.h
	Shader.h
	Renderer.h
	SpriteImplementation.h
	ShaderImplementation.h
	RendererImplementation.h
	specificOpenGL/OpenGLSprite.h
	specificOpenGL/OpenGLShader.h
	specificOpenGL/OpenGLRenderer.h
	Events.h
	KeyCodes.h
	)

set(SOURCE_FILES 
	PengApp.cpp
	GameWindow.cpp
	specificGLFW/GlfwWindow.cpp
	Sprite.cpp
	Shader.cpp
	Renderer.cpp
	specificOpenGL/OpenGLSprite.cpp
	specificOpenGL/OpenGLShader.cpp
	specificOpenGL/OpenGLRenderer.cpp
	)

add_library(Peng SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DPENG_LIB)
add_definitions(-DPENG_DEBUG)
add_definitions(-DPENG_OPENGL)

include_directories(../glfw/include)
include_directories(../Peng)
include_directories(../stbi)
include_directories(../glad/include)

target_precompile_headers(Peng PRIVATE pch.h)

target_link_libraries(Peng glfw glad stbi)