#include "../Configurations/Configuration.h"
#include "Game.h"

int main()
{
	Configuration::initialize();

	Game game(800, 600);
	game.Run(60);

	return 0;
}