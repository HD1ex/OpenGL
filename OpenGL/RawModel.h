#pragma once
#include "pch.h"

class RawModel
{
public:
	RawModel() = default;
	RawModel(const GLuint vao, const GLuint vertex_count);
	~RawModel();

	//Getters
public:
	GLuint getVao() const;

	GLuint getVertexCount() const;

private:
	GLuint m_vao;
	GLuint m_vertexCount;
};

