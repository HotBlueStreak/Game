#pragma once

#include "../Resource Manager/ResourceHolder.h"
#include "../Resource Manager/ResourceIdentifiers.h"
#include "../Event Manager/EventManager.h"
#include "View.h"

class Player : public sf::Drawable
{
public:
	Player();

	void SetPosition(sf::Vector2f position);
	void SetPosition(float x, float y);

	sf::Vector2f GetPosition();

	void LoadTextures();
	sf::Sprite GetSprite();

	void Update(sf::Time delta_time);
	void Movement(sf::Time delta_time);
	void ProcessEvents();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
	short direction, speed;
	sf::Vector2f delta;

	TextureHolder m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_position;

	EventManager m_event_manager;
};