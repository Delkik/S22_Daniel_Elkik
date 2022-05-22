#pragma once
#include "pch.h"
#include "Events.h"

namespace Peng {
	
	class WindowImplementation {
	public:
		virtual bool CreateWindow(int width, int height, const std::string& windowName) = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual double* GetMousePosition() const = 0;

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback) = 0;
		virtual void SetKeyHeldCallback(std::function<void(const KeyHeldEvent&)> keyHeldCallback) = 0;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback) = 0;

		virtual void SetMousePressedCallback(std::function<void(const MousePressedEvent&)> mousePressedCallback) = 0;
		virtual void SetMouseReleasedCallback(std::function<void(const MouseReleasedEvent&)> mouseReleasedCallback) = 0;

	};
}