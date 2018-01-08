#pragma once
#include "pch.h"
#include "Window.h"

class IScene
{
public:
	virtual ~IScene() = default;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void processInput(Window* pWindow) = 0;
};

