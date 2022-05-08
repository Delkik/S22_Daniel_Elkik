#pragma once

#include "Sprite.h"
#include "Shader.h"
#include "RendererImplementation.h"

namespace Peng {
	class Renderer
	{
	public:
		static void Init();
		static void Draw(Peng::Sprite& picture, int xPos, int yPos, int zPos);

	private:
		inline static Renderer* instance_{ nullptr };
		RendererImplementation* implementation_{ nullptr };

		Renderer();

		Peng::Shader shader_;
	};
}

