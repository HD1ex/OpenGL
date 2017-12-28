#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::render(const RawModel* rawModel)
{
	glBindVertexArray(rawModel->getVao());
	glEnableVertexAttribArray(0);
	glDrawElements(GL_TRIANGLES, rawModel->getVertexCount(), GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
