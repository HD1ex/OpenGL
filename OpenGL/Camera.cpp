#include "Camera.h"
#include "Window.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::update(Window* pWindow)
{
	const auto dt = pWindow->getDeltaTime();

	const auto delta = 5.f; // In GL-Time
	if (pWindow->isKeyPressed(GLFW_KEY_W))
		m_position.z -= delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_S))
		m_position.z += delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_A))
		m_position.x -= delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_D))
		m_position.x += delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_LEFT_SHIFT))
		m_position.y += delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_LEFT_CONTROL))
		m_position.y -= delta * dt;
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
