#pragma once
#include "pch.h"
#include "TexturedModel.h"
#include "Entity.h"
#include "StaticShader.h"
#include <glm/gtx/projection.hpp>
#include "Window.h"

/**
 * \brief This class manages openGL rendering
 */
class Renderer
{
public:
	Renderer();
	Renderer(StaticShader* pShader);
	~Renderer();
	void render(const Entity* pEntity, StaticShader* pShader);
	void setProjectionMatrix(float fov, float aspectRatio, float zNear, float zFar);

	static Window* s_pWindow;

private:
	mat4 m_projection;
};

