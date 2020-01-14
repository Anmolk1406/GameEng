#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H


#include "GameState.h"
#include "Gui.h"


class MainMenuState :
	public State
{
private:
	//variables
	sf::Texture bgTexture; //background Texture
	sf::RectangleShape background; //the main menu background.
	sf::Font font;
	
	std::map<std::string, gui::Button*>buttons;
	
	
	//funcs
	void InitVariables();
	void Background();
	void InitFonts();
	void InitKeyBinds();
	void InitButton();
public:
	MainMenuState(sf::RenderWindow* window, std::map < std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();


	//functions
	void updateButtons();
	void updateInput(const float& dt);
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif // !MAINMENUSTATE_H
