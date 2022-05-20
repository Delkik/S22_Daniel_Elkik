#include "pch.h"
#include "PengUtil.h"
#include "glad/glad.h"
#include "OpenGLSprite.h"
#include "stb_image.h"

namespace Peng {
	OpenGLSprite::OpenGLSprite(const std::string& filePath)
	{
		// loading texture
		stbi_set_flip_vertically_on_load(true);
		int numChannels;
		unsigned char* data = stbi_load(filePath.c_str(), &width_, &height_, &numChannels, 0);

		if (data == NULL) {
			PENG_LOG("ERROR texture didnt load");
		}

		float vertices[] = {
			 0.0f,			0.0f,			0.0f,	0.0f,	// bottom left
			 0.0f,			(float)height_,	0.0f,	1.0f,	// top left
			 (float)width_,	(float)height_,	1.0f,	1.0f,	// top right
			 (float)width_,	0.0f,			1.0f,	0.0f	// bottom right
		};

		unsigned int indices[] = {
			0, 1, 2,	// first triangle
			0, 2, 3		// second triangle
		};

		glGenVertexArrays(1, &VAO_);
		glGenBuffers(1, &VBO_);
		glGenBuffers(1, &EBO_);

		glBindVertexArray(VAO_);

		glBindBuffer(GL_ARRAY_BUFFER, VBO_);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)8);
		glEnableVertexAttribArray(1);


		/////////// TEXTURE ///////////

		glGenTextures(1, &tex_);
		glBindTexture(GL_TEXTURE_2D, tex_);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	int OpenGLSprite::GetWidth() const
	{
		return width_;
	}
	int OpenGLSprite::GetHeight() const
	{
		return height_;
	}
	void OpenGLSprite::Bind()
	{
		glBindVertexArray(VAO_);
		glBindTexture(GL_TEXTURE_2D, tex_);
	}

	bool OpenGLSprite::IsBound() const
	{
		return false;
	}
}