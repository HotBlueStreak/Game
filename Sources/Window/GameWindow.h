#pragma once

#include "../Event Manager/EventManager.h"

class GameWindow 
{
public:
	GameWindow();
	GameWindow(const std::string& l_title, const sf::Vector2u& l_size);
	~GameWindow();

	void BeginDraw();
	void EndDraw();

	void Update();
	
	bool IsDone();
	bool isFocused();
	bool IsFullScreen();
	sf::Vector2u GetWindowSize();

	void ToggleFullscreen(EventDetails* l_details);
	
	void Draw(sf::Drawable& l_drawable);

	sf::RenderWindow* GetRenderWindow();

	EventManager* GetEventManager();

	void Close(EventDetails* l_details = nullptr);

private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_window_size;
	std::string m_window_title;
	bool m_isDone;
	bool m_isFullscreen;
	bool m_isFocused;

	EventManager m_event_manager;
};