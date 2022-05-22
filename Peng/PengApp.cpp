#include "pch.h"

#include "PengApp.h"
#include "GameWindow.h"
#include "KeyCodes.h"

#include "Renderer.h"
#include "Sprite.h"
#include "Shader.h"
#include "Events.h"

namespace Peng {

	PengApp::PengApp() {
		PENG_LOG("Peng has initiated...\n");
		Peng::GameWindow::Init();

		Peng::GameWindow::GetWindow()->CreateWindow(1000, 800, "Pengine");

		Renderer::Init();
	}

	void PengApp::Run() {

		nextFrameTime_ = std::chrono::steady_clock::now() + frameDuration_;


		while (true) {
			Renderer::ClearScreen();

			OnUpdate();

			std::this_thread::sleep_until(nextFrameTime_);

			Peng::GameWindow::GetWindow()->SwapBuffers(); // display frames
			Peng::GameWindow::GetWindow()->PollEvents();

			nextFrameTime_ += frameDuration_;
		}
	}

	void PengApp::OnUpdate() {

	}

	void PengApp::SetKeyPressedCallback(std::function<void(const KeyPressedEvent& )> keyPressedCallback)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(keyPressedCallback);
	}

	void PengApp::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(keyReleasedCallback);
	}

	void PengApp::SetKeyHeldCallback(std::function<void(const KeyHeldEvent&)> keyHeldCallback)
	{
		GameWindow::GetWindow()->SetKeyHeldCallback(keyHeldCallback);
	}

	void PengApp::SetMousePressedCallback(std::function<void(const MousePressedEvent&)> mousePressedCallback)
	{
		GameWindow::GetWindow()->SetMousePressedCallback(mousePressedCallback);
	}

	void PengApp::SetMouseReleasedCallback(std::function<void(const MouseReleasedEvent&)> mouseReleasedCallback)
	{
		GameWindow::GetWindow()->SetMouseReleasedCallback(mouseReleasedCallback);
	}

}