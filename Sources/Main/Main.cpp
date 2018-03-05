#include "../Configurations/Configuration.h"
#include "Game.h"

int main()
{
	Configuration::initialize();

	Game game;
	game.Run();

	return 0;
}