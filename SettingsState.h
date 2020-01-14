#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "State.h"
#include "Gui.h"

class SettingsState :
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
	SettingsState(sf::RenderWindow* window, std::map < std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~SettingsState();

	//functions
	void updateButtons();
	void updateInput(const float& dt);
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);

};

#endif // !SETTINGSSTATE_H

