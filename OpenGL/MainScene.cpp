#include "MainScene.h"

MainScene::MainScene()
{
	m_pLoader = make_unique<Loader>();
	m_pRenderer = make_unique<MasterRenderer>();
	m_pLight = make_unique<Light>(vec3(10, 10, 10), vec3(1, 1, 1));

	m_pModel = ModelLoader::loadCompiledModel(L"dragon.model", m_pLoader.get());

	m_pTexture = make_shared<ModelTexture>(m_pLoader->loadTexture("white.png"));
	m_pTexturedModel = make_unique<TexturedModel>(m_pModel.get(), m_pTexture.get());

	/*for (float x = 0; x < 100; x += 10.f)
		for (float z = 0; z < 100; z += 10.f)
		{
			m_vecpEntities.push_back(make_unique<Entity>(m_pTexturedModel.get(), vec3(x, 0, z)));
		}*/

	m_vecpEntities.push_back(make_unique<Entity>(m_pTexturedModel.get(), vec3(0, 0, 0)));


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
	for (auto& pEntity : m_vecpEntities)
		pEntity->rotate(vec3(0, 0.01f, 0));
}

void MainScene::render()
{
	for (auto& pEntity : m_vecpEntities)
		m_pRenderer->processEntity(pEntity.get());

	m_pRenderer->render(m_pLight.get(), m_pCamera.get());
}
