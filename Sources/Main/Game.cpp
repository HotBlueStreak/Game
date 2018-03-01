#include "Game.h"

Game::Game() : m_window("Game", sf::Vector2u(800, 600))
{
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
	m_player.Update(delta_time);
}

void Game::Render()
{
	m_window.BeginDraw();
	m_window.Draw(m_player);
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