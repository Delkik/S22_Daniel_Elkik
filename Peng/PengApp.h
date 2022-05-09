#pragma once

#include "PengUtil.h"
#include "pch.h"

#define PENG_FRAMERATE 60

namespace Peng {

	class PENG_API PengApp {

	public:
		void Run();
		virtual void OnUpdate();

	private:
		std::chrono::milliseconds frameDuration_{ 1000 / PENG_FRAMERATE };
		std::chrono::steady_clock::time_point nextFrameTime_;
	};

}



