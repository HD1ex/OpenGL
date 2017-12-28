#include "Loader.h"


Loader::~Loader()
{
	glDeleteVertexArrays(m_vaos.size(), m_vaos.data());
	glDeleteBuffers(m_vbos.size(), m_vbos.data());
}

unique_ptr<RawModel> Loader::loadToVao(const vector<float>& positions, const vector<GLuint>& indices)
{
	const int vao = createVao();
	bindIndicesBuffer(indices);
	storeDataInAttributeList(0, 3, positions);
	unbindVao();

	return make_unique<RawModel>(vao, indices.size());
}

GLuint Loader::createVao()
{
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	m_vaos.push_back(vao);
	return vao;
}

void Loader::storeDataInAttributeList(const int attributeNumber, const int vertexSize, const vector<float>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	m_vbos.push_back(vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attributeNumber, vertexSize, GL_FLOAT, false, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVao()
{
	glBindVertexArray(0);
}

void Loader::bindIndicesBuffer(const vector<GLuint>& indices)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	m_vbos.push_back(vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}
