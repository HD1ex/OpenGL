#include "Renderer.h"
#include "Entity.h"
#include "StaticShader.h"

Window* Renderer::s_pWindow = nullptr;

Renderer::Renderer(StaticShader* pShader)
{
	setProjectionMatrix(70, s_pWindow->getAspectRatio(), 0.1f, 1000.f);
	pShader->start();
	pShader->loadProjection(m_projection);
	pShader->stop();
}


Renderer::~Renderer()
{
}

void Renderer::render(const Entity * pEntity, StaticShader* pShader)
{
	const auto pTexturedModel = pEntity->getModel();
	const auto pRawModel = pTexturedModel->getRawModel();
	ModelTexture* pTexture = pTexturedModel->getTexture();

	glBindVertexArray(pRawModel->getVao());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	pShader->loadShineVariables(pTexture->getShineDamper(), pTexture->getReflectivity());
	auto trans = createTransformationMatrix(pEntity->getPosition(), pEntity->getRotation(), pEntity->getScale());
	pShader->loadTransformation(trans);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, pTexturedModel->getTexture()->getTexture());
	glDrawElements(GL_TRIANGLES, pRawModel->getVertexCount(), GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
}

void Renderer::setProjectionMatrix(const float fov, const float aspectRatio, const float zNear, const float zFar)
{
	m_projection = perspective<float>(fov, aspectRatio, zNear, zFar);
}
