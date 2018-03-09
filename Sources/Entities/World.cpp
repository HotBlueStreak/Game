#include "World.h"

World::World(float x, float y) : m_x(x), m_y(y)
{
}

World::~World()
{
	Clear();
}

void World::Add(Entity* entity)
{
	m_entities.push_back(entity);
}

void World::Clear()
{
	for (Entity* entity : m_entities)
		delete entity;
	m_entities.clear();
	
	for (Entity* entity : m_entities)
		delete entity;
	m_entities.clear();
}

bool World::isCollide(const Entity& other)
{
	for (Entity* entity : m_entities)
		if (other.isCollide(*entity))
			return true;
	return false;
}

int World::GetSize()
{
	return m_entities.size() + m_entities.size();
}

int World::GetX() const
{
	return m_x;
}

int World::GetY() const
{
	return m_y;
}

const std::list<Entity*> World::GetEntities() const
{
	return m_entities;
}

void World::Update(sf::Time delta_time)
{

	for (Entity* entity_ptr : m_entities)
	{
		Entity& entity = *entity_ptr;

		entity.Update(delta_time);
	}

	const auto end = m_entities.end();
	for (auto it_i = m_entities.begin(); it_i != end; ++it_i)
	{
		Entity& entity_i = **it_i;
		auto it_j = it_i;
		it_j++;
		for (; it_j != end; ++it_j)
		{
			Entity& entity_j = **it_j;

			if (entity_i.isAlive() and entity_i.isCollide(entity_j))
				entity_i.onDestroy(entity_j);

			if (entity_j.isAlive() and entity_j.isCollide(entity_i))
				entity_j.onDestroy(entity_i);
		}
	}

	for (auto it = m_entities.begin(); it != m_entities.end();)
	{
		if (not (*it)->isAlive())
		{
			delete *it;
			it = m_entities.erase(it);
		}
		else
			++it;
	}
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (Entity* entity : m_entities)
		target.draw(*entity, states);
}