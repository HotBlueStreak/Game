#pragma once

#include "../Window/GameWindow.h"
#include "../Event Manager/EventManager.h"
#include "../Entities/Player.h"
#include "../Entities/Items.h"
#include "../Map/Map.h"
#include "../Entities/World.h"
#include "../Utilities/random.h"


class Game : private sf::NonCopyable
{
public:
	Game(int x = 800, int y = 600);
	~Game();

	GameWindow* GetWindow();

	void Run(int minimum_frame_per_seconds = 30);

private:
	void ProcessEvents();
	void Update(sf::Time deltaTime);
	void Render();

	void Reset();

	GameWindow m_window;
	World m_world;
};

//class Game : private sf::NonCopyable
//{
//public:
//	Game();
//	~Game();
//	
//	void Run(int minimum_frame_per_seconds = 30);
//	
//	GameWindow* GetWindow();
//
//	sf::Time GetElapsed();
//	void RestartClock();
//
//private:
//	void HandleInput();
//	void Update(sf::Time delta_time);
//	void Render();
//
//private:
//	GameWindow m_window;
//	World m_world;
//	sf::Clock m_timer;
//	sf::Clock m_clock;
//	sf::Time m_elapsed;
//};