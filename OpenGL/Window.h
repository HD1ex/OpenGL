#pragma once
#include "pch.h"
#include "GLFW\glfw3.h"

class Window
{
	//Public functions
public:
	Window(int width, int height);
	Window(float factor);
	~Window();
	GLFWwindow * getGLFWWindow();
	void setGLViewport();
	bool isOpen();
	void swapBuffers();
	void processEvents();
	float getAspectRatio();
	bool isKeyPressed(int glfwKey) const;

	double getTime() const;
	double getDeltaTime() const;

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

