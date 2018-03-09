#include "Tile.h"

Tile::Tile()
{

}

Tile::Tile(int x, int y, TileType type)
{
	m_x = x;
	m_y = y;
	m_type = type;
}

Tile::Tile(int x, int y, char type)
{
	m_x = x;
	m_y = y;
	SetTypeChar(type);
}

Tile::~Tile()
{

}

sf::Vector2i Tile::GetCoordinates() const
{
	return sf::Vector2i(m_x, m_y);
}

int Tile::GetX() const
{
	return m_x;
}

int Tile::GetY() const
{
	return m_y;
}

TileType Tile::GetType() const
{
	return m_type;
}

char Tile::GetTypeChar() const
{
	switch (m_type)
	{
	case TileType::Passable:
		return '0';

	case TileType::Impassable:
		return '1';

	default:
		return '0';
	}
}

void Tile::SetType(const TileType type)
{
	m_type = type;
}

void Tile::SetTypeChar(const char type)
{
	switch (type)
	{
	case '0':
		m_type = TileType::Passable;
		break;

	case '1':
		m_type = TileType::Impassable;
		break;

	default:
		m_type = TileType::Passable;
		break;
	}
}