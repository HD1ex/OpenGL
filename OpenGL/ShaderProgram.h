#pragma once
#include "pch.h"

class ShaderProgram
{
public:
	ShaderProgram(const wstring &vertexFile, const wstring &fragmentFile);
	virtual ~ShaderProgram();
	void init();
	void start() const;
	void stop();

protected:
	virtual void bindAttributes() = 0;
	virtual void getAllUniformLocations() = 0;

	void bindAttribute(int attribute, const string& attributeName) const;
	GLuint getUniformLocation(string uniformName);

	void loadFloat(GLuint location, float value);
	void loadVector(GLuint location, vec3& value);
	void loadBoolean(GLuint location, bool value);
	void loadMatrix(GLuint location, mat4x4& value);

	//Wrapper functions
private:
	static int loadShader(const wstring& filename,const int type);

	//Members
private:
	int m_programID;
	int m_vertexShaderID;
	int m_fragmentShaderID;
};

