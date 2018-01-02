#include "ModelTexture.h"


ModelTexture::ModelTexture(const GLuint& texture)
	:m_texture(texture), m_shineDamper(1.0f), m_reflectivity(0.f)
{
}

ModelTexture::~ModelTexture()
{
}

GLuint ModelTexture::getTexture() const
{
	return m_texture;
}

float ModelTexture::getShineDamper() const
{
	return m_shineDamper;
}

void ModelTexture::setShineDamper(const float shineDamper)
{
	m_shineDamper = shineDamper;
}

float ModelTexture::getReflectivity() const
{
	return m_reflectivity;
}

void ModelTexture::setReflectivity(const float reflectivity)
{
	m_reflectivity = reflectivity;
}
