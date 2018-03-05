#pragma once

#include "../Resource Manager/ResourceHolder.h"
#include "../Utilities/random.h"

class Player;
class Configuration
{
public:
	enum Textures : int 
	{
		PlayerRed,
		PlayerBlue,
		Map,
		Health,
		Weapons
	};
	static ResourceHolder<sf::Texture, int> textures;

	enum Fonts : int 
	{ 
		Gui 
	};
	static ResourceHolder<sf::Font, int> fonts;

	enum PlayerInputs : int 
	{
		Up,
		Down,
		Left,
		Right,
		Shoot
	};

	enum Sounds : int 
	{
	};
	static ResourceHolder<sf::SoundBuffer, int> sounds;

	enum Musics : int 
	{
	};
	static ResourceHolder<sf::Music, int> musics;

	static void initialize();

	static Player* player;
	static Player* player2;

	static void draw(sf::RenderTarget& target);

private:
	static int _score;
	static sf::Text   _txt_score;
	static sf::Sprite _spr_life;

	static void initTextures();
	static void initFonts();
	static void initSounds();
	static void initMusics();
};