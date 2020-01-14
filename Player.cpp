#include "Player.h"

//intializer functions
void Player::InitVariables()
{

}

void Player::InitComponents()
{
}

/*cons / destruc*/

Player::Player(float x, float y,sf::Texture& texture_sheet)
{
	this->InitVariables();


	this->setPosition(x, y);

	this->createHitboxComponent(this->sprite, 0.f, 0.f, 170, 230);
	this->createMovementComponent(400.f, 10.f, 4.f);
	this->createAnimationComponent(texture_sheet);
	this->animationComponent->addAnimation("IDLE_LEFT", 8.f, 0, 0, 5, 0, 170, 220);
	this->animationComponent->addAnimation("WALK_RIGHT", 8.f, 0, 1, 4, 0, 150, 220);

}

Player::~Player()
{

}

void Player::update(const float& dt)
{
		this->movementComponent->update(dt);

		if (this->movementComponent->getState(IDLE))
			this->animationComponent->play("IDLE_LEFT", dt);
		else if (this->movementComponent->getState(MOVING_LEFT))
			this->animationComponent->play("WALK_RIGHT", dt);
		/*if (this->movementComponent->getState(MOVING_RIGHT))
			this->animationComponent->play("WALK_RIGHT", dt);
		if (this->movementComponent->getState(MOVING_UP))
			this->animationComponent->play("WALK_UP", dt);
		if (this->movementComponent->getState(MOVING_DOWN))
			this->animationComponent->play("WALK_DOWN", dt); */

		this->hitboxComponent->update();


}
