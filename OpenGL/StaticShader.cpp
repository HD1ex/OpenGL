#include "StaticShader.h"

const wstring StaticShader::VERTEX_FILE = L"simpleVertexShader.glsl";
const wstring StaticShader::FRAGMENT_FILE = L"simpleFragmentShader.glsl";

StaticShader::StaticShader()
	:ShaderProgram(VERTEX_FILE, FRAGMENT_FILE)
{
}


StaticShader::~StaticShader()
{
}

void StaticShader::bindAttributes()
{
	bindAttribute(0, "position");
}
