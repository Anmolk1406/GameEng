#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
	: sprite(sprite), texture_sheet(texture_sheet)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : this->animations)
	{
		delete i.second;
	}
}

void AnimationComponent::addAnimation(const std::string key, float animationTimer,
	int startFrameX, int startFrameY, int framesX, int framesY, int width, int height)
{
	this->animations[key] = new Animation(this->sprite, this->texture_sheet, animationTimer,
		startFrameX, startFrameY,
		framesX, framesY,
		width, height
	);
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	this->animations[key]->play(dt);
}

