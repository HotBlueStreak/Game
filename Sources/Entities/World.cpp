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
	m_entities_tmp.push_back(entity);
}

void World::Clear()
{
	for (Entity* entity : m_entities)
		delete entity;
	m_entities.clear();
	
	for (Entity* entity : m_entities_tmp)
		delete entity;
	m_entities_tmp.clear();
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
	return m_entities.size() + m_entities_tmp.size();
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
	if (m_entities_tmp.size() > 0)
		m_entities.merge(m_entities_tmp);

	for (Entity* entity_ptr : m_entities)
	{
		Entity& entity = *entity_ptr;

		entity.Update(delta_time);
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