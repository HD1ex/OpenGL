#pragma once
#include "pch.h"
#include "RawModel.h"
#include "ModelTexture.h"

class TexturedModel
{
public:
	TexturedModel();
	~TexturedModel();

	TexturedModel(RawModel* pRawModel, ModelTexture*pModelTexture);

	RawModel* getRawModel() const;

	ModelTexture* getTexture() const;

private:
	RawModel * m_pModel;
	ModelTexture* m_pTexture;
};
