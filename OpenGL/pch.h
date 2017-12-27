#pragma once
#include <glad\glad.h>
#include <iostream>
#include <sstream>

using namespace std;

inline void error(const char* what, int line, const char* file)
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
