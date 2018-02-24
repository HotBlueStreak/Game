#include "Game.h"

Game::Game() : m_window("Game", sf::Vector2u(800, 600))
{
	LoadTextures();
	m_window.GetEventManager()->AddCallback("Move", &Game::Move, this);
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

void Game::Move(EventDetails* l_details)
{
	sf::Vector2i mouse_position = m_window.GetEventManager()->GetMousePosition(m_window.GetRenderWindow());
	m_sprite.setPosition(mouse_position.x, mouse_position.y);

	std::cout << "Moving sprite to: " << mouse_position.x << ":" << mouse_position.y << std::endl;
}

void Game::HandleInput()
{
}

void Game::LoadTextures()
{
	m_texture.Load(Textures::PlayerRed, "Data/Textures/PlayerRed.png");
	m_sprite.setTexture(m_texture.Get(Textures::PlayerRed));
}

void Game::Update(sf::Time delta_time)
{
	m_window.Update();
}

void Game::Render()
{
	m_window.BeginDraw();
	m_window.Draw(m_sprite);
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