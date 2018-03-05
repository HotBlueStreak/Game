#include "Entity.h"


Entity::Entity(Configuration::Textures id, World& world) : m_world(world), m_alive(true)
{
	sf::Texture& texture = Configuration::textures.Get(id);
	m_sprite.setTexture(texture);

	switch (id)
	{
	case Configuration::Textures::Map:
		m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
		break;

	case Configuration::Textures::PlayerRed:
		m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
		break;

	case Configuration::Textures::Weapons:
		m_sprite.setTextureRect(sf::IntRect(0, 0, 4, 4));
		break;

	default:
		m_sprite.setOrigin(texture.getSize().x, texture.getSize().y);
		break;
	}
}

Entity::~Entity()
{

}

void Entity::SetPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
}

void Entity::SetPosition(sf::Vector2f coordinate)
{
	m_sprite.setPosition(coordinate.x, coordinate.y);
}

const sf::Vector2f& Entity::GetPosition() const
{
	return m_sprite.getPosition();
}

bool Entity::isAlive() const
{
	return m_alive;
}

void Entity::onDestroy()
{
	m_alive = false;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
