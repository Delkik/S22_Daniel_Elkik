#include "pch.h"

#include "PengApp.h"

namespace Peng {



	void PengApp::Run() {

		PENG_LOG("Peng has initiated...\n");

		while (true) {
			OnUpdate();
		}
	}

	void PengApp::OnUpdate() {

	}

}