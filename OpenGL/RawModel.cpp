#include "RawModel.h"

RawModel::RawModel(const GLuint vao, const GLuint vertexCount)
	: m_vao(vao),
	m_vertexCount(vertexCount)
{
}

RawModel::~RawModel()
{
}

GLuint RawModel::getVao() const
{
	return m_vao;
}

GLuint RawModel::getVertexCount() const
{
	return m_vertexCount;
}
