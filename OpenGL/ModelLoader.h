#pragma once
#include "pch.h"
#include "RawModel.h"
#include "Loader.h"

class ModelLoader
{
public:
	static unique_ptr<RawModel> loadObjModel(const wstring& filename, Loader* pLoader);
	static unique_ptr<RawModel> loadCompiledModel(const wstring& filename, Loader* pLoader);
};

