#include "pch.h"
#include "OpenGLRenderer.h"
#include "GameWindow.h"
#include "glad/glad.h"

namespace Peng {
	void OpenGLRenderer::Draw(Peng::Sprite& picture, float xPos, float yPos, float zPos, Peng::Shader shader)
	{
		float windowWidth{ GameWindow::GetWindow()->GetWidth() * 1.0f };
		float windowHeight{ GameWindow::GetWindow()->GetHeight() * 1.0f };

		shader.Bind();
		picture.Bind();

		//shader.SetUniform2Ints("windowSize", windowWidth, windowHeight);
		//shader.SetUniform3Ints("spriteCoord", xPos, yPos, zPos);

		shader.SetUniform2Floats("windowSize", windowWidth, windowHeight);
		shader.SetUniform3Floats("spriteCoord", xPos, yPos, zPos);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	void OpenGLRenderer::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}