#include "MainScene.h"

MainScene::MainScene()
{
	m_pShader = make_unique<StaticShader>();
	m_pShader->init();

	m_pLoader = make_unique<Loader>();
	m_pRenderer = make_unique<Renderer>(m_pShader.get());	
	m_pLight = make_unique<Light>(vec3(10, 10, 10), vec3(1, 1, 1));


	m_pModel = ObjLoader::loadObjModel(L"dragon.obj", m_pLoader.get());

	m_pTexture = make_shared<ModelTexture>(m_pLoader->loadTexture("white.png"));
	m_pTexturedModel = make_unique<TexturedModel>(m_pModel.get(), m_pTexture.get());

	m_pEntity = make_unique<Entity>(m_pTexturedModel.get(), vec3(0, 0, 0), vec3(), vec3(1,1,1));

	m_pCamera = make_unique<Camera>();
	m_pCamera->setPosition(vec3(0, 7, 15));

	m_pTexture->setReflectivity(1);
	m_pTexture->setShineDamper(10);
}


MainScene::~MainScene()
{
}

void MainScene::update()
{
	m_pCamera->update();
	m_pEntity->rotate(vec3(0, -0.01f, 0));
}

void MainScene::render()
{
	m_pShader->start();
	m_pShader->loadView(m_pCamera.get());
	m_pShader->loadLight(m_pLight.get());

	m_pRenderer->render(m_pEntity.get(),m_pShader.get());

	m_pShader->stop();
}
