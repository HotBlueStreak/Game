#pragma once

#include "../Window/GameWindow.h"
#include "../Event Manager/EventManager.h"
#include "../Resource Manager/ResourceHolder.h"
#include "../Resource Manager/ResourceIdentifiers.h"
#include "../Entities/Player.h"
#include "../Map/Map.h"


class Game : private sf::NonCopyable
{
public:
	Game();
	~Game();
	
	void Run(int minimum_frame_per_seconds = 30);
	
	GameWindow* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();

private:
	void HandleInput();
	void Update(sf::Time delta_time);
	void Render();

private:
	GameWindow m_window;

	Player m_player;
	
	sf::Clock m_clock;
	sf::Time m_elapsed;
};