#pragma once
#include "ShaderProgram.h"
#include "Camera.h"
#include "Light.h"

class StaticShader :
	public ShaderProgram
{
public:
	StaticShader();
	~StaticShader();

	void loadTransformation(mat4& transformation);
	void loadProjection(mat4& projection);
	void loadView(Camera* pCamera);
	void loadLight(Light* pLight);
	void loadShineVariables(float damper, float reflectivity);

protected:
	void bindAttributes() override;
	void getAllUniformLocations() override;
private:
	static const wstring VERTEX_FILE;
	static const wstring FRAGMENT_FILE;
	GLuint m_locationTransformationMatrix;
	GLuint m_locationProjectionMatrix;
	GLuint m_locationViewMatrix;
	GLuint m_locationLightPosition;
	GLuint m_locationLightColor;
	GLuint m_locationShineDamper;
	GLuint m_locationReflectivity;

};

