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
		//gladLoadGL();
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			PENG_LOG("GLAD failed to initialize")
		}
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

	GlfwWindow::~GlfwWindow()
	{
		if (glfwWindow_ != nullptr) {
			glfwDestroyWindow(glfwWindow_);
		}
		glfwTerminate();
	}
}