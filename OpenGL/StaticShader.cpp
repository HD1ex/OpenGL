#include "StaticShader.h"

const wstring StaticShader::VERTEX_FILE = L"simpleVertexShader.glsl";
const wstring StaticShader::FRAGMENT_FILE = L"simpleFragmentShader.glsl";

StaticShader::StaticShader()
	:ShaderProgram(VERTEX_FILE, FRAGMENT_FILE)
{
}


StaticShader::~StaticShader()
{
	ShaderProgram::~ShaderProgram();
}

void StaticShader::loadTransformation(mat4& transformation)
{
	loadMatrix(m_locationTransformationMatrix, transformation);
}

void StaticShader::loadProjection(mat4& projection)
{
	loadMatrix(m_locationProjectionMatrix, projection);
}

void StaticShader::loadView(Camera* pCamera)
{
	auto mat = pCamera->createViewMatrix();
	loadMatrix(m_locationViewMatrix, mat);
}

void StaticShader::bindAttributes()
{
	bindAttribute(0, "position");
	bindAttribute(1, "textureCoordinates");
}

void StaticShader::getAllUniformLocations()
{
	m_locationTransformationMatrix = getUniformLocation("transformationMatrix");
	m_locationProjectionMatrix = getUniformLocation("projectionMatrix");
	m_locationViewMatrix = getUniformLocation("viewMatrix");

}
