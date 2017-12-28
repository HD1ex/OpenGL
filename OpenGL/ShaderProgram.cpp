#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(wstring vertexFile, wstring fragmentFile)
{
	vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
	vertexShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
}

ShaderProgram::~ShaderProgram()
{
	stop();
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	glDeleteProgram(programID);
}

void ShaderProgram::init()
{
	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	glValidateProgram(programID);
	bindAttributes();
}

void ShaderProgram::start()
{
	glUseProgram(programID);
}

void ShaderProgram::stop()
{
	glUseProgram(0);
}

void ShaderProgram::bindAttribute(int attribute, string attributeName)
{
	glBindAttribLocation(programID, attribute, attributeName.c_str());
}

int ShaderProgram::loadShader(wstring filename, int type)
{
	std::ifstream file(filename);
	std::stringstream buffer;
	buffer << file.rdbuf();
	string str = buffer.str();
	const char* fileData = str.c_str();
	const int fileSize = str.length();

	int id = glCreateShader(type);
	glShaderSource(id, 1, &fileData, &fileSize);
	glCompileShader(id);
	int  success;
	char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(id, sizeof(infoLog), nullptr, infoLog);
		error(infoLog);
	}

	return id;
}
