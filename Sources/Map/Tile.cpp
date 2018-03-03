#include "Tile.h"

Tile::Tile()
{

}

Tile::Tile(int x, int y, TileType type)
{
	x_ = x;
	y_ = y;
	type_ = type;
}

Tile::Tile(const int x, const int y, const char type)
{
	x_ = x;
	y_ = y;
	SetTypeChar(type);
}

Tile::~Tile()
{

}

sf::Vector2i Tile::GetCoordinates() const
{
	return sf::Vector2i(x_, y_);
}

int Tile::GetX() const
{
	return x_;
}

int Tile::GetY() const
{
	return y_;
}

TileType Tile::GetType() const
{
	return type_;
}

char Tile::GetTypeChar() const
{
	switch (type_)
	{
	case TileType::Ground:
		return '0';

	case TileType::Stone:
		return '1';
	
	case TileType::Wall:
		return '2';

	case TileType::Flower:
		return '3';

	case TileType::Heart:
		return '4';

	default:
		return '0';
	}
}

void Tile::SetType(const TileType type)
{
	type_ = type;
}

void Tile::SetTypeChar(const char type)
{
	switch (type)
	{
	case '0':
		type_ = TileType::Ground;
		break;

	case '1':
		type_ = TileType::Stone;
		break;
	
	case '2':
		type_ = TileType::Wall;
		break;

	case '3':
		type_ = TileType::Flower;
		break;

	case '4':
		type_ = TileType::Heart;
		break;

	default:
		type_ = TileType::Ground;
		break;
	}
}