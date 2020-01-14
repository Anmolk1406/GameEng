#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include<iostream>
#include<string>
#include <map>

//sfml libs
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"


class AnimationComponent
{ 
private:
	class Animation

	{
	public:
		//variables
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animationTimer, timer; 
		int width, height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float animationTimer, 
			int startFrameX, int startFrameY, int framesX, int framesY, int width, int height) 
			:sprite(sprite), textureSheet(textureSheet),
			animationTimer(animationTimer), width(width), height(height)
		{
			this->timer = 0.f;
			this->startRect = sf::IntRect(startFrameX * width, startFrameY * height, width, height);
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(framesX * width, framesY * height, width, height);
		
			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
		}



		//functions
		void play(const float& dt)
		{
			//update timer;
			this->timer += 40.f * dt;
			if (this->timer >= this->animationTimer)
			{
		    		//reset timer;
				this->timer = 0.f;

				if (this->currentRect != this->endRect)
				{
					this->currentRect.left += this->width;

				}
				else //reset
				{
					this->currentRect.left = this->startRect.left;
				}
				this->sprite.setTextureRect(this->currentRect);

			}
		}

		void reset()
		{
			this->timer = this->animationTimer;
			this->currentRect = this->startRect;
		}

	};

	sf::Sprite& sprite;
	sf::Texture& texture_sheet;
	std::map<std::string, Animation*> animations;
	
public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	virtual ~AnimationComponent();

	//Functions
	void addAnimation(const std::string key, float animationTimer,
		int startFrameX, int startFrameY, int framesX, int framesY, int width, int height);

	void play(const std::string key, const float& dt);

	

	
};

#endif // !ANIMATIONCOMPONENT_H
