#pragma once

#include "Entity.h"
#include "Collision.h"
#include "Shoot.h"
#include "Items.h"
#include "../Map/Map.h"

class Player : public Entity
{
public:
	Player(World& world);

	virtual bool isCollide(const Entity& other) const;
	virtual void Update(sf::Time delta_time);

	void Control();
	void Movement(sf::Time delta_time);
	void CollisionWithMap();
	void Shoot();
	void ChangeHealth(const int quantity);
	virtual void onDestroy(Entity& other);
	
	int m_state;

private:
	int m_speed;
	int m_health;
	sf::Vector2f delta;
	sf::Vector2f m_position;
	float m_time_since_last_shoot;

};