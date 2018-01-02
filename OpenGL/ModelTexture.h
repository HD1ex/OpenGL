#pragma once
#include "pch.h"

class ModelTexture
{
public:
	ModelTexture(const GLuint & texture);
	~ModelTexture();

	GLuint getTexture() const;
	float getShineDamper() const;
	void setShineDamper(const float shineDamper);
	float getReflectivity() const;
	void setReflectivity(const float reflectivity);
private:
	GLuint m_texture;
	float m_shineDamper;
	float m_reflectivity;
};

