#pragma once
#include "pch.h"
#include "TexturedModel.h"

class Entity
{
public:

	Entity(TexturedModel* pModel, const vec3& position = vec3(0.f), const vec3& rotation = vec3(0.f), const vec3& scale = vec3(1.f));

	Entity();
	~Entity();


	TexturedModel* getModel() const;
	void setModel(TexturedModel* const model);
	vec3 getPosition() const;
	void setPosition(const vec3& position);
	vec3 getRotation() const;
	void setRotation(const vec3& rotation);
	vec3 getScale() const;
	void setScale(const vec3& scale);

	void move(vec3 amount);
	void rotate(vec3 amount);
private:
	TexturedModel * m_pModel;
	vec3 m_position;
	vec3 m_rotation;
	vec3 m_scale;
};

