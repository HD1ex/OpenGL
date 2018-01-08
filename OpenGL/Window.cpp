#include "Window.h"

Window::Window(int width, int height)
	: m_width(width), m_height(height)
{
	//Setup GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create Window
	m_pGLFWWindow = glfwCreateWindow(width, height, "OpenGL", nullptr, nullptr);
	if (m_pGLFWWindow == nullptr)
	{
		error("Failed to create GLFW window");
	}
	glfwMakeContextCurrent(m_pGLFWWindow);
	glfwSetWindowUserPointer(m_pGLFWWindow, this);

	//Events

	glfwSetFramebufferSizeCallback(m_pGLFWWindow, [](GLFWwindow* pW, int width, int height) {
		static_cast<Window*>(glfwGetWindowUserPointer(pW))->onResize(width, height);
	});
}


Window::~Window()
{
	//GLFW Cleanup
	glfwTerminate();
}

GLFWwindow * Window::getGLFWWindow()
{
	return m_pGLFWWindow;
}

void Window::setGLViewport()
{
	glViewport(0, 0, m_width, m_height);
}

bool Window::isOpen()
{
	return glfwWindowShouldClose(m_pGLFWWindow) == 0;
}

void Window::swapBuffers()
{
	glfwSwapBuffers(m_pGLFWWindow);
}

void Window::processEvents()
{
	glfwPollEvents();

	m_timeLastFrame = getTime();
}

float Window::getAspectRatio()
{
	return static_cast<float>(m_width) / m_height;
}

void Window::onResize(int width, int height)
{
	m_width = width;
	m_height = height;
	setGLViewport();
}

bool Window::isKeyPressed(const int glfwKey) const
{
	const auto state = glfwGetKey(m_pGLFWWindow, glfwKey);
	return state == GLFW_PRESS;
}

double Window::getTime() const
{
	return glfwGetTime();
}

double Window::getDeltaTime() const
{
	return getTime() - m_timeLastFrame;
}
