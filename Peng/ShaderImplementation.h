#pragma once

namespace Peng {
	class ShaderImplementation 
	{
	public:
		virtual void Bind() = 0;
		virtual void SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3) = 0;
		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) = 0;

		virtual void SetUniform3Floats(const std::string& uniformName, float val1, float val2, float val3) = 0;
		virtual void SetUniform2Floats(const std::string& uniformName, float val1, float val2) = 0;

	};
}