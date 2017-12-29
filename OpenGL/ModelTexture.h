#pragma once
#include "pch.h"

class ModelTexture
{
public:
	ModelTexture(const GLuint & texture);
	~ModelTexture();

private:
	GLuint m_texture;
public:
	GLuint getTexture() const;
};

