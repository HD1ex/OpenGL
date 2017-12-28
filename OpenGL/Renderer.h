#pragma once
#include "pch.h"
#include "RawModel.h"

/**
 * \brief This class manages openGL rendering
 */
class Renderer
{
public:
	Renderer();
	~Renderer();
	void render(const RawModel* rawModel);
};

