#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"


class Game
{

private:
	//variables
	sf::RenderWindow *window; //creating window a pointer for dynamic uses!
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videModes;
	sf::ContextSettings windowSettings;
	
	bool fullScreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;


	//Initialization
	void InitVariables();
	void InitWindow(); //initialization window
	void InitStates();
	void InitKeys();


public:
	
	// constructor/destructor things
	Game();
	virtual ~Game();



	//functions

	//regular funcs.
	void endApplications();

	void updateDt();
	void updateSFMLEvents();
	void update();

	//render
	void render();



	//core
	void run();



};


#endif