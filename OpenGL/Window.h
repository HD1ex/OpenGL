#pragma once
#include "pch.h"
#include "GLFW/glfw3.h"

class Window
{
	//Public functions
public:
	Window(int width, int height);
	Window(float factor);
	~Window();
	GLFWwindow * getGLFWWindow() const;
	void setGLViewport() const;
	bool isOpen() const;
	void swapBuffers() const;
	void processEvents();
	float getAspectRatio() const;
	bool isKeyPressed(int glfwKey) const;
	vec2 getCursorPosition() const;

	double getTime() const;
	double getDeltaTime() const;
	void closeOnEscape() const;
	bool isMouseButtonPressed(int button);

	//Wrapper functions
private:
	void onResize(int width, int height);

	//Members
private:
	GLFWwindow * m_pGLFWWindow;
	int m_width;
	int m_height;
	double m_timeLastFrame;

};

