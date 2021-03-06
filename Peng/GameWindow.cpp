#include "pch.h"
#include "GameWindow.h"
#include "specificGLFW/GlfwWindow.h"

namespace Peng {
	
	void GameWindow::Init() { if (!instance_) { instance_ = new GameWindow; } }

	GameWindow* GameWindow::GetWindow()
	{
		assert(instance_);
		return instance_;
	}


	bool GameWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		return window_->CreateWindow(width, height, windowName);
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

	double* GameWindow::GetMousePosition() const
	{
		return window_->GetMousePosition();
	}

	void GameWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)> keyPressedCallback)
	{
		window_->SetKeyPressedCallback(keyPressedCallback);
	}

	void GameWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)> keyReleasedCallback)
	{
		window_->SetKeyReleasedCallback(keyReleasedCallback);
	}

	void GameWindow::SetKeyHeldCallback(const std::function<void(const KeyHeldEvent&)> keyHeldCallback)
	{
		window_->SetKeyHeldCallback(keyHeldCallback);
	}

	void GameWindow::SetMousePressedCallback(const std::function<void(const MousePressedEvent&)> mousePressedCallback)
	{
		window_->SetMousePressedCallback(mousePressedCallback);
	}

	void GameWindow::SetMouseReleasedCallback(const std::function<void(const MouseReleasedEvent&)> mouseReleasedCallback)
	{
		window_->SetMouseReleasedCallback(mouseReleasedCallback);
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
