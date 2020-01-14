#include "HitboxComponent.h"


HitboxComponent::HitboxComponent
(sf::Sprite& sprite, float offX, float offY, float width, float height)
	:sprite(sprite), offsetX(offX), offsetY(offY)
	{
	this->hitBox.setPosition(this->sprite.getPosition().x + offX, this->sprite.getPosition().y + offY);
	this->hitBox.setSize(sf::Vector2f(width, height));
	this->hitBox.setFillColor(sf::Color::Transparent);
	this->hitBox.setOutlineThickness(1.f);
	this->hitBox.setOutlineColor(sf::Color::Blue);

	}

HitboxComponent::~HitboxComponent()
{
}

bool HitboxComponent::checkIntercept(const sf::FloatRect& frect)
{
	return this->hitBox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::update()
{
	this->hitBox.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);

}

void HitboxComponent::render(sf::RenderTarget& target)
{
	target.draw(this->hitBox);
}
