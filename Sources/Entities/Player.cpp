#include "Player.h"

Player::Player(World& world, float x, float y) : Entity(Configuration::Textures::PlayerRed, world), m_health(100)
{
	SetPosition(x, y);

	m_time_since_last_shoot = 0;
}

bool Player::isCollide(const Entity& other) const
{
	return Collision::CircleTest(m_sprite, other.m_sprite);
}

void Player::Update(sf::Time delta_time)
{
	float seconds = delta_time.asSeconds();

	m_time_since_last_shoot += seconds;

	if (m_health > 100)
		m_health = 100;

	if (m_health <= 0)
	{
		onDestroy();
	}

	CollisionWithMap();
	Control();
	Movement(delta_time);

	if (m_time_since_last_shoot >= 5)
		Shoot();
}

void Player::onDestroy()
{
	Entity::onDestroy();
}

void Player::CollisionWithMap()
{
	for (int i = GetPosition().y / 16; i < (GetPosition().y + 16) / 16; i++)
		for (int j = GetPosition().x / 16; j<(GetPosition().x + 16) / 16; j++)
		{
			if (Map::GetMap()->Map::GetTile(j, i)->GetType() == TileType::Stone)
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

			if (Map::GetMap()->Map::GetTile(j, i)->GetType() == TileType::Flower)
			{
				m_health -= 40;
				Map::GetMap()->Map::GetTile(j, i)->SetType(TileType::Ground);
			}

			if (Map::GetMap()->Map::GetTile(j, i)->GetType() == TileType::Heart)
			{
				m_health += 20;
				Map::GetMap()->Map::GetTile(j, i)->SetType(TileType::Ground);
			}
		}
}

void Player::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_state = Configuration::PlayerInputs::Left;
		m_speed = 30;
		m_sprite.setTextureRect(sf::IntRect(32, 0, 16, 16));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_state = Configuration::PlayerInputs::Right;
		m_speed = 30;
		m_sprite.setTextureRect(sf::IntRect(48, 0, 16, 16));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_state = Configuration::PlayerInputs::Up;
		m_speed = 30;
		m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_state = Configuration::PlayerInputs::Down;
		m_speed = 30;
		m_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
	}
}

void Player::Shoot()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_world.Add(new Bullet(*this));
		m_time_since_last_shoot = 0;
		return;
	}
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