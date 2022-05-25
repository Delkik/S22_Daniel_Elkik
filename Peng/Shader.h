#pragma once

#include "PengUtil.h"
#include "ShaderImplementation.h"

namespace Peng {

	class PENG_API Shader
	{
	public:
		
		Shader(const std::string& vertexFile, const std::string& fragmentFile);

		void SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3);
		void SetUniform2Ints(const std::string& uniformName, int val1, int val2);

		void SetUniform3Floats(const std::string& uniformName, float val1, float val2, float val3);
		void SetUniform2Floats(const std::string& uniformName, float val1, float val2);

		void Bind();


	private:
		ShaderImplementation* implementation_;
	};
}

