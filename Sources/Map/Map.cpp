#include "Map.h"

std::vector<std::string> SplitString(std::string string, const char delimiter)
{
	std::vector<std::string> strings;
	while (string.size() > 0)
	{
		if (std::count(string.begin(), string.end(), delimiter) > 0)
		{
			strings.push_back(string.substr(0, string.find(delimiter)));
			string.erase(0, string.find(delimiter) + 1);
		}
		else
		{
			strings.push_back(string.substr(0, string.size()));
			string.erase(0, string.size());
		}

	}
	return strings;
}

std::vector<std::string> LoadFile(const std::string path)
{
	std::ifstream file(path);
	std::vector<std::string> strings;

	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string string;
			file >> string;
			strings.push_back(string);
		}
	}
	return strings;
}

Map::Map(Configuration::Textures id, std::string path)
{
	std::vector<std::string> strings = LoadFile(path);

	sf::Texture& texture = Configuration::textures.Get(id);
	m_sprite.setTexture(texture);

	std::vector<std::string> dimensions = SplitString(strings.at(0), ',');
	strings.erase(strings.begin());
	m_width = atoi(dimensions.at(0).c_str());
	m_height = atoi(dimensions.at(1).c_str());

	for (auto i = 0; i < strings.size(); i++)
	{
		std::vector<Tile> vector;
		for (auto j = 0; j < strings.at(i).size(); ++j)
			vector.push_back(Tile(j, i, strings.at(i).at(j)));
		m_collision_map.push_back(vector);
	}
}

void Map::ShowCollisionMap(sf::RenderWindow* window)
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (GetTile(j, i).GetType() == TileType::Passable)
				m_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));

			if (GetTile(j, i).GetType() == TileType::Impassable)
				m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
			
			m_sprite.setPosition(j * 16, i * 16);

			window->draw(m_sprite);
		}
	}
}

Tile Map::GetTile(int x, int y) const
{
	return m_collision_map.at(y).at(x);
}

Tile Map::GetTile(sf::Vector2i coordinates) const
{
	return m_collision_map.at(coordinates.y).at(coordinates.x);
}

int Map::GetWidth() const
{
	return m_width;
}

int Map::GetHeight() const
{
	return m_height;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}