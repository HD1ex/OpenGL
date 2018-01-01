#include "Loader.h"
#include "lodepng.h"


Loader::~Loader()
{
	glDeleteVertexArrays(m_vaos.size(), m_vaos.data());
	glDeleteBuffers(m_vbos.size(), m_vbos.data());
	glDeleteTextures(m_textures.size(), m_textures.data());
}

unique_ptr<RawModel> Loader::loadToVao(const vector<float>& positions, const vector<float>& texCoords, const vector<GLuint>& indices)
{
	const int vao = createVao();
	bindIndicesBuffer(indices);
	storeDataInAttributeList(0, 3, positions);
	storeDataInAttributeList(1, 2, texCoords);
	unbindVao();

	return make_unique<RawModel>(vao, indices.size());
}

bool isPowerOf2(const unsigned value)
{
	const auto l = log2f(value);

	return (l - static_cast<unsigned>(l)) == 0;
}

GLuint Loader::loadTexture(const string& filename)
{
	GLuint tex;
	glGenTextures(1, &tex);
	m_textures.push_back(tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	// Load file and decode image.
	std::vector<unsigned char> image;
	unsigned width, height;
	const auto code = lodepng::decode(image, width, height, filename);

	if (code != 0)
	{
		error(lodepng_error_text(code));
	}

	if(!isPowerOf2(width) || !isPowerOf2(height))
	{
		ostringstream errtxt;
		errtxt << filename << " is not power of 2!";
		error(errtxt.str().c_str());
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return tex;
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
