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

	const vector<float> texCoords = {
		0,0,
		0,1,
		1,1,
		1,0,
	};

	m_pModel = m_pLoader->loadToVao(vertices, texCoords, indices);

	m_pTexture = make_shared<ModelTexture>(m_pLoader->loadTexture("test_texture.png"));
	m_pTexturedModel = make_unique<TexturedModel>(m_pModel.get(), m_pTexture.get());
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

	m_pRenderer->render(m_pTexturedModel.get());

	m_pShader->stop();
}
