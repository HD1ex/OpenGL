#include "Camera.h"
#include "Window.h"


Camera::Camera()
	:m_up(0, 1, 0)
	, m_movementSpeed(1.f) // In GL-Units/sec
{

}


Camera::~Camera() = default;

void Camera::update(Window* pWindow)
{
	const auto dt = pWindow->getDeltaTime();

	//Keyboard
	vec3 movementVector;
	if (pWindow->isKeyPressed(GLFW_KEY_W))
		movementVector.z--;
	if (pWindow->isKeyPressed(GLFW_KEY_S))
		movementVector.z++;
	if (pWindow->isKeyPressed(GLFW_KEY_A))
		movementVector.x--;
	if (pWindow->isKeyPressed(GLFW_KEY_D))
		movementVector.x++;
	if (pWindow->isKeyPressed(GLFW_KEY_LEFT_SHIFT))
		movementVector.y++;
	if (pWindow->isKeyPressed(GLFW_KEY_LEFT_CONTROL))
		movementVector.y--;

	//Mouse
	const auto cur = pWindow->getCursorPosition();
	if (pWindow->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
	{
		auto diff = cur - m_lastCursor;

		diff.x *= 0.005f;
		diff.y *= 0.005f;

		m_rotation.x -= diff.x;
		m_rotation.y += diff.y;

		static const double LIMIT = pi<float>() * 0.95f * 0.5f;
		constrain(m_rotation.y, -LIMIT, LIMIT);
	}
	m_lastCursor = cur;

	//Calc rotation
	const auto h = half_pi<float>() - m_rotation.x;
	const auto v = half_pi<float>() - m_rotation.y;
	const auto radius = 1.0f;
	vec3 direction;

	direction.x = radius * sin(v) * cos(h);
	direction.y = radius * cos(v);
	direction.z = radius * sin(v) * sin(h);

	const auto forward = vec3(direction.x, 0, direction.z);
	const auto leftRight = cross(m_up, direction);

	normalize(forward);
	normalize(leftRight);

	if (movementVector.z > 0)
		m_position += forward * m_movementSpeed;
	else if (movementVector.z < 0)
		m_position -= forward * m_movementSpeed;

	if (movementVector.x > 0)
		m_position += leftRight * m_movementSpeed;
	else if (movementVector.x < 0)
		m_position -= leftRight * m_movementSpeed;

	if (movementVector.y > 0)
		m_position += m_up * m_movementSpeed;
	else if (movementVector.y < 0)
		m_position -= m_up * m_movementSpeed;

	//Apply
	m_lookAt = m_position + direction;
}

vec3 Camera::getPosition() const
{
	return m_position;
}

void Camera::setPosition(const vec3 position)
{
	m_position = position;
}

vec2 Camera::getRotation() const
{
	return m_rotation;
}

void Camera::setRotation(const vec2 rotation)
{
	m_rotation = rotation;
}

mat4 Camera::createViewMatrix() const
{
	return glm::lookAtLH(m_position, m_lookAt, m_up);
}
