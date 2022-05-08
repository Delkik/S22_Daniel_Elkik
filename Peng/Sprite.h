#pragma once

#include "SpriteImplementation.h"
#include "PengUtil.h"

namespace Peng {

	class PENG_API Sprite
	{

	public:
		Sprite(const std::string& filename);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();

	private:
		SpriteImplementation* implementation_;
	};
}

