#include "pch.h"
#include "OpenGLShader.h"
#include "glad/glad.h"
#include "PengUtil.h"


namespace Peng {
	OpenGLShader::OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// FILE READING //
		std::string sourceCode;
		std::ifstream vertexInput{ vertexFile };

		while (vertexInput) {
			std::string line;
			getline(vertexInput, line);
			line.append("\n");
			sourceCode += line;
		}

		vertexInput.close();

		const char* cSource = sourceCode.c_str();
		glShaderSource(vertexShader, 1, &cSource, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "Error shader vertex compilation failed\n" << infoLog << std::endl;
		}

		// fragment shaders
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		// FILE READING //
		sourceCode.clear();
		std::ifstream fragmentInput{ fragmentFile };

		while (fragmentInput) {
			std::string line;
			getline(fragmentInput, line);
			line.append("\n");
			sourceCode += line;
		}

		fragmentInput.close();

		const char* fragSource = sourceCode.c_str();
		glShaderSource(fragmentShader, 1, &fragSource, NULL);
		glCompileShader(fragmentShader);

		//int success;
		//char infoLog[512];
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "Error shader fragment compilation failed\n" << infoLog << std::endl;
		}

		// Link shaders
		shaderProgram_ = glCreateProgram();
		glAttachShader(shaderProgram_, vertexShader);
		glAttachShader(shaderProgram_, fragmentShader);
		glLinkProgram(shaderProgram_);

		glGetProgramiv(shaderProgram_, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram_, 512, NULL, infoLog);
			std::cout << "Error shader linking compilation failed\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLShader::SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3)
	{
		int uniformLocation{ glGetUniformLocation(shaderProgram_,uniformName.c_str()) };
		glUseProgram(shaderProgram_);
		glUniform3i(uniformLocation, val1, val2, val3);
	}

	void OpenGLShader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{	
		int uniformLocation{ glGetUniformLocation(shaderProgram_,uniformName.c_str()) };
		glUseProgram(shaderProgram_);
		glUniform2i(uniformLocation, val1, val2);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(shaderProgram_);
	}
}
