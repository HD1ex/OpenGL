#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(const wstring& vertexFile,const wstring& fragmentFile)
	:m_programID(0)
{
	m_vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
	m_fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
}

ShaderProgram::~ShaderProgram()
{
	stop();
	glDetachShader(m_programID, m_vertexShaderID);
	glDetachShader(m_programID, m_fragmentShaderID);
	glDeleteShader(m_vertexShaderID);
	glDeleteShader(m_fragmentShaderID);
	glDeleteProgram(m_programID);
}

void ShaderProgram::init()
{
	m_programID = glCreateProgram();
	glAttachShader(m_programID, m_vertexShaderID);
	glAttachShader(m_programID, m_fragmentShaderID);
	bindAttributes();
	glLinkProgram(m_programID);
	glValidateProgram(m_programID);
	getAllUniformLocations();
}

void ShaderProgram::start() const
{
	glUseProgram(m_programID);
}

void ShaderProgram::stop()
{
	glUseProgram(0);
}

void ShaderProgram::bindAttribute(int attribute, const string& attributeName) const
{
	glBindAttribLocation(m_programID, attribute, attributeName.c_str());
}

GLuint ShaderProgram::getUniformLocation(string uniformName)
{
	return glGetUniformLocation(m_programID, uniformName.c_str());
}

void ShaderProgram::loadFloat(const GLuint location, const float value)
{
	glUniform1f(location, value);
}

void ShaderProgram::loadVector(const GLuint location,const vec3 & value)
{
	glUniform3f(location, value.x, value.y, value.z);
}

void ShaderProgram::loadBoolean(const GLuint location, bool value)
{
	glUniform1f(location, value);
}

void ShaderProgram::loadMatrix(const GLuint location, mat4x4 & value)
{
	glUniformMatrix4fv(location, 1, false, value_ptr(value));
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
