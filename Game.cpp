#include "Game.h"

//static functions


//Initializer functions

void Game::InitVariables()
{
	this->window = NULL;
	this->fullScreen = false;
	this->dt = 0.f;
}

void Game::InitWindow()
{
	// creates a window using options from a "windows.ini" file .
	// like set resultion, frames per seconds and stuff

	std::ifstream ifs("Config/window.ini");
	this->videModes = sf::VideoMode::getFullscreenModes();
	std::string title = "None";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	// window_bounds.bitsPerPixel; later homo
	bool fullScreen = false;
	unsigned frameRateLimit = 120;
	bool verticalSyncEnabled = false;
	unsigned antiAliasignLevel = 0;

	if (ifs.is_open())  ///checking if window.ini exists
	{
		//reading values from window.ini
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullScreen;
		ifs >> frameRateLimit;
		ifs >> verticalSyncEnabled;
		ifs >> antiAliasignLevel;
	}

	ifs.close();


	this->fullScreen = fullScreen;
	this->windowSettings.antialiasingLevel = antiAliasignLevel; //i can't make good variables names for shit lmao.
	
	if(this->fullScreen)
	this->window = new sf::RenderWindow(window_bounds, title,sf::Style::Fullscreen, windowSettings);
	
	else
	{
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Close | sf::Style::Titlebar, windowSettings);
	}

	this->window->setFramerateLimit(frameRateLimit);
	this->window->setVerticalSyncEnabled(verticalSyncEnabled);
	
}

void Game::InitKeys()
{
	std::ifstream ifs("Config/supported_keys.ini");

	if (ifs.is_open()) 
	{
		std::string key = "";
		int keyValue = 0;
		while (ifs >> key >> keyValue)
		{
			this->supportedKeys[key] = keyValue; 
		}
	}

	ifs.close();


	//debug
	for (auto i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << "\n";
	}

}

void Game::InitStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

//constructor/destrcutors

Game::Game()
{

	/**this is a constructor and will be called as the program is launched
	means this contents of function "InitWindows will be executed. "**/

	this->InitWindow();
	this->InitKeys();
	this->InitStates();
}


Game::~Game()
{
	delete this->window;

	while (!this->states.empty()) { delete this->states.top(); this->states.pop(); }
}

//funtions...


void Game::endApplications()
{
	std::cout << "Ending Application" << std::endl;
}

void Game::updateDt()
{

	//updates the dt variable with the time it takes to update one frame.
	this->dt = this->dtClock.restart().asSeconds();

	std::cout << this->dt << std::endl;

}

void Game::updateSFMLEvents()
{

		//events
		while (this->window->pollEvent(this->sfEvent)) {
			if (this->sfEvent.type == sf::Event::Closed) { this->window->close(); }
		}

		//events ends here

}

void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->dt); //overloading hai state.h wale update(); pe jaega ye xd
	
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	
	}


	//Application end
	else
	{
		this->endApplications();
		this->window->close();
	}
}

void Game::render()
{
	//rendering
	this->window->clear();


	if(!this->states.empty())
		this->states.top()->render();


	this->window->display();
	//rendering ends here
}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
