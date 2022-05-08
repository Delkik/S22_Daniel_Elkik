#include "pch.h"

#include "PengApp.h"
#include "GameWindow.h"

#include "glad/glad.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Shader.h"


namespace Peng {

	void PengApp::Run() {

		PENG_LOG("Peng has initiated...\n");
		Peng::GameWindow::Init();

		Peng::GameWindow::GetWindow()->CreateWindow(800,600,"Pengine");

		Renderer::Init();

		Peng::Sprite star{"../Peng/Assets/Images/Star.png"};

		while (true) {
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Renderer::Draw(star, 50, 20, 1);

			Peng::GameWindow::GetWindow()->SwapBuffers(); // display frames
			Peng::GameWindow::GetWindow()->PollEvents();
		}
	}

	void PengApp::OnUpdate() {

	}

}