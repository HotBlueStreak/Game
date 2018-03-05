#include "Shoot.h"

void Shoot::Update(sf::Time delta_time)
{
	float seconds = delta_time.asSeconds();
	m_duration -= delta_time;

	if (m_duration < sf::Time::Zero)
		m_alive = false;

	m_sprite.move(delta.x * delta_time.asSeconds(), delta.y * delta_time.asSeconds());
}

Bullet::Bullet(Player& from) : Shoot(Configuration::Textures::Weapons, from.m_world)
{
	m_sprite.setPosition(from.GetPosition());

	m_duration = sf::seconds(5);
	m_direction = from.m_state;

	m_speed = 100;

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
	/*if (dynamic_cast<const Enemy*>(&other) != nullptr)
	{
		return Collision::circleTest(_sprite, other._sprite);
	}*/
	return false;
}

