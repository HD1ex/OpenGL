#include "ModelTexture.h"


ModelTexture::ModelTexture(const GLuint& texture)
	:m_texture(texture)
{
}

ModelTexture::~ModelTexture()
{
}

GLuint ModelTexture::getTexture() const
{
	return m_texture;
}
