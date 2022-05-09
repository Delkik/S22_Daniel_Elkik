#include "pch.h"
#include "Events.h"

namespace Peng {
	KeyPressedEvent::KeyPressedEvent(int keyCode) : keyCode_(keyCode) {}
	int KeyPressedEvent::GetKeyCode() const
	{
		return keyCode_;
	}


	KeyReleasedEvent::KeyReleasedEvent(int keyCode) : keyCode_(keyCode) {}
	int KeyReleasedEvent::GetKeyCode() const
	{
		return keyCode_;
	}
}
