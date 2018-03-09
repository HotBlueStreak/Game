#pragma once

#include <fstream>
#include <sstream>

#include "Tile.h"
#include "TileType.h"
#include "../Configurations/Configuration.h"

class Map : public sf::Drawable
{
public:
	Map(Configuration::Textures id, std::string path);

	int GetWidth() const;
	int GetHeight() const;

	void ShowCollisionMap(sf::RenderWindow* window);

	Tile GetTile(int x, int y) const;
	Tile GetTile(sf::Vector2i coordinates) const;

private:
	int m_width;
	int m_height;

	sf::Sprite m_sprite;

	std::vector<std::vector<Tile>> m_collision_map;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};