#pragma once
#include "pch.h"
#include <iterator>

mat4 createTransformationMatrix(const vec3 translation, const vec3 rotation, const vec3 scaleValue);

template<typename Out>
void split(const std::string &s, const char delim, Out result);

std::vector<std::string> split(const std::string& s, const char delim);
