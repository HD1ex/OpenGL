#include "TexturedModel.h"



TexturedModel::TexturedModel()
{
}


TexturedModel::~TexturedModel()
{
}

TexturedModel::TexturedModel(RawModel* pRawModel, ModelTexture* pModelTexture)
	: m_pModel(pRawModel), m_pTexture(pModelTexture)
{
}

RawModel* TexturedModel::getRawModel() const
{
	return m_pModel;
}

ModelTexture* TexturedModel::getTexture() const
{
	return m_pTexture;
}
