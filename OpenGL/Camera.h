#pragma once
#include "pch.h"
#include "Window.h"

class Camera
{
public:
	Camera();
	~Camera();

	void update(Window* pWindow);

	vec3 getPosition() const;
	void setPosition(vec3 position);
	vec3 getRotation() const;
	void setRotation(vec3 rotation);

	mat4 createViewMatrix();
private:
	vec3 m_position;
	vec3 m_rotation;
};

