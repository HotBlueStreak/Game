#pragma once

#include "TileType.h"

class Tile
{
public:
	Tile();
	Tile(int x, int y, TileType type);
	Tile(int x, int y, char type);
	~Tile();

	sf::Vector2i GetCoordinates() const;
	int GetX() const;
	int GetY() const;

	TileType GetType() const;
	char GetTypeChar() const;
	
	void SetType(const TileType type);
	void SetTypeChar(const char type);

private:
	int m_x;
	int m_y;
	TileType m_type;
};

