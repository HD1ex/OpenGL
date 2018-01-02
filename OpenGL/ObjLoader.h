#pragma once
#include "pch.h"
#include "RawModel.h"

class Loader;

class ObjLoader
{
public:
	static unique_ptr<RawModel> loadObjModel(wstring filename, Loader* pLoader);
};

