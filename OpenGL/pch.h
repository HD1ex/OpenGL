#pragma once
#include <glad/glad.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <glm/common.hpp>
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <glm/gtx/matrix_operation.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

using namespace std;

inline void error(const char* what, const int line, const char* file)
{
	if (what[0])
	{
		cerr << what << endl;
		cerr << "This Error occured at line " << line << " in file " << file << endl;
	}
	else
	{
		cerr << "An Error occured at line " << line << " in file " << file << endl;
	}

	throw;
}

#define error(text) error(text, __LINE__, __FILE__)

inline bool fileExists(const std::string& name)
{
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}


#include "Tools.h"
