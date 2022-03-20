#include "pch.h"

#include "PengApp.h"
#include "GameWindow.h"


namespace Peng {

	void PengApp::Run() {

		PENG_LOG("Peng has initiated...\n");

		Peng::GameWindow::Init();

		Peng::GameWindow::GetWindow()->CreateWindow(800,600,"Pengine");

		while (true) {
			OnUpdate();

			Peng::GameWindow::GetWindow()->SwapBuffers(); // display frames
			Peng::GameWindow::GetWindow()->PollEvents();
		}
	}

	void PengApp::OnUpdate() {

	}

}