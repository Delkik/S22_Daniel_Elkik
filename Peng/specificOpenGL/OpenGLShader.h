#pragma once
#include "ShaderImplementation.h"

namespace Peng {
	class OpenGLShader : public ShaderImplementation
	{
	public:
		OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile);

		virtual void SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3) override;
		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) override;

		virtual void SetUniform3Floats(const std::string& uniformName, float val1, float val2, float val3) override;
		virtual void SetUniform2Floats(const std::string& uniformName, float val1, float val2) override;

		virtual void Bind() override;

	private:
		unsigned int shaderProgram_;
	};
}