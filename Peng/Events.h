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

	class PENG_API KeyHeldEvent
	{
	public:
		KeyHeldEvent(int keyCode);
		KeyHeldEvent() = delete;

		int GetKeyCode() const;

	private:
		int keyCode_;
	};

	class PENG_API MousePressedEvent
	{
	public:
		MousePressedEvent(int button);
		MousePressedEvent() = delete;

		int GetButton() const;

	private:
		int button_;
	};

	class PENG_API MouseReleasedEvent
	{
	public:
		MouseReleasedEvent(int button);
		MouseReleasedEvent() = delete;

		int GetButton() const;

	private:
		int button_;
	};
}

