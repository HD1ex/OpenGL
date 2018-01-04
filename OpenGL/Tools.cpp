#include "Tools.h"


mat4 createTransformationMatrix(const vec3 translation, const vec3 rotation, const vec3 scaleValue)
{
	mat4 matrix;

	matrix *= translate(translation);

	matrix *= glm::rotate(rotation.x, vec3(1, 0, 0));
	matrix *= glm::rotate(rotation.y, vec3(0, 1, 0));
	matrix *= glm::rotate(rotation.z, vec3(0, 0, 1));

	matrix *= scale(scaleValue);

	return matrix;
}

std::vector<std::string> split(const std::string& s, const char delim)
{
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

template<typename Out>
void split(const std::string &s, const char delim, Out result)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		*(result++) = item;
	}
}



long getFileSize(const std::string& filename)
{
	struct stat stat_buf;
	const auto rc = stat(filename.c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
}

float randomFloat()
{
	const float max = INT_MAX;

	return rand() / max;
}
