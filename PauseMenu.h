#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <map>

#include "Gui.h"

//sfml libs
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

class PauseMenu
{
private:
	sf::Font& font;
	sf::Text menuText;


	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, gui::Button*> buttons;

	//private functions

protected:


public:

	PauseMenu(sf::RenderWindow& window, sf::Font& font);
	virtual ~PauseMenu();

	//accessor
	std::map<std::string, gui::Button*>& getButtons();

	//Function
	const bool isButtonPressed(const std::string key);
	void addButtons(const std::string key,float y, const std::string text);	
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);

};

#endif