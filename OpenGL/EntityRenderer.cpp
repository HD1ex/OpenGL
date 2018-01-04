#include "EntityRenderer.h"
#include "Entity.h"
#include "StaticShader.h"

EntityRenderer::EntityRenderer(StaticShader* pShader, mat4& projection)
	:m_pShader(pShader)
{
	pShader->start();
	pShader->loadProjection(projection);
	pShader->stop();
}


EntityRenderer::~EntityRenderer()
{
}

void EntityRenderer::render(const map<TexturedModel*, vector<Entity*>>& mapEntities)
{
	const auto models = extract_keys(mapEntities);

	for(auto pModel : models)
	{
		const auto& batch = mapEntities.at(pModel);
		prepareTexturedModel(pModel);
		for(auto pEntity : batch)
		{
			prepareInstance(pEntity);

			glDrawElements(GL_TRIANGLES, pModel->getRawModel()->getVertexCount(), GL_UNSIGNED_INT, nullptr);
		}
		unbindTexturedModel();
	}
}

void EntityRenderer::prepareTexturedModel(TexturedModel* pTexturedModel)
{
	const auto pRawModel = pTexturedModel->getRawModel();
	glBindVertexArray(pRawModel->getVao());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	const auto pTexture = pTexturedModel->getTexture();

	m_pShader->loadShineVariables(pTexture->getShineDamper(), pTexture->getReflectivity());
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, pTexturedModel->getTexture()->getTexture());
}

void EntityRenderer::unbindTexturedModel()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
}

void EntityRenderer::prepareInstance(Entity* pEntity)
{
	auto trans = createTransformationMatrix(pEntity->getPosition(), pEntity->getRotation(), pEntity->getScale());
	m_pShader->loadTransformation(trans);
}
