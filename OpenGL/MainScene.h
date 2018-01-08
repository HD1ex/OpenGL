#pragma once
#include "pch.h"
#include "IScene.h"
#include "StaticShader.h"
#include "Loader.h"
#include "ModelTexture.h"
#include "TexturedModel.h"
#include "ModelLoader.h"
#include "MasterRenderer.h"

class MainScene :
	public IScene
{
public:
	MainScene();
	~MainScene();

	void processInput(Window* window) override;
	void update()override;
	void render()override;

	//Members
private:
	unique_ptr<Loader> m_pLoader;
	unique_ptr<MasterRenderer> m_pRenderer;
	shared_ptr<RawModel> m_pModel;
	shared_ptr<ModelTexture> m_pTexture;
	unique_ptr<TexturedModel> m_pTexturedModel;
	vector<unique_ptr<Entity>> m_vecpEntities;
	unique_ptr<Camera> m_pCamera;
	unique_ptr<Light> m_pLight;
};

