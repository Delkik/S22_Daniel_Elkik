#pragma once

#include "WindowImplementation.h"
#include "PengUtil.h"
#include "Events.h"

namespace Peng {

	class PENG_API GameWindow {

	public:
		static void Init();
		static GameWindow* GetWindow();

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		void PollEvents();

		int GetWidth() const;
		int GetHeight() const;
		double* GetMousePosition() const;

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)> keyReleasedCallback);
		void SetKeyHeldCallback(const std::function<void(const KeyHeldEvent&)> keyHeldCallback);

		void SetMousePressedCallback(const std::function<void(const MousePressedEvent&)> mousePressedCallback);
		void SetMouseReleasedCallback(const std::function<void(const MouseReleasedEvent&)> mouseReleasedCallback);

	private:
		inline static GameWindow* instance_ { nullptr };
		
		GameWindow();

		WindowImplementation* window_ { nullptr };
	};
	
}


