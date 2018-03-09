#include "Player.h"

Player::Player(World& world) : Entity(Configuration::Textures::PlayerRed, world), m_health(100)
{
	m_time_since_last_shoot = 4;
}

bool Player::isCollide(const Entity& other) const
{
	if (dynamic_cast<const Bullet*>(&other) != nullptr)
	{
		return Collision::CircleTest(m_sprite, other.m_sprite);
	}
	
	if (dynamic_cast<const Health*>(&other) == nullptr)
	{
		return Collision::CircleTest(m_sprite, other.m_sprite);
	}
	return false;
}

void Player::Update(sf::Time delta_time)
{
	float seconds = delta_time.asSeconds();

	m_time_since_last_shoot += seconds;

	if (m_health > 100)
		m_health = 100;

	CollisionWithMap();
	Control();
	Movement(delta_time);

	if (m_time_since_last_shoot >= 5)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			Shoot();
}

void Player::onDestroy(Entity& other)
{
	m_health -= 20;

	if (m_health <= 0)
		Entity::onDestroy(other);
}

void Player::CollisionWithMap()
{
	for (int i = GetPosition().y / 16; i < (GetPosition().y + 16) / 16; i++)
		for (int j = GetPosition().x / 16; j<(GetPosition().x + 16) / 16; j++)
		{
			if (Configuration::map_f->GetTile(j, i).GetType() == TileType::Impassable)
			{
				if (delta.y > 0)
					SetPosition(GetPosition().x, i * 16 - 16);

				if (delta.y < 0)
					SetPosition(GetPosition().x, i * 16 + 16);
					
				if (delta.x > 0)
					SetPosition(j * 16 - 16, GetPosition().y);
					
				if (delta.x < 0)
					SetPosition(j * 16 + 16, GetPosition().y);
			}
		}
}

void Player::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_state = Configuration::PlayerInputs::Left;
		m_speed = 100;
		m_sprite.setTextureRect(sf::IntRect(32, 0, 16, 16));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_state = Configuration::PlayerInputs::Right;
		m_speed = 100;
		m_sprite.setTextureRect(sf::IntRect(48, 0, 16, 16));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_state = Configuration::PlayerInputs::Up;
		m_speed = 100;
		m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_state = Configuration::PlayerInputs::Down;
		m_speed = 100;
		m_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
	}
}

void Player::Shoot()
{
	m_world.Add(new Bullet(*this));
	m_time_since_last_shoot = 0;
	return;
}

void Player::Movement(sf::Time delta_time)
{
	switch (m_state)
	{
	case Configuration::PlayerInputs::Left :
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

	m_speed = 0;

	m_sprite.move(delta.x * delta_time.asSeconds(), delta.y * delta_time.asSeconds());
}

void Player::ChangeHealth(const int quantity)
{
	m_health += quantity;
}