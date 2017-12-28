#pragma once
#include "IScene.h"
#include "StaticShader.h"
#include "Loader.h"
#include "Renderer.h"

class MainScene :
	public IScene
{
public:
	MainScene();
	~MainScene();
	void update()override;
	void render()override;

	//Members
private:
	unique_ptr<StaticShader> m_pShader;
	unique_ptr<Loader> m_pLoader;
	unique_ptr<Renderer> m_pRenderer;
	unique_ptr<RawModel> m_pModel;
};

