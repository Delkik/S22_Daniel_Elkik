#include "pch.h"
#include "Shader.h"
//#include "specificOpenGL/OpenGLShader.h"
#include "specificOpenGL/OpenGLShader.h"

namespace Peng {
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
	{
	#ifdef PENG_OPENGL	
		implementation_ = new OpenGLShader{vertexFile, fragmentFile};
	#else
		#Only_OpenGL_is_supported
	#endif
	}

	void Shader::SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3)
	{
		implementation_->SetUniform3Ints(uniformName, val1, val2, val3);
	}

	void Shader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		implementation_->SetUniform2Ints(uniformName, val1, val2);
	}


	void Shader::Bind()
	{
		implementation_->Bind();
	}
}