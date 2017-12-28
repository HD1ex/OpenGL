#pragma once
#include "pch.h"
#include "Window.h"
#include "MainScene.h"

class App
{
public:
	App();
	int run();
	~App();

private:
	Window m_window;
	unique_ptr<IScene> m_pScene;
};

