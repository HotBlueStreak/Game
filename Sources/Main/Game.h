#pragma once

#include "../Window/GameWindow.h"
#include "../Event Manager/EventManager.h"
#include "../Entities/Player.h"
#include "../Map/Map.h"
#include "../Entities/World.h"
#include "../Utilities/random.h"


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
	World m_world;
	sf::Clock m_timer;
	sf::Clock m_clock;
	sf::Time m_elapsed;
};