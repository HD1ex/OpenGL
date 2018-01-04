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
class EntityRenderer
{
public:
	EntityRenderer(StaticShader * pShader, mat4 & projection);
	~EntityRenderer();
	void render(const map<TexturedModel*, vector<Entity*>>& mapEntities);
	void prepareTexturedModel(TexturedModel* pTexturedModel);
	void unbindTexturedModel();
	void prepareInstance(Entity* pEntity);

private:
	StaticShader * m_pShader;
};

