#pragma once
#include "pch.h"

class IScene
{
public:
	virtual void clear();
	virtual void update() = 0;
	virtual void render() = 0;
};

