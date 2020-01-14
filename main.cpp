#include "Game.h"


int main()
{
	sf::err().rdbuf(NULL); //ignoring any joysticks that may cause axis errors.

	Game game;

	game.run(); //running the game as soon the program is lauched.

	return 0;
}