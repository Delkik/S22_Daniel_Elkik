#include "pch.h"
#include "Sprite.h"
#include "specificOpenGL/OpenGLSprite.h"

namespace Peng {
	Sprite::Sprite(const std::string& filename)
	{
#ifdef PENG_OPENGL
		implementation_ = new OpenGLSprite{filename}; 
#else
	#Only_OpenGL_is_supported
#endif
	}
	int Sprite::GetWidth() const
	{
		return implementation_->GetWidth();
	}
	int Sprite::GetHeight() const
	{
		return implementation_->GetHeight();
	}
	void Sprite::Bind()
	{
		implementation_->Bind();
	}
}