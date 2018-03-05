#pragma once

#include "../Configurations/Configuration.h"
#include "World.h"

class World;
class Entity : public sf::Drawable
{
public:
	Entity(Configuration::Textures id, World& world);
	virtual ~Entity();

	virtual bool isAlive() const;
	virtual bool isCollide(const Entity& other) const = 0;
	virtual void onDestroy();

	const sf::Vector2f& GetPosition() const;
	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f position);

	virtual void Update(sf::Time delta_time) = 0;

protected:
	friend class Player;
	friend class Bullet;

	sf::Sprite m_sprite;
	World& m_world;
	bool m_alive;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};