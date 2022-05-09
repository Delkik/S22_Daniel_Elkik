#include "pch.h"
#include "OpenGLRenderer.h"
#include "GameWindow.h"
#include "glad/glad.h"

namespace Peng {
	void OpenGLRenderer::Draw(Peng::Sprite& picture, int xPos, int yPos, int zPos, Peng::Shader shader)
	{
		int windowWidth{ GameWindow::GetWindow()->GetWidth() };
		int windowHeight{ GameWindow::GetWindow()->GetHeight() };

		shader.Bind();
		picture.Bind();

		shader.SetUniform2Ints("windowSize", windowWidth, windowHeight);
		shader.SetUniform3Ints("spriteCoord", xPos, yPos, zPos);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	void OpenGLRenderer::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}