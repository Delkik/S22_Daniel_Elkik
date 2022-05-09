#pragma once

#include "RendererImplementation.h"
#include "Shader.h"
#include "Sprite.h"

namespace Peng {
	class OpenGLRenderer : public RendererImplementation {
		virtual void Draw(Peng::Sprite& picture, int xPos, int yPos, int zPos, Peng::Shader shader) override;
		virtual void ClearScreen() override;

	};
}