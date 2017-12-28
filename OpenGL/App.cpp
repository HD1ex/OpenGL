#include "App.h"



App::App()
	:m_window(1920, 1080)
{
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		error("Failed to initialize GLAD");
	}

	m_window.setGLViewport();

	m_pScene = make_unique<MainScene>();
}

int App::run()
{
	//Main loop
	while (m_window.isOpen())
	{
		m_pScene->clear();
		m_pScene->update();
		m_pScene->render();

		m_window.swapBuffers();
		m_window.processEvents();
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