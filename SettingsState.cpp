#include "SettingsState.h"

SettingsState::SettingsState(sf::RenderWindow* window, std::map < std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->Background();

	this->InitVariables();

	this->InitFonts();

	this->InitKeyBinds();

	this->InitButton();
}

void SettingsState::InitVariables()
{

}

void SettingsState::Background()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));

	if (!this->bgTexture.loadFromFile("Resources/Images//Backgrounds/bg_2.png"))
	{
		throw "ERROR::MAINMENUSTATE::FALIED_TO_LOAD_BACKGROUND_TEXTURE_MAINMENUSTATE";

	}
	this->background.setTexture(&this->bgTexture); /*texturing the main menu background*/
}

void SettingsState::InitFonts()
{
	if (!this->font.loadFromFile("Fonts/fonts.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void SettingsState::InitKeyBinds()
{
	std::ifstream ifs("Config/mainMainStateKeyBinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
		{
			this->keyBinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void SettingsState::InitButton()
{

	this->buttons["QUIT_STATE"] = new gui::Button(
		200, 600,
		150, 100, &this->font, "Quit", 30,
		sf::Color(250, 250, 250, 250), sf::Color(150, 150, 150, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

}


SettingsState::~SettingsState()
{

}


void SettingsState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//quit the game
	if (this->buttons["QUIT_STATE"]->isPressed())
	{
		this->quit = true;
	}

}

void SettingsState::updateInput(const float& dt)
{

}

void SettingsState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);


	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";

	this->updateButtons();



}

void SettingsState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}

	target->draw(this->background);

	this->renderButtons(*target);


	/*will remove later*/

	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(20);
	std::stringstream ss; //lol
	ss << "x: " << this->mousePosView.x << ", y: " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);

}