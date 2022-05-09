#include "pch.h"

#include "glad/glad.h"
#include "GlfwWindow.h"
#include "PengUtil.h"

namespace Peng {

	GlfwWindow::GlfwWindow() {
		
		if (!glfwInit()) {
			PENG_LOG("GLFW failed initialization");
		}
	}

	bool GlfwWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		glfwWindow_ = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		if (glfwWindow_ == nullptr) {
			PENG_LOG("Window was not created.");
			return false;
		}
		glfwMakeContextCurrent(glfwWindow_);
		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			PENG_LOG("GLAD failed to initialize")
		}

		glfwSetWindowUserPointer(glfwWindow_, &callbacks_);


		glfwSetKeyCallback(glfwWindow_, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			if (action == GLFW_PRESS || action == GLFW_REPEAT) {
				Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyPressedEvent event{ key };
				userPointer->keyPressedCallback(event);
			}
			else if (action == GLFW_RELEASE) {
				Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyReleasedEvent event{ key };
				userPointer->keyReleasedCallback(event);
			}
			});
		return true;
	}
	
	void GlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(glfwWindow_);
	
	}
	
	void GlfwWindow::PollEvents()
	{
		glfwPollEvents();
	}
	
	int GlfwWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(glfwWindow_, &width, &height);

		return width;
	}
	
	int GlfwWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(glfwWindow_, &width, &height);

		return height;
	}

	void GlfwWindow::SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback)
	{
		callbacks_.keyPressedCallback = keyPressedCallback;

	}

	void GlfwWindow::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback)
	{
		callbacks_.keyReleasedCallback = keyReleasedCallback;
	}


	GlfwWindow::~GlfwWindow()
	{
		if (glfwWindow_ != nullptr) {
			glfwDestroyWindow(glfwWindow_);
		}
		glfwTerminate();
	}
}