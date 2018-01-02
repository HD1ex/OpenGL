#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::update()
{
	//TODO add proper movement
	auto delta = 0.02f;
	if (GetAsyncKeyState(VK_UP))
		m_position.z -= delta;
	if (GetAsyncKeyState(VK_DOWN))
		m_position.z += delta;
	if (GetAsyncKeyState(VK_LEFT))
		m_position.x -= delta;
	if (GetAsyncKeyState(VK_RIGHT))
		m_position.x += delta;
}

vec3 Camera::getPosition() const
{
	return m_position;
}

void Camera::setPosition(vec3 position)
{
	m_position = std::move(position);
}

vec3 Camera::getRotation() const
{
	return m_rotation;
}

void Camera::setRotation(vec3 rotation)
{
	m_rotation = std::move(rotation);
}

mat4 Camera::createViewMatrix()
{
	mat4 matrix;
	matrix *= glm::rotate(m_rotation.x, vec3(1, 0, 0));
	matrix *= glm::rotate(m_rotation.y, vec3(0, 1, 0));
	matrix *= glm::rotate(m_rotation.z, vec3(0, 0, 1));

	matrix *= translate(-m_position);

	return matrix;
}
