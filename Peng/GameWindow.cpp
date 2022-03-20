#include "pch.h"
#include "GameWindow.h"
#include "specificGLFW/GlfwWindow.h"

namespace Peng {
	
	void GameWindow::Init() {
		if (!instance_) { instance_ = new GameWindow; }

	}



	GameWindow* GameWindow::GetWindow()
	{
		assert(instance_);
		return instance_;
	}


	bool GameWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		return window_->CreateWindow(800, 600, "Pengine");
	}

	void GameWindow::SwapBuffers()
	{
		window_->SwapBuffers();

	}

	void GameWindow::PollEvents()
	{
		window_->PollEvents();
	}

	int GameWindow::GetWidth() const
	{
		return window_->GetWidth();
	}

	int GameWindow::GetHeight() const
	{
		return window_->GetHeight();
	}

	GameWindow::GameWindow() {

	#ifdef PENG_WINDOWS
		window_ = new GlfwWindow;
	#elif defined PENG_MACOS
		window_ = new GlfwWindow;
	#elif defined PENG_LINUX
		window_ = new GlfwWindow;
	#else
		#Unsupported_platform
	#endif
	}

}
