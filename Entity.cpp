#include "Entity.h"   

void Entity::InitVariables()
{
	this->movementComponent = NULL;
}

Entity::Entity()
{
	this->InitVariables();
}

Entity::~Entity()
{
	delete this->hitboxComponent;
	delete this->movementComponent;
	delete this->animationComponent;
}


/*functions*/


void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);

}

void Entity::createHitboxComponent(sf::Sprite& sprite, float offX, float offY, float width, float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, offX, offY, width, height);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
} 

void Entity::move(const float dir_x, const float dir_y, const float& dt)
{
	if (this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y, dt); //sets velocity
	}
}

//character movement
void Entity::update(const float& dt)
{
	if (this->movementComponent)
		this->movementComponent->update(dt);
}

void Entity::render(sf::RenderTarget& target)
{
		target.draw(this->sprite);

		if (this->hitboxComponent)
			this->hitboxComponent->render(target);

}
