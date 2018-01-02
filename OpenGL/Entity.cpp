#include "Entity.h"
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat.hpp>


Entity::Entity(TexturedModel* pModel, const vec3& position, const vec3& rotation, const vec3& scale)
	: m_pModel(pModel),
	m_position(position),
	m_rotation(rotation),
	m_scale(scale)
{
}

Entity::Entity()
{
}


Entity::~Entity()
{
}

TexturedModel* Entity::getModel() const
{
	return m_pModel;
}

void Entity::setModel(TexturedModel* const model)
{
	m_pModel = model;
}

vec3 Entity::getPosition() const
{
	return m_position;
}

void Entity::setPosition(const vec3& position)
{
	m_position = position;
}

vec3 Entity::getRotation() const
{
	return m_rotation;
}

void Entity::setRotation(const vec3& rotation)
{
	m_rotation = rotation;
}

vec3 Entity::getScale() const
{
	return m_scale;
}

void Entity::setScale(const vec3& scale)
{
	m_scale = scale;
}

void Entity::move(const vec3 amount)
{
	m_position += amount;
}

void Entity::rotate(const vec3 amount)
{
	m_rotation += amount;
}
