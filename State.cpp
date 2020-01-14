#include "State.h"

State::State(sf::RenderWindow* window, std::map < std::string, int>* supportedKeys, std::stack<State*>*states)
{
	this->window = window;
	this->quit = false;
	this->pause = false;
	this->supportedKeys = supportedKeys;
	this->states = states;
	this->keyTime = 0.f;
	this->keyTimeMax = 50.f;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	// TODO: insert return statement here

	return this->quit;
}

const bool State::getKeyTime()
{
	if (this->keyTime >= this->keyTimeMax)

	{
		this->keyTime = 0.f;
		return true;
	}

	return false;
}

void State::endState()
{
	this->quit = true;
}

void State::pauseState()
{
	this->pause = true;
}

void State::unPausedState()
{
	this->pause = false;
}

void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
void State::updateKeyTime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
	{
		this->keyTime += 50.f * dt; 
	}
}

