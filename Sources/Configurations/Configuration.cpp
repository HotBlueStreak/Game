#include "Configuration.h"

ResourceHolder<sf::Texture, int> Configuration::textures;
ResourceHolder<sf::Font, int> Configuration::fonts;
ResourceHolder<sf::SoundBuffer, int> Configuration::sounds;
ResourceHolder<sf::Music, int> Configuration::musics;

Player* Configuration::player = nullptr;
Player* Configuration::player2 = nullptr;
Map* Configuration::map_f = nullptr;

sf::Time Configuration::round_time;

void Configuration::initialize()
{
	initTextures();
	initFonts();
	initSounds();
	initMusics();
	
	RandomInit();

	round_time = sf::seconds(-1);
}

void Configuration::draw(sf::RenderTarget& target)
{
}

void Configuration::initTextures()
{
	textures.Load(Textures::PlayerRed, "Data/Textures/PlayerRed.png");
	textures.Load(Textures::PlayerBlue, "Data/Textures/PlayerBlue.png");
	textures.Load(Textures::Mape, "Data/Textures/Map.png");
	textures.Load(Textures::Items, "Data/Textures/Items.png");
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

void Configuration::Reset()
{
	round_time = sf::seconds(120);
}

bool Configuration::isGameOver()
{
	return round_time <= sf::Time::Zero;
}