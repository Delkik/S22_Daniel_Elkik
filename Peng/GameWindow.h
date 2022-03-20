#pragma once

#include "WindowImplementation.h"

namespace Peng {

	class GameWindow {

	public:
		static void Init();
		static GameWindow* GetWindow();

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		void PollEvents();
		int GetWidth() const;
		int GetHeight() const;

	private:
		inline static GameWindow* instance_ { nullptr };
		
		GameWindow();

		WindowImplementation* window_ { nullptr };
	};
	
}


