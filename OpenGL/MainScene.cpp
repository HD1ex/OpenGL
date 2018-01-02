#include "MainScene.h"

MainScene::MainScene()
{
	m_pShader = make_unique<StaticShader>();
	m_pShader->init();

	m_pLoader = make_unique<Loader>();
	m_pRenderer = make_unique<Renderer>(m_pShader.get());

	const vector<float> vertices = {
		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,0.5f,-0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		0.5f,0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,0.5f,0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f
	};

	const vector<GLuint> indices = {
		0,1,3,
		3,1,2,
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22
	};

	const vector<float> texCoords = {
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0
	};

	m_pModel = m_pLoader->loadToVao(vertices, texCoords, indices);

	m_pTexture = make_shared<ModelTexture>(m_pLoader->loadTexture("test_texture.png"));
	m_pTexturedModel = make_unique<TexturedModel>(m_pModel.get(), m_pTexture.get());

	m_pEntity = make_unique<Entity>(m_pTexturedModel.get(), vec3(0, 0, -1), vec3(), vec3(1,1,1));

	m_pCamera = make_unique<Camera>();
}


MainScene::~MainScene()
{
}

void MainScene::update()
{
	m_pCamera->update();
	m_pEntity->rotate(vec3(0.017f, -0.01f, 0));
}

void MainScene::render()
{
	m_pShader->start();
	m_pShader->loadView(m_pCamera.get());

	m_pRenderer->render(m_pEntity.get(),m_pShader.get());

	m_pShader->stop();
}
