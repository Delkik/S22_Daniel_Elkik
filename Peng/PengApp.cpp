#include "pch.h"

#include "PengApp.h"
#include "GameWindow.h"
#include "KeyCodes.h"

#include "Renderer.h"
#include "Sprite.h"
#include "Shader.h"
#include "Events.h"

namespace Peng {

	void PengApp::Run() {

		PENG_LOG("Peng has initiated...\n");
		Peng::GameWindow::Init();

		Peng::GameWindow::GetWindow()->CreateWindow(800, 600, "Pengine");

		Renderer::Init();

		Peng::Sprite star{ "../Peng/Assets/Images/Star.png" };

		nextFrameTime_ = std::chrono::steady_clock::now() + frameDuration_;


		int x{ 50 }, y{ 51 };
		auto keyCallback = [&x](const KeyPressedEvent& event) {
			if (event.GetKeyCode() == PENG_KEY_LEFT) {
				x -= 5;
			}
			else if (event.GetKeyCode() == PENG_KEY_RIGHT) {
				x += 5;
			}
		};
		auto keyRelease = [](const KeyReleasedEvent& event) {PENG_LOG(event.GetKeyCode()); };
		SetKeyPressedCallback(keyCallback);
		SetKeyReleasedCallback(keyRelease);

		while (true) {
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(star, x, y, 1);


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

}