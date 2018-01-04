#pragma once
#include "pch.h"
#include <iterator>

mat4 createTransformationMatrix(const vec3 translation, const vec3 rotation, const vec3 scaleValue);

template<typename Out>
void split(const std::string &s, const char delim, Out result);

std::vector<std::string> split(const std::string& s, const char delim);

long getFileSize(const std::string& filename);

float randomFloat();

template <typename TK, typename TV>
std::vector<TK> extract_keys(std::map<TK, TV> const& inputMap)
{
	std::vector<TK> retval;
	for (auto const& element : inputMap)
	{
		retval.push_back(element.first);
	}
	return retval;
}

template <typename TK, typename TV>
std::vector<TV> extract_values(std::map<TK, TV> const& inputMap)
{
	std::vector<TV> retval;
	for (auto const& element : inputMap)
	{
		retval.push_back(element.second);
	}
	return retval;
}