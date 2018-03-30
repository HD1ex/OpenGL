#pragma once
#include "pch.h"
#include "StaticShader.h"
#include "EntityRenderer.h"

class MasterRenderer
{
public:
	MasterRenderer();
	~MasterRenderer();
	void render(Light* pSun, Camera* pCamera);
	void processEntity(Entity* pEntity);

	static void setGlobalWindow(Window* pWindow);

private:
	void prepare();
	void setProjectionMatrix(const float fov, const float aspectRatio, const float zNear, const float zFar);

private:
	static Window* s_pWindow;

	unique_ptr<StaticShader> m_pShader;
	unique_ptr<EntityRenderer> m_pRenderer;
	map<TexturedModel*, vector<Entity*>> m_mapEntities;
	mat4 m_projection;
};

