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
	vec2 getRotation() const;
	void setRotation(vec2 rotation);

	mat4 createViewMatrix() const;
private:
	vec3 m_position;
	vec2 m_rotation;
	vec2 m_lastCursor;
	vec3 m_lookAt;
	vec3 m_up;
	float m_movementSpeed;
};

