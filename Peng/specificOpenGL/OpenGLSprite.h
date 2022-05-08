#pragma once

#include "SpriteImplementation.h"

namespace Peng {
	class OpenGLSprite : public SpriteImplementation
	{
	public:
		OpenGLSprite(const std::string& filePath);
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
		virtual bool IsBound() const override;
	private:
		unsigned int VBO_;
		unsigned int VAO_;
		unsigned int EBO_;
		unsigned int tex_;
		int width_{ 0 };
		int height_{ 0 };


	};
}