#pragma once

#include <fstream>
#include <sstream>

#include "Tile.h"
#include "TileType.h"
#include "../Resource Manager/ResourceHolder.h"
#include "../Resource Manager/ResourceIdentifiers.h"

class Map
{
public:
	static void Load(const std::string path);

	static Map* GetMap();

	void SetTextures();

	int GetWidth() const;
	int GetHeight() const;

	void MapRenderer(sf::RenderWindow* window);

	Tile* GetTile(const short x, const short y) const;
	Tile* GetTile(const sf::Vector2f coordinates) const;

private:
	Map();
	Map(const int width, const int height);
	~Map();

private:
	static Map map_;

	int width_;
	int height_;

	//TextureHolder texture;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	std::vector<std::vector<Tile>> tiles_;
};

