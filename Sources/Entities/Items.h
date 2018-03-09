#pragma once 

#include "Entity.h"
#include "Shoot.h"
#include "Collision.h"
#include "../Map/Map.h"

class Item : public Entity
{
public:
	using Entity::Entity;

	virtual void Update(sf::Time delta_time);

protected:
	sf::Time m_duration;
};

class Health : public Item
{
public:
	Health(World& world);

	virtual void onDestroy(Entity& other);
	virtual bool isCollide(const Entity& other) const;
};