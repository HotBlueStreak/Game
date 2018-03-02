#pragma once 

#include <fstream>
#include <sstream>

#include "../Window/GameWindow.h"
#include "../Resource Manager/ResourceHolder.h"
#include "../Resource Manager/ResourceIdentifiers.h"

class Map : public sf::Drawable
{
public:
	void Load(const std::string path);
	void Save(const std::string path);

	void InitMap(const int width, const int height);

	void MapRenderer(sf::RenderWindow* window);

	int GetWidth() const;
	int GetHeight() const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	int m_width;
	int m_height;

	TextureHolder m_texture;
	sf::Sprite m_sprite;

	std::vector<std::string> m_map;

};