#include "pch.h"
#include "Window.h"

int main()
{
	Window window(1920, 1080);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		error("Failed to initialize GLAD");
	}

	window.setGLViewport();

	//Main loop
	while (window.isOpen())
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.swapBuffers();
		window.processEvents();
	}


	return 0;
}