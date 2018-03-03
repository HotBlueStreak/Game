#pragma once

#include "../Resource Manager/ResourceHolder.h"
#include "../Resource Manager/ResourceIdentifiers.h"
#include "../Event Manager/EventManager.h"
#include "../Map/Map.h"

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
	void InteractionWithMap();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
	short direction, speed, health;
	sf::Vector2f delta;
	bool life;

	TextureHolder m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	EventManager m_event_manager;
};