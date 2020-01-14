#include "GameState.h"

/* Initializer Functions*/
void GameState::InitKeyBinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

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

void GameState::InitTexture()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/Player/PlayerSheet.png"))
	{
		throw"ERROR::GAME_STATE::COULD_NOT_LOAD_TEXTURE_FILE";
		std::cout << "error:: could not load textures" << std::endl;
	}

}

void GameState::InitPlayer()
{
	this->player = new Player(0, 0, this->textures["PLAYER_SHEET"]);
}

void GameState::InitFonts()
{
	if (!this->font.loadFromFile("Fonts/fonts.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void GameState::InitpauseMenu()
{
	this->p_Menu = new PauseMenu(*this->window, this->font);
	this->p_Menu->addButtons("QUIT", 200.f, "Quit");
}

GameState::GameState(sf::RenderWindow* window, std::map < std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->InitKeyBinds();
	this->InitTexture();
	this->InitPlayer();
	this->InitpauseMenu();
	this->InitFonts();
}

GameState::~GameState()
{
	delete this->p_Menu;
	delete this->player;
}

void GameState::updatePlayerInput(const float& dt)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT")))) 
	{ this->player->move(-1.f, 0.f, dt); }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
	{ this->player->move(1.f, 0.f, dt); }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
	{ this->player->move(0.f, 1.f, dt); }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
	{ this->player->move(0.f, -1.f, dt); }


}



void GameState::update(const float& dt)
{

	this->updateMousePosition();
	this->updateInput(dt);
	this->updateKeyTime(dt);

	if (!this->pause) // game unpaused
	{
		this->updatePlayerInput(dt);
		this->player->update(dt);
	}
	else if(this->pause) // game paused
	{ 
		this->p_Menu->update(this->mousePosView);
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
	 	target = this->window;
	}

	this->player->render(*target);


	if (this->pause)
	{
		this->p_Menu->render(*target);
	}

	/*will remove later

	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(20);
	std::stringstream ss; //lol
	ss << "x: " << this->mousePosView.x << ", y: " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText); */
}

void GameState::updateInput(const float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("CLOSE"))) && this->getKeyTime())
	{
		if (this->pause == false)
			this->pauseState();
		else
			this->unPausedState();
	}
}

void GameState::updateButtons()
{
	if (this->p_Menu->isButtonPressed("QUIT"))
	{
		this->quit = true;
	}
}
