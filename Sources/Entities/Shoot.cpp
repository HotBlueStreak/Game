#include "Shoot.h"

void Shoot::Update(sf::Time delta_time)
{
	for (int i = GetPosition().y / 16; i < (GetPosition().y + 16) / 16; i++)
		for (int j = GetPosition().x / 16; j<(GetPosition().x + 16) / 16; j++)
			if (Configuration::map_f->GetTile(j, i).GetType() == TileType::Impassable)
				m_alive = false;

	float seconds = delta_time.asSeconds();
	m_duration -= delta_time;

	if (m_duration < sf::Time::Zero)
		m_alive = false;

	m_sprite.move(delta.x * delta_time.asSeconds(), delta.y * delta_time.asSeconds());
}

Bullet::Bullet(Player& from) : Shoot(Configuration::Textures::Weapons, from.m_world)
{
	m_sprite.setPosition(from.GetPosition().x + 8, from.GetPosition().y + 8);

	m_duration = sf::seconds(5);
	m_direction = from.m_state;

	m_speed = 500;

	switch (m_direction)
	{
	case Configuration::PlayerInputs::Left:
		delta.x = -m_speed;
		delta.y = 0;
		break;
	case Configuration::PlayerInputs::Right:
		delta.x = m_speed;
		delta.y = 0;
		break;
	case Configuration::PlayerInputs::Up:
		delta.x = 0;
		delta.y = -m_speed;
		break;
	case Configuration::PlayerInputs::Down:
		delta.x = 0;
		delta.y = m_speed;
		break;
	}

}

bool Bullet::isCollide(const Entity& other) const
{
	if (dynamic_cast<const Player*>(&other) != nullptr)
	{
		return Collision::CircleTest(m_sprite, other.m_sprite);
	}
	return false;
}

