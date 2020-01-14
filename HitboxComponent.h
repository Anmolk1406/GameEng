#ifndef HITBOXCOMPONENT_H
#define HITBOXCOMPONENT_H


// defined libs
#include <iostream>
#include <ctime>
#include <cstdlib>


//sfml libs
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"



class HitboxComponent
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitBox;
	float offsetX, offsetY;

public:
	HitboxComponent(sf::Sprite& sprite, float offX, float offY, float width, float height); // oof
	virtual ~HitboxComponent();

	//Functions

	bool checkIntercept(const sf::FloatRect& frect);
	void update();
	void render(sf::RenderTarget& target);
};

#endif // !HITBOXCOMPONENT_H