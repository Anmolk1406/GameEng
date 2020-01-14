#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"



class Player :
	public Entity
{
private:
	//variables


	//intializer functions
	void InitVariables();
	void InitComponents();


public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();




	//functions

	virtual void update(const float& dt);
};

#endif // !PLAYER_H
