#pragma once

#include "PengUtil.h"

namespace Peng {
	class PENG_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;

	private:
		int keyCode_;
	};
	

	class PENG_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int keyCode);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;

	private:
		int keyCode_;
	};
}

