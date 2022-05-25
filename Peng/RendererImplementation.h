#pragma once

#include "Shader.h"
#include "Sprite.h"

namespace Peng {
	class RendererImplementation {
	public:
		virtual void Draw(Peng::Sprite& picture, float xPos, float yPos, float zPos, Peng::Shader shader) = 0;
		virtual void ClearScreen() = 0;
	};
}