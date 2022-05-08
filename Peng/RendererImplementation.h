#pragma once

#include "Shader.h"
#include "Sprite.h"

namespace Peng {
	class RendererImplementation {
	public:
		virtual void Draw(Peng::Sprite& picture, int xPos, int yPos, int zPos, Peng::Shader shader) = 0;
	};
}