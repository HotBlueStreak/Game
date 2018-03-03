#include "Map.h"

Map Map::map_;

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

void Map::MapRenderer(sf::RenderWindow* window)
{
	for (int i = 0; i < height_; i++)
		for (int j = 0; j < width_; j++)
		{
			if (GetTile(i, i)->GetTypeChar() == '0')
				m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));

			if (GetTile(j, i)->GetTypeChar() == '1')
				m_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));

			if (GetTile(j, i)->GetTypeChar() == '2')
				m_sprite.setTextureRect(sf::IntRect(32, 0, 16, 16));

			if (GetTile(j, i)->GetTypeChar() == '3')
				m_sprite.setTextureRect(sf::IntRect(48, 0, 16, 16));

			if (GetTile(j, i)->GetTypeChar() == '4')
				m_sprite.setTextureRect(sf::IntRect(64, 0, 16, 16));

			m_sprite.setPosition(j * 16, i * 16);

			window->draw(m_sprite);
		}
}

void Map::SetTextures()
{
	m_texture.loadFromFile("Data/Textures/Map.png");
	m_sprite.setTexture(m_texture);
}

Map::Map()
{

}

Map::Map(const int width, const int height)
{
	width_ = width;
	height_ = height;
}

Map::~Map()
{

}

void Map::Load(const std::string path)
{
	std::vector<std::string> strings = LoadFile(path);

	std::vector<std::string> dimensions = SplitString(strings.at(0), ',');
	strings.erase(strings.begin());
	int width = atoi(dimensions.at(0).c_str());
	int height = atoi(dimensions.at(1).c_str());

	map_ = Map(width, height);

	for (auto i = 0; i < strings.size(); i++)
	{
		std::vector<Tile> vector;
		for (auto j = 0; j < strings.at(i).size(); ++j)
			vector.push_back(Tile(j, i, strings.at(i).at(j)));
		map_.tiles_.push_back(vector);
	}
}

Map* Map::GetMap()
{
	return &map_;
}

Tile* Map::GetTile(const short x, const short y) const
{
	return &map_.tiles_.at(y).at(x);
}

Tile* Map::GetTile(const sf::Vector2f coordinates) const
{
	return &map_.tiles_.at(coordinates.y).at(coordinates.x);
}

int Map::GetWidth() const
{
	return width_;
}

int Map::GetHeight() const
{
	return height_;
}