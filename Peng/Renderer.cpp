#include "pch.h"
#include "Renderer.h"
#include "GameWindow.h"
#include "specificOpenGL/OpenGLRenderer.h"

namespace Peng {
	void Renderer::Init()
	{
		if (!instance_) {
			instance_ = new Renderer;
		}
	}

	void Renderer::Draw(Peng::Sprite& picture, int xPos, int yPos, int zPos)
	{
		assert(instance_);
		instance_->implementation_->Draw(picture, xPos, yPos, zPos, instance_->shader_);
	}

	Renderer::Renderer() : 
		shader_("../Peng/Assets/Shaders/defaultVertex.glsl", "../Peng/Assets/Shaders/defaultFragment.glsl") 
	{
	#ifdef PENG_OPENGL	
		implementation_ = new OpenGLRenderer;
	#else
			#Only_OpenGL_is_supported
	#endif
	}
}