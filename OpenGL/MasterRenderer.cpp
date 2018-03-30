#include "MasterRenderer.h"

Window* MasterRenderer::s_pWindow = nullptr;

MasterRenderer::MasterRenderer()
{
	setProjectionMatrix(70, s_pWindow->getAspectRatio(), 0.1f, 1000.f);

	m_pShader = make_unique<StaticShader>();
	m_pShader->init();
	m_pRenderer = make_unique<EntityRenderer>(m_pShader.get(), m_projection);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}


MasterRenderer::~MasterRenderer()
{

}

void MasterRenderer::render(Light* pSun, Camera* pCamera)
{
	prepare();
	m_pShader->start();
	m_pShader->loadLight(pSun);
	m_pShader->loadView(pCamera);
	m_pRenderer->render(m_mapEntities);
	m_pShader->stop();
	m_mapEntities.clear();
}

void MasterRenderer::processEntity(Entity* pEntity)
{
	const auto pModel = pEntity->getModel();

	m_mapEntities[pModel].push_back(pEntity);

	/*if (m_mapEntities.find(pModel) == m_mapEntities.end())
	{
		m_mapEntities.emplace()
	}

	vector<Entity*>& batch = m_mapEntities.at(pModel);
	batch.push_back(pEntity);*/
}

void MasterRenderer::setGlobalWindow(Window* pWindow)
{
	s_pWindow = pWindow;
}

void MasterRenderer::prepare()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.f, 0.f, 0.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MasterRenderer::setProjectionMatrix(const float fov, const float aspectRatio, const float zNear, const float zFar)
{
	m_projection = perspective<float>(fov, aspectRatio, zNear, zFar);
}
