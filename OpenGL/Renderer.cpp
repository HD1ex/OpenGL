#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::render(const TexturedModel * pTexturedModel)
{
	const auto pRawModel = pTexturedModel->getRawModel();
	glBindVertexArray(pRawModel->getVao());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, pTexturedModel->getTexture()->getTexture());
	glDrawElements(GL_TRIANGLES, pRawModel->getVertexCount(), GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}
