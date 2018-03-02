#include "Map.h"

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

void Map::InitMap(const int width, const int height)
{
	m_width = width;
	m_height = height;
	m_map.reserve(height);

	m_texture.Load(Textures::Map, "Data/Textures/Map.png");
	m_sprite.setTexture(m_texture.Get(Textures::Map));
}

void Map::Load(const std::string path)
{
	std::vector<std::string> strings = LoadFile(path);

	std::vector<std::string> dimensions = SplitString(strings.at(0), ',');
	strings.erase(strings.begin());
	int width = atoi(dimensions.at(0).c_str());
	int height = atoi(dimensions.at(1).c_str());

	InitMap(width, height);

	for (auto i = 0; i < strings.size(); i++)
	{
		m_map.push_back(strings.at(i));
	}
}

void Map::Save(const std::string path)
{
	std::ofstream file(path);

	std::ostringstream oss;
	oss << m_width << ',' << m_height << "\n";
	file << oss.str();

	for (auto i = 0; i < m_map.size(); ++i)
	{
		file << m_map.at(i) << "\n";
	}
}

void Map::MapRenderer(sf::RenderWindow* window)
{
	for (auto i = 0; i < m_height; i++)
		for (auto j = 0; j < m_width; j++)
		{
			if (m_map.at(i).at(j) == '0')
				m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

			if (m_map.at(i).at(j) == '1')
				m_sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));

			if (m_map.at(i).at(j) == '2')
				m_sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));

			m_sprite.setPosition(j * 32, i * 32);
		
			window->draw(m_sprite);
		}
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}

int Map::GetWidth() const
{
	return m_width;
}

int Map::GetHeight() const
{
	return m_height;
}
