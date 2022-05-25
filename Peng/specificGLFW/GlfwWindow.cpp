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

			if (action == GLFW_PRESS) {
				Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyPressedEvent event{ key };
				userPointer->keyPressedCallback(event);
			}
			else if (action == GLFW_RELEASE) {
				Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyReleasedEvent event{ key };
				userPointer->keyReleasedCallback(event);
			}
			else if (action == GLFW_REPEAT) {
				Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyHeldEvent event{ key };
				userPointer->keyHeldCallback(event);
			}
			});


		glfwSetMouseButtonCallback(glfwWindow_, [](GLFWwindow* window, int button, int action, int mods) {

			if (action == GLFW_PRESS) {
				Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

				MousePressedEvent event{ button };
				userPointer->mousePressedCallback(event);
			}

			else if (action == GLFW_RELEASE) {
				Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

				MouseReleasedEvent event{ button };
				userPointer->mouseReleasedCallback(event);
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

	double* GlfwWindow::GetMousePosition() const
	{
		double x, y;
		glfwGetCursorPos(glfwWindow_,&x,&y);
		y -= GetHeight();
		if (y < 0) { y *= -1; }
		double pos[2]{x,y};
		return pos;
	}

	void GlfwWindow::SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback)
	{
		callbacks_.keyPressedCallback = keyPressedCallback;

	}

	void GlfwWindow::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback)
	{
		callbacks_.keyReleasedCallback = keyReleasedCallback;
	}

	void GlfwWindow::SetKeyHeldCallback(std::function<void(const KeyHeldEvent&)> keyHeldCallback)
	{
		callbacks_.keyHeldCallback = keyHeldCallback;
	}

	void GlfwWindow::SetMousePressedCallback(std::function<void(const MousePressedEvent&)> mousePressedCallback)
	{
		callbacks_.mousePressedCallback = mousePressedCallback;
	}

	void GlfwWindow::SetMouseReleasedCallback(std::function<void(const MouseReleasedEvent&)> mouseReleasedCallback)
	{
		callbacks_.mouseReleasedCallback = mouseReleasedCallback;
	}


	GlfwWindow::~GlfwWindow()
	{
		if (glfwWindow_ != nullptr) {
			glfwDestroyWindow(glfwWindow_);
		}
		glfwTerminate();
	}
}