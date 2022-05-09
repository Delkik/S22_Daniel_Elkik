#include "pch.h"

#include "PengApp.h"
#include "GameWindow.h"

#include "Renderer.h"
#include "Sprite.h"
#include "Shader.h"


namespace Peng {

	void PengApp::Run() {

		PENG_LOG("Peng has initiated...\n");
		Peng::GameWindow::Init();

		Peng::GameWindow::GetWindow()->CreateWindow(800, 600, "Pengine");

		Renderer::Init();

		Peng::Sprite star{ "../Peng/Assets/Images/Star.png" };

		int xPos{ -star.GetWidth() };

		nextFrameTime_ = std::chrono::steady_clock::now() + frameDuration_;

		while (true) {
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(star, xPos, 20, 1);

			xPos = (xPos + 5) % ((Peng::GameWindow::GetWindow()->GetWidth() + star.GetWidth())-star.GetWidth());

			std::this_thread::sleep_until(nextFrameTime_);

			Peng::GameWindow::GetWindow()->SwapBuffers(); // display frames
			Peng::GameWindow::GetWindow()->PollEvents();

			nextFrameTime_ += frameDuration_;
		}
	}

	void PengApp::OnUpdate() {

	}

}