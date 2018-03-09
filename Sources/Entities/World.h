#pragma once

#include <list>
#include <memory>

#include "../Configurations/Configuration.h"
#include "Entity.h"

class Entity;
class World : public sf::Drawable
{
public:
	World(float x, float y);
	~World();

	void Update(sf::Time delta_time);
	void Add(Entity* entity);
	void Clear();
	bool isCollide(const Entity& other);
	
	int GetSize();
	int GetX() const;
	int GetY() const;

	const std::list<Entity*> GetEntities() const;

private:
	std::list<Entity*> m_entities;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	const int m_x;
	const int m_y;
};