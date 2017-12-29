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
	void bindAttribute(int attribute, const string& attributeName) const;

	//Wrapper functions
private:
	static int loadShader(const wstring& filename,const int type);

	//Members
private:
	int programID;
	int vertexShaderID;
	int fragmentShaderID;
};

