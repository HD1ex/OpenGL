#include "App.h"
#include <chrono>

App::App()
	:m_window(1280, 720)
{
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		error("Failed to initialize GLAD");
	}

	MasterRenderer::s_pWindow = &m_window;

	m_window.setGLViewport();

	const auto t1 = std::chrono::high_resolution_clock::now();

	m_pScene = make_unique<MainScene>();

	const auto t2 = std::chrono::high_resolution_clock::now();

	cout << "Loading time: " << chrono::duration_cast<chrono::duration<double>>(t2 - t1).count() << " seconds" << endl;
}

int App::run()
{
	//Main loop
	while (m_window.isOpen())
	{
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