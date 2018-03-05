#include "Map.h"

Map Map::m_map;

Map::Map()
{
}

Map::Map(const int width, const int height)
{
	m_width = width;
	m_height = height;
}

Map::~Map()
{

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

void Map::Load(const std::string path)
{
	std::vector<std::string> strings = LoadFile(path);

	std::vector<std::string> dimensions = SplitString(strings.at(0), ',');
	strings.erase(strings.begin());
	int width = atoi(dimensions.at(0).c_str());
	int height = atoi(dimensions.at(1).c_str());

	m_map = Map(width, height);

	for (auto i = 0; i < strings.size(); i++)
	{
		std::vector<Tile> vector;
		for (auto j = 0; j < strings.at(i).size(); ++j)
			vector.push_back(Tile(j, i, strings.at(i).at(j)));
		m_map.m_tiles.push_back(vector);
	}
}

void Map::SetTextures()
{
	m_sprite.setTexture(Configuration::textures.Get(Configuration::Textures::Map));
}

void Map::MapRenderer(sf::RenderWindow* window)
{
	m_count_elements = 0;

	for (int i = 0; i < m_height; i++)
		for (int j = 0; j < m_width; j++)
		{
			if (GetTile(j, i)->GetType() == TileType::Ground)
				m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));

			if (GetTile(j, i)->GetType() == TileType::Stone)
				m_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));

			if (GetTile(j, i)->GetType() == TileType::Sandstone)
				m_sprite.setTextureRect(sf::IntRect(32, 0, 16, 16));

			if (GetTile(j, i)->GetType() == TileType::Flower)
			{
				m_sprite.setTextureRect(sf::IntRect(48, 0, 16, 16));
				m_count_elements++;
			}

			if (GetTile(j, i)->GetType() == TileType::Heart)
			{
				m_sprite.setTextureRect(sf::IntRect(64, 0, 16, 16));
				m_count_elements++;
			}

			m_sprite.setPosition(j * 16, i * 16);

			window->draw(m_sprite);
		}
}

void Map::RandomMapGenerate()
{
	sf::Vector2i rand_pos_element;
	int rand_type_element;
	srand(time(0));

	if (m_count_elements < 5)
	{
		rand_pos_element.x = 1 + rand() % (m_width - 1);
		rand_pos_element.y = 1 + rand() % (m_height - 1);
		
		rand_type_element = rand() % 2;

		if (GetTile(rand_pos_element)->GetType() == TileType::Ground)
		{
			switch (rand_type_element)
			{
			case(0):
				GetTile(rand_pos_element)->SetType(TileType::Flower);
				break;
			case(1):
				GetTile(rand_pos_element)->SetType(TileType::Heart);
				break;
			}

			m_count_elements++;
		}
	}
}

Map* Map::GetMap()
{
	return &m_map;
}

Tile* Map::GetTile(const short x, const short y) const
{
	return &m_map.m_tiles.at(y).at(x);
}

Tile* Map::GetTile(const sf::Vector2i coordinates) const
{
	return &m_map.m_tiles.at(coordinates.y).at(coordinates.x);
}

int Map::GetWidth() const
{
	return m_width;
}

int Map::GetHeight() const
{
	return m_height;
}