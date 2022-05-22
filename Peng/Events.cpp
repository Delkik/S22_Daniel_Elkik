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


	KeyHeldEvent::KeyHeldEvent(int keyCode) : keyCode_(keyCode) {}
	int KeyHeldEvent::GetKeyCode() const
	{
		return keyCode_;
	}


	MousePressedEvent::MousePressedEvent(int button) : button_(button) {}
	int MousePressedEvent::GetButton() const 
	{
		return button_;
	}

	MouseReleasedEvent::MouseReleasedEvent(int button) : button_(button) {}
	int MouseReleasedEvent::GetButton() const
	{
		return button_;
	}


}	
