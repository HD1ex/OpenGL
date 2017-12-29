#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(const wstring& vertexFile,const wstring& fragmentFile)
	:programID(0)
{
	vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
	fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
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

void ShaderProgram::start() const
{
	glUseProgram(programID);
}

void ShaderProgram::stop()
{
	glUseProgram(0);
}

void ShaderProgram::bindAttribute(int attribute, const string& attributeName) const
{
	glBindAttribLocation(programID, attribute, attributeName.c_str());
}

int ShaderProgram::loadShader(const wstring& filename,const int type)
{
	std::ifstream file(filename);
	std::stringstream buffer;
	buffer << file.rdbuf();
	auto str = buffer.str();
	auto fileData = str.c_str();
	const int fileSize = str.length();

	const int id = glCreateShader(type);
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
