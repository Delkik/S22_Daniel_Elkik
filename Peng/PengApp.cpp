#include "pch.h"

#include "PengApp.h"
#include "GameWindow.h"

#include "glad/glad.h"
#include "Sprite.h"
#include "Shader.h"


namespace Peng {

	void PengApp::Run() {

		PENG_LOG("Peng has initiated...\n");

		Peng::GameWindow::Init();

		Peng::GameWindow::GetWindow()->CreateWindow(800,600,"Pengine");

		Peng::Shader shader{ "../Peng/Assets/Shaders/defaultVertex.glsl","../Peng/Assets/Shaders/defaultFragment.glsl" };
		shader.SetUniform2Ints("windowSize", 800, 600);
		shader.SetUniform3Ints("spriteCoord", 100, 200, 1.0f);

		Peng::Sprite star{"../Peng/Assets/Images/Star.png"};

		while (true) {
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shader.Bind();
			star.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			Peng::GameWindow::GetWindow()->SwapBuffers(); // display frames
			Peng::GameWindow::GetWindow()->PollEvents();
		}
	}

	void PengApp::OnUpdate() {

	}

}