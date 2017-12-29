#pragma once
#include "pch.h"
#include "TexturedModel.h"

/**
 * \brief This class manages openGL rendering
 */
class Renderer
{
public:
	Renderer();
	~Renderer();
	void render(const TexturedModel * pTexturedModel);
};

