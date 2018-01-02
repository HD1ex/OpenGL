#include "Light.h"



Light::Light(const vec3& position, const vec3& color): m_position(position),
                                                       m_color(color)
{
}

Light::~Light()
{
}

vec3 Light::getPosition() const
{
	return m_position;
}

void Light::setPosition(vec3 position)
{
	m_position = std::move(position);
}

vec3 Light::getColor() const
{
	return m_color;
}

void Light::setColor(vec3 color)
{
	m_color = std::move(color);
}
