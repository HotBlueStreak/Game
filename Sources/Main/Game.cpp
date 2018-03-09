#include "Game.h"

Game::Game(int x, int y) : m_window("Game", sf::Vector2u(x, y)), m_world(x, y)
{
	Reset();
}

Game::~Game()
{
}

GameWindow* Game::GetWindow()
{
	return &m_window;
}

void Game::Run(int minimum_frame_per_seconds)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time TimePerFrame = sf::seconds(1.f / minimum_frame_per_seconds);

	while (!GetWindow()->IsDone())
	{
		ProcessEvents();
		
		timeSinceLastUpdate = clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			Update(TimePerFrame);
		}

		Update(timeSinceLastUpdate);
		Render();
	}
}

void Game::ProcessEvents()
{
}

void Game::Update(sf::Time deltaTime)
{

	if (not Configuration::isGameOver())
	{
		m_window.Update();
		m_world.Update(deltaTime);
		if (Configuration::player == nullptr)
		{
			Configuration::player = new Player(m_world);
			Configuration::player->SetPosition(50, 50);
			m_world.Add(Configuration::player);
		}

		if (Configuration::player2 == nullptr)
		{
			Configuration::player2 = new Player(m_world);
			Configuration::player2->SetPosition(500, 50);
			m_world.Add(Configuration::player2);
		}

		if (Configuration::map_f == nullptr)
		{
			Configuration::map_f = new Map(Configuration::Textures::Mape, "Sources/Configurations/map.txt");
		}
	}
}

void Game::Render()
{
	m_window.BeginDraw();
	if (not Configuration::isGameOver())
	{
		//Configuration::map_f->ShowCollisionMap(m_window.GetRenderWindow());
		//m_window.Draw(*Configuration::map_f);
		m_window.Draw(m_world);
	}
	m_window.EndDraw();
}

void Game::Reset()
{
	m_world.Clear();
	Configuration::player = nullptr;
	Configuration::player2 = nullptr;
	Configuration::Reset();
}

//Game::Game() : m_window("Game", sf::Vector2u(800, 600)), m_world(800, 600)
//{
//	m_world.Clear();
//	Configuration::player = nullptr;
//	Configuration::player2 = nullptr;
//
//}
//
//Game::~Game()
//{
//
//}
//
//void Game::Run(int minimum_frame_per_seconds)
//{
//	sf::Clock clock;
//	sf::Time time_since_last_update = sf::Time::Zero;
//	sf::Time time_per_frame = sf::seconds(1.f / minimum_frame_per_seconds);
//
//	while(!GetWindow()->IsDone())
//	{
//		HandleInput();
//
//		bool repaint = false;
//		time_since_last_update = clock.restart();
//
//		while (time_since_last_update > time_per_frame)
//		{
//			time_since_last_update -= time_per_frame;
//			Update(time_per_frame);
//		}
//
//		Update(time_per_frame);
//		Render();
//	}
//}
//
//void Game::HandleInput()
//{
//}
//
//void Game::Update(sf::Time delta_time)
//{
//	m_window.Update();
//
//	if (Configuration::map_f == nullptr)
//	{
//		Configuration::map_f = new Map(Configuration::Textures::Mape, "Sources/Configurations/map.txt");
//	}
//
//	if (Configuration::player == nullptr)
//	{
//		Configuration::player = new Player(m_world);
//		Configuration::player->SetPosition(50, 50);
//		m_world.Add(Configuration::player);
//
//
//		Item* health = new Health(m_world);
//		health->SetPosition(100, 100);
//
//		m_world.Add(health);
//	}
//
//	if (Configuration::player2 == nullptr)
//	{
//		Configuration::player2 = new Player(m_world);
//		Configuration::player2->SetPosition(500, 50);
//		m_world.Add(Configuration::player2);
//	}
//	m_world.Update(delta_time);
//
//	float time = m_timer.getElapsedTime().asMilliseconds();
//}
//
//void Game::Render()
//{
//	m_window.BeginDraw();
//	Configuration::map_f->ShowCollisionMap(m_window.GetRenderWindow());
//	//m_window.Draw(*Configuration::map_f);
//	m_window.Draw(m_world);
//	m_window.EndDraw();
//}
//
//GameWindow* Game::GetWindow()
//{
//	return &m_window;
//}
//
//sf::Time Game::GetElapsed()
//{
//	return m_elapsed;
//}
//
//void Game::RestartClock()
//{
//	float frame_time = m_clock.getElapsedTime().asSeconds();
//	m_clock.restart();
//
//	m_elapsed = sf::seconds(frame_time);
//}