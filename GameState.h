#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "PauseMenu.h"


class GameState:
	public State
{
private:
	sf::Font font;
	PauseMenu* p_Menu;
	Player* player;
	
	//
	
	//funcs
	void InitKeyBinds();
	void InitTexture();
	void InitpauseMenu();
	void InitPlayer();
	void InitFonts();

public:
	GameState(sf::RenderWindow* window, std::map < std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();


	//functions
	void updatePlayerInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
	void updateInput(const float& dt);
	void updateButtons();
};

#endif