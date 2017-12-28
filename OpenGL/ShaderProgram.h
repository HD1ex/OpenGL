#pragma once
#include "pch.h"

class ShaderProgram
{
public:
	ShaderProgram(wstring vertexFile, wstring fragmentFile);
	~ShaderProgram();
	void init();
	void start();
	void stop();

protected:
	virtual void bindAttributes() = 0;
	void bindAttribute(int attribute, string attributeName);

	//Wrapper functions
private:
	static int loadShader(wstring filename, int type);

	//Members
private:
	int programID;
	int vertexShaderID;
	int fragmentShaderID;
};

