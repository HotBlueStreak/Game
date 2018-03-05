#include "Game.h"

Game::Game() : m_window("Game", sf::Vector2u(800, 600)), m_world(800, 600)
{
	Map::GetMap()->Load("Sources/Configurations/map.txt");
	Map::GetMap()->SetTextures();
}

Game::~Game()
{

}

void Game::Run(int minimum_frame_per_seconds)
{
	sf::Clock clock;
	sf::Time time_since_last_update = sf::Time::Zero;
	sf::Time time_per_frame = sf::seconds(1.f / minimum_frame_per_seconds);

	while(!GetWindow()->IsDone())
	{
		HandleInput();

		bool repaint = false;
		time_since_last_update = clock.restart();

		while (time_since_last_update > time_per_frame)
		{
			time_since_last_update -= time_per_frame;
			Update(time_per_frame);
		}

		Update(time_per_frame);
		Render();
	}
}

void Game::HandleInput()
{
}

void Game::Update(sf::Time delta_time)
{
	m_window.Update();

	m_world.Update(delta_time);
	if (Configuration::player == nullptr)
	{
		Configuration::player = new Player(m_world, 17, 17);
		m_world.Add(Configuration::player);
	}

	float time = m_timer.getElapsedTime().asMilliseconds();

	if (time > 3000)
	{
		Map::GetMap()->RandomMapGenerate();
		m_timer.restart();
	}
	
}

void Game::Render()
{
	m_window.BeginDraw();
	Map::GetMap()->MapRenderer(m_window.GetRenderWindow());
	m_window.Draw(m_world);
	m_window.EndDraw();
}

GameWindow* Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	float frame_time = m_clock.getElapsedTime().asSeconds();
	m_clock.restart();

	m_elapsed = sf::seconds(frame_time);
}