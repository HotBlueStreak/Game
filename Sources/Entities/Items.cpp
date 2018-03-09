#include "Items.h"
#include "Player.h"

void Item::Update(sf::Time delta_time)
{
	float seconds = delta_time.asSeconds();

	m_duration -= delta_time;

	if (m_duration < sf::Time::Zero)
		m_alive = false;
}

Health::Health(World& world) : Item(Configuration::Textures::Items, world)
{
	m_duration = sf::seconds(30);
	
	m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

void Health::onDestroy(Entity& other)
{
	Player* ptr = dynamic_cast<Player*>(&other);

	ptr->ChangeHealth(20);

	Item::onDestroy(other);
}

bool Health::isCollide(const Entity& other) const
{
	if (dynamic_cast<const Player*>(&other) != nullptr)
	{
		return Collision::CircleTest(m_sprite, other.m_sprite);
	}
	return false;
}