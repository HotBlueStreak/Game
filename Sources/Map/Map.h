#pragma once

#include <fstream>
#include <sstream>

#include "Tile.h"
#include "TileType.h"
#include "../Configurations/Configuration.h"

class Map
{
public:
	static void Load(const std::string path);

	static Map* GetMap();

	void SetTextures();

	int GetWidth() const;
	int GetHeight() const;

	void MapRenderer(sf::RenderWindow* window);
	void RandomMapGenerate();

	Tile* GetTile(const short x, const short y) const;
	Tile* GetTile(const sf::Vector2i coordinates) const;

private:
	Map();
	Map(const int width, const int height);
	~Map();

private:
	static Map m_map;

	int m_width;
	int m_height;

	int m_count_elements;
	
	sf::Sprite m_sprite;

	std::vector<std::vector<Tile>> m_tiles;
};

