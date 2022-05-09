#pragma once

#include "Sprite.h"
#include "Shader.h"
#include "RendererImplementation.h"
#include "PengUtil.h"

namespace Peng {
	class PENG_API Renderer
	{
	public:
		static void Init();
		static void Draw(Peng::Sprite& picture, int xPos, int yPos, int zPos);
		static void ClearScreen();

	private:
		inline static Renderer* instance_{ nullptr };
		RendererImplementation* implementation_{ nullptr };

		Renderer();

		Peng::Shader shader_;
	};
}

