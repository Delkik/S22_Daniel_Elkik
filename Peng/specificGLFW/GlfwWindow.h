#pragma once
#include "GLFW/glfw3.h"
#include "WindowImplementation.h"
#include "Events.h"

namespace Peng {
	
	class GlfwWindow : public WindowImplementation {
	
	public:
		GlfwWindow();
		virtual bool CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		void SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback) override;
		void SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback) override;
		~GlfwWindow();

	private:
		struct Callbacks {
			std::function<void(const KeyPressedEvent&)> keyPressedCallback{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> keyReleasedCallback{ [](const KeyReleasedEvent&) {} };
		} callbacks_;

		GLFWwindow* glfwWindow_ { nullptr };
	};
}
