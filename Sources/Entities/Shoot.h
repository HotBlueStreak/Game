#pragma once 

#include "Entity.h"
#include "Player.h"
#include "World.h"
#include "Collision.h"

class Shoot : public Entity
{
public:
	using Entity::Entity;

	virtual void Update(sf::Time deltaTime);

protected:
	sf::Time m_duration;
	int m_speed;
	int direction;
	sf::Vector2f delta;
};


class Bullet : public Shoot
{
public:
	Bullet(Player& from);
	virtual bool isCollide(const Entity& other)const;

private:
	int m_direction;

};
