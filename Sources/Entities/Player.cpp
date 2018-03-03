#include "Player.h"

Player::Player()
{
	LoadTextures();
}

void Player::Update(sf::Time delta_time)
{
	ProcessEvents();
	Movement(delta_time);
	InteractionWithMap();
}

void Player::InteractionWithMap()
{
	for (int i = m_position.y / 16; i < (m_position.y + 16) / 16; i++)
		for (int j = m_position.x / 16; j<(m_position.x + 16) / 16; j++)
		{
			if (Map::GetMap()->Map::GetTile(j, i)->GetTypeChar() == '1')
			{
				if (delta.y > 0)
					m_position.y = i * 16 - 16;

				if (delta.y < 0)
					m_position.y = i * 16 + 16;

				if (delta.x > 0)
					m_position.x = j * 16 - 16;

				if (delta.x < 0)
					m_position.x = j * 16 + 16;
			}

			if (Map::GetMap()->Map::GetTile(j, i)->GetTypeChar() == '3')
			{
				health -= 40;
				Map::GetMap()->Map::GetTile(j, i)->SetType(TileType::Ground);
			}

			if (Map::GetMap()->Map::GetTile(j, i)->GetTypeChar() == '4')
			{
				health += 20;
				Map::GetMap()->Map::GetTile(j, i)->SetType(TileType::Ground);
			}
		}

}

void Player::ProcessEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction = 0;
		speed = 30;
		m_sprite.setTextureRect(sf::IntRect(32, 0, 16, 16));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = 1;
		speed = 30;
		m_sprite.setTextureRect(sf::IntRect(48, 0, 16, 16));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction = 2;
		speed = 30;
		m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = 3;
		speed = 30;
		m_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
	}
}

void Player::Movement(sf::Time delta_time)
{
	switch (direction)
	{
	case 0:
		delta.x = -speed;
		delta.y = 0;
		break;
	case 1:
		delta.x = speed;
		delta.y = 0;
		break;
	case 2:
		delta.x = 0;
		delta.y = -speed;
		break;
	case 3:
		delta.x = 0;
		delta.y = speed;
		break;
	}

	m_position.x += delta.x * delta_time.asSeconds();
	m_position.y += delta.y * delta_time.asSeconds();

	speed = 0;

	m_sprite.setPosition(m_position.x, m_position.y);
}

void Player::SetPosition(sf::Vector2f position)
{
	m_position = position;
}

void Player::SetPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

sf::Vector2f Player::GetPosition()
{
	return m_position;
}

void Player::LoadTextures()
{
	m_texture.Load(Textures::PlayerRed, "Data/Textures/PlayerRed.png");
	m_sprite.setTexture(m_texture.Get(Textures::PlayerRed));
	m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

sf::Sprite Player::GetSprite()
{
	return m_sprite;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}