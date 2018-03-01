#pragma once

#include "../Window/GameWindow.h"

class View
{
public:
	void SetPlayerView(sf::Vector2f position);

private:
	sf::View m_view;
	sf::Vector2f m_position;

};