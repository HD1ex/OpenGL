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

	vec4 dir;

	const auto delta = 5.f; // In GL-Units/sec
	if (pWindow->isKeyPressed(GLFW_KEY_W))
		dir.z -= delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_S))
		dir.z += delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_A))
		dir.x -= delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_D))
		dir.x += delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_LEFT_SHIFT))
		dir.y += delta * dt;
	if (pWindow->isKeyPressed(GLFW_KEY_LEFT_CONTROL))
		dir.y -= delta * dt;

	const auto mat = createTransformationMatrix(vec3(), m_rotation, vec3(1));

	dir = mat * dir;

	m_position.x += dir.x;
	m_position.y += dir.y;
	m_position.z += dir.z;
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
