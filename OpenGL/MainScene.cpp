#include "MainScene.h"

MainScene::MainScene()
{
	m_pShader = make_unique<StaticShader>();
	m_pShader->init();

	m_pLoader = make_unique<Loader>();
	m_pRenderer = make_unique<Renderer>();

	const vector<float> vertices = {
		-0.5f, 0.5f, 0.f,
		-0.5f, -0.5f, 0.f,
		0.5f, -0.5f, 0.f,
		0.5f, 0.5f, 0.f,
	};

	const vector<GLuint> indices = {
		0,1,3,
		3,1,2
	};

	m_pModel = m_pLoader->loadToVao(vertices, indices);
}


MainScene::~MainScene()
{
}

void MainScene::update()
{
}

void MainScene::render()
{
	m_pShader->start();

	m_pRenderer->render(m_pModel.get());

	m_pShader->stop();
}
