#include "App.h"



App::App()
	:window(1920, 1080)
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		error("Failed to initialize GLAD");
	}

	window.setGLViewport();
}

int App::run()
{
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


App::~App()
{
}

int main()
{
	return App().run();
}