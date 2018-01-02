#pragma once
#include "pch.h"

class Light
{
public:

	Light(const vec3& position, const vec3& color);

	~Light();


	vec3 getPosition() const;
	void setPosition(vec3 position);
	vec3 getColor() const;
	void setColor(vec3 color);
private:
	vec3 m_position;
	vec3 m_color;
};

