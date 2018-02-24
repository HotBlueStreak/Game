#include "GameWindow.h"

GameWindow::GameWindow()
{
	Setup("Window", sf::Vector2u(640, 480));
}

GameWindow::GameWindow(const std::string& l_title, const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
}

GameWindow::~GameWindow()
{
	Destroy();
}

void GameWindow::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_window_title = l_title;
	m_window_size = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	m_isFocused = true;

	m_event_manager.AddCallback("Fullscreen_toggle", &GameWindow::ToggleFullscreen, this);
	m_event_manager.AddCallback("Window_close", &GameWindow::Close, this);

	Create();
}

void GameWindow::Create()
{
	auto style = m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;

	m_window.create({m_window_size.x, m_window_size.y, 32}, m_window_title, style);
}

void GameWindow::Destroy()
{
	m_window.close();
}

void GameWindow::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::LostFocus)
		{
			m_isFocused = false;
			m_event_manager.SetFocus(false);
		}
		else
			if (event.type == sf::Event::GainedFocus)
			{
				m_isFocused = true;
				m_event_manager.SetFocus(true);
			}
		m_event_manager.HandleEvent(event);
	}
	m_event_manager.Update();
}

void GameWindow::ToggleFullscreen(EventDetails* l_details)
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void GameWindow::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}

void GameWindow::EndDraw()
{
	m_window.display();
}

bool GameWindow::IsDone()
{
	return m_isDone;
}

bool GameWindow::isFocused()
{
	return m_isFocused;
}

bool GameWindow::IsFullScreen()
{
	return m_isFullscreen;
}

sf::RenderWindow* GameWindow::GetRenderWindow()
{
	return &m_window;
}

EventManager* GameWindow::GetEventManager() 
{ 
	return &m_event_manager; 
}

sf::Vector2u GameWindow::GetWindowSize()
{
	return m_window_size;
}

void GameWindow::Draw(sf::Drawable& l_drawable)
{
	m_window.draw(l_drawable);
}

void GameWindow::Close(EventDetails* l_details)
{
	m_isDone = true;
}