#include "ObjLoader.h"
#include "Loader.h"

//unique_ptr<RawModel> ObjLoader::loadObjModel(const wstring filename, Loader* pLoader)
//{
//	ifstream file(filename);
//
//	if (!file.is_open())
//	{
//		wostringstream text;
//		text << "File error. Couldn't open file '" << filename << "'";
//		error(text.str().c_str());
//	}
//
//	vector<float> positions;
//	vector<vec2> textures;
//	vector<vec3> normals;
//	vector<GLuint> indices;
//
//	vector<float> texturesOrdered;
//	vector<float> normalsOrdered;
//
//	string line;
//	vector<string> columns;
//	auto lineNumber = 0;
//
//	const auto getArgsAsFloats = [&](size_t num)
//	{
//		if (columns.size() <= num)
//		{
//			wostringstream text;
//			text << "Error wih obj file '" << filename << "'. Faulty line " << lineNumber;
//			error(text.str().c_str());
//		}
//		vector<float> data(num);
//		for (size_t i = 0; i < num; i++)
//		{
//			data[i] = (strtof(columns[i + 1].c_str(), nullptr));
//		}
//
//		return data;
//	};
//
//	while (getline(file, line))
//	{
//		lineNumber++;
//		columns = split(line, ' ');
//
//		if (columns.empty())
//			continue;
//
//		if (columns[0] == "v")
//		{
//			auto data = getArgsAsFloats(3);
//
//			for (auto i = 0; i < 3; i++)
//			{
//				positions.push_back(data[i]);
//			}
//		}
//		else if (columns[0] == "vt")
//		{
//			auto data = getArgsAsFloats(2);
//
//			textures.emplace_back(data[0], data[1]);
//		}
//		else if (columns[0] == "vn")
//		{
//			auto data = getArgsAsFloats(3);
//
//			normals.emplace_back(data[0], data[1], data[2]);
//		}
//		else if (columns[0] == "f")
//		{
//			texturesOrdered.resize(positions.size() / 3 * 2);
//			normalsOrdered.resize(positions.size());
//			break;
//		}
//	}
//
//	while (getline(file, line))
//	{
//		lineNumber++;
//		columns = split(line, ' ');
//
//		if (columns.empty() || columns[0] != "f")
//			continue;
//
//		if (columns.size() < 4)
//		{
//			wostringstream text;
//			text << "Error wih obj file '" << filename << "'. Faulty line " << lineNumber;
//			error(text.str().c_str());
//		}
//
//		for (auto i = 0; i < 3; i++)
//		{
//			auto vertexData = split(columns[1 + i], '/');
//
//			if (vertexData.size() < 3)
//			{
//				wostringstream text;
//				text << "Error wih obj file '" << filename << "'. Faulty line " << lineNumber;
//				error(text.str().c_str());
//			}
//
//			auto index = static_cast<GLuint>(strtol(vertexData[0].c_str(), nullptr, 10) - 1);
//			indices.push_back(index);
//			auto texture = textures[strtol(vertexData[1].c_str(), nullptr, 10) - 1];
//			texture.y = 1.f - texture.y;
//			texturesOrdered[index * 2] = texture.x;
//			texturesOrdered[index * 2 + 1] = texture.y;
//			const auto normal = normals[strtol(vertexData[2].c_str(), nullptr, 10) - 1];
//			normalsOrdered[index * 3] = normal.x;
//			normalsOrdered[index * 3 + 1] = normal.y;
//			normalsOrdered[index * 3 + 2] = normal.z;
//		}
//	}
//
//	return pLoader->loadToVao(positions, texturesOrdered, normalsOrdered, indices);
//}


unique_ptr<RawModel> ObjLoader::loadObjModel(const wstring filename, Loader* pLoader)
{
	ifstream file(filename);

	if (!file.is_open())
	{
		wostringstream text;
		text << "File error. Couldn't open file '" << filename << "'";
		error(text.str().c_str());
	}

	vector<float> positions;
	vector<vec2> textures;
	vector<vec3> normals;
	vector<GLuint> indices;

	vector<float> texturesOrdered;
	vector<float> normalsOrdered;

	string line;
	auto lineNumber = 0;

	while (getline(file, line))
	{
		lineNumber++;

		if (strncmp(line.c_str(), "v ", 2) == 0)
		{
			float data[3];
			sscanf_s(line.c_str(), "v %f %f %f", &data[0], &data[1], &data[2]);

			for (size_t i = 0; i < 3; i++)
			{
				positions.push_back(data[i]);
			}
		}
		else if (strncmp(line.c_str(), "vt ", 2) == 0)
		{
			float data[2];
			sscanf_s(line.c_str(), "vt %f %f", &data[0], &data[1]);

			textures.emplace_back(data[0], data[1]);
		}
		else if (strncmp(line.c_str(), "vn ", 2) == 0)
		{
			float data[3];
			sscanf_s(line.c_str(), "vn %f %f %f", &data[0], &data[1], &data[2]);

			normals.emplace_back(data[0], data[1], data[2]);
		}
		else if (strncmp(line.c_str(), "f ", 2) == 0)
		{
			texturesOrdered.resize(positions.size() / 3 * 2);
			normalsOrdered.resize(positions.size());
			break;
		}
	}
	do
	{
		if (strncmp(line.c_str(), "f ", 2) != 0)
			continue;

		unsigned vertexIndex[3], uvIndex[3], normalIndex[3];

		const auto matches = sscanf_s(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
		if (matches != 9)
		{
			wostringstream text;
			text << "Error wih obj file '" << filename << "'. Faulty line " << lineNumber;
			error(text.str().c_str());
		}

		for (auto i = 0; i < 3; i++)
		{
			auto index = vertexIndex[i] - 1;
			const auto texture = textures[uvIndex[i] - 1];
			const auto normal = normals[normalIndex[i] - 1];

			indices.push_back(index);
			texturesOrdered[index * 2] = texture.x;
			texturesOrdered[index * 2 + 1] = 1.f - texture.y;
			normalsOrdered[index * 3] = normal.x;
			normalsOrdered[index * 3 + 1] = normal.y;
			normalsOrdered[index * 3 + 2] = normal.z;
		}

		lineNumber++;
	} while (getline(file, line));

	return pLoader->loadToVao(positions, texturesOrdered, normalsOrdered, indices);
}