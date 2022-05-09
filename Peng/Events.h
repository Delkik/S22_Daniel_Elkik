#pragma once

namespace Peng {
	class KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;

	private:
		int keyCode_;
	};
	


	class KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int keyCode);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;

	private:
		int keyCode_;
	};
}

