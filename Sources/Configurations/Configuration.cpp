#include "Configuration.h"

ResourceHolder<sf::Texture, int> Configuration::textures;
ResourceHolder<sf::Font, int> Configuration::fonts;
ResourceHolder<sf::SoundBuffer, int> Configuration::sounds;
ResourceHolder<sf::Music, int> Configuration::musics;

Player* Configuration::player = nullptr;
Player* Configuration::player2 = nullptr;

void Configuration::initialize()
{
	initTextures();
	initFonts();
	initSounds();
	initMusics();
	Random::RandomInit();
}

void Configuration::draw(sf::RenderTarget& target)
{
}

void Configuration::initTextures()
{
	textures.Load(Textures::PlayerRed, "Data/Textures/PlayerRed.png");
	textures.Load(Textures::PlayerBlue, "Data/Textures/PlayerBlue.png");
	textures.Load(Textures::Map, "Data/Textures/Map.png");
	textures.Load(Textures::Health, "Data/Textures/Health.png");
	textures.Load(Textures::Weapons, "Data/Textures/Weapons.png");
}

void Configuration::initFonts()
{
}

void Configuration::initSounds()
{
}

void Configuration::initMusics()
{
}