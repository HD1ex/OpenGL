#pragma once
#include "pch.h"
#include "Window.h"

class App
{
public:
	App();
	int run();
	~App();

private:
	Window window;
};

