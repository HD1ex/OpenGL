#pragma once
#include "ShaderProgram.h"
#include "Camera.h"

class StaticShader :
	public ShaderProgram
{
public:
	StaticShader();
	~StaticShader();

	void loadTransformation(mat4& transformation);
	void loadProjection(mat4& projection);
	void loadView(Camera* pCamera);

protected:
	void bindAttributes() override;
	void getAllUniformLocations() override;
private:
	static const wstring VERTEX_FILE;
	static const wstring FRAGMENT_FILE;
	GLuint m_locationTransformationMatrix;
	GLuint m_locationProjectionMatrix;
	GLuint m_locationViewMatrix;
};

