#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

// defined libs
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <map>

//sfml libs
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

enum movingState {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN};
				//   0          1              2          3              4
class MovementComponent
{

private:
	sf::Sprite& sprite;
		
	float maxVelocity;
	sf::Vector2f velocity;
	float acceleration;
	float deceleration;

	//Initlizer functions

public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
	virtual ~MovementComponent();

	//accessors
	const sf::Vector2f& getVelocity() const;

	// std::map<std::string, bool> state;

	const bool getState(const short unsigned state) const;

	const bool idle() const;
	const bool movingLeft() const;
	const bool movingRight() const;
	const bool moving() const;

	//functions
	void move(const float dir_x, const float dir_y, const float& dt);
	void update(const float &dt);


};

#endif // !1