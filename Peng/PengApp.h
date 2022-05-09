#pragma once

#include "PengUtil.h"
#include "pch.h"
#include "Events.h"

#define PENG_FRAMERATE 60

namespace Peng {

	class PENG_API PengApp {

	public:
		void Run();
		virtual void OnUpdate();
		void SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback);
		void SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback);

	private:
		std::chrono::milliseconds frameDuration_{ 1000 / PENG_FRAMERATE };
		std::chrono::steady_clock::time_point nextFrameTime_;
	};

}



