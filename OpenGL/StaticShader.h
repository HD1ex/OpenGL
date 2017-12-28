#pragma once
#include "ShaderProgram.h"
class StaticShader :
	public ShaderProgram
{
public:
	StaticShader();
	~StaticShader();

protected:
	virtual void bindAttributes()override;

private:
	static const wstring VERTEX_FILE;
	static const wstring FRAGMENT_FILE;
};

