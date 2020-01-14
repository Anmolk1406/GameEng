#include "Gui.h"


void gui::Button::background()
{
	this->button.setSize(sf::Vector2f(static_cast<float>(this->button.getSize().x),
		static_cast<float>(this->button.getSize().y)));

	if (!this->btnTexture.loadFromFile("Resources/Images//Backgrounds/btn.jpg"))
	{
		throw "ERROR::MAINMENUSTATE::FALIED_TO_LOAD_BACKGROUND_TEXTURE_MAINMENUSTATE";

	}
	this->button.setTexture(&this->btnTexture); 
}

gui::Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned char_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDLE;

	this->textIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;


	this->button.setPosition(sf::Vector2f(x,y));
	this->button.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(textIdleColor);
	this->text.setCharacterSize(char_size);
	this->text.setPosition(
		this->button.getPosition().x + (this->button.getGlobalBounds().width) / 2.f - this->text.getGlobalBounds().width / 2.f,
		this->button.getPosition().y + (this->button.getGlobalBounds().height) / 2.f - this->text.getGlobalBounds().height / 2.f
	);

	
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->button.setFillColor(this->idleColor);


		/*this->button.setSize(sf::Vector2f(static_cast<float>(this->button.getSize().x),
			static_cast<float>(this->button.getSize().y)));

		if (!this->btnTexture.loadFromFile("Resources/Images//Backgrounds/btn.jpg"))
		{
			throw "ERROR::MAINMENUSTATE::FALIED_TO_LOAD_BACKGROUND_TEXTURE_MAINMENUSTATE";

		}*/

}

gui::Button::~Button()
{
}



// Accessors ||
const bool gui::Button::isPressed() const
{
	if(this->buttonState == BTN_ACTIVE)	
		return true;
	
	else
		return false;
}

const std::string gui::Button::getText() const
{
	return this->text.getString();
}


// ends here || Modifiers Start


void gui::Button::setText(const std::string text)
{
	this->text.setString(text);
}




/*functions*/



void gui::Button::update(const sf::Vector2f& mousePos)
{
	/*update the bools for hovers and clicks*/
	this->buttonState = BTN_IDLE;


	/*hover*/
	if (this->button.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;
		
		//Pressed//
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
			std::cout << "Left clicked on a button of same stack" << "\n";
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->button.setFillColor(idleColor);
		this->text.setFillColor(this->textIdleColor);

		break;
	case BTN_HOVER:
	
		this->button.setFillColor(hoverColor);
		this->text.setFillColor(this->textHoverColor);

		break;
	case BTN_ACTIVE:
		this->button.setFillColor(activeColor);
		this->text.setFillColor(this->textActiveColor);
		break;
	default:
		this->button.setFillColor(sf::Color::Red);
		this->button.setFillColor(sf::Color::Blue);
		break;

	}

}

void gui::Button::render(sf::RenderTarget& target)
{
	target.draw(this->button);

	target.draw(this->text);
}


//Drop Down List;


gui::DropDownList::DropDownList(sf::Font& font, std::string list[], unsigned nrOfElems, const unsigned default_index)
	: font(font), showList(false)
{ 
	//unsigned nrOfElems = sizeof(list) / sizeof(std::string);

	for (size_t i = 0; i < nrOfElems; i++)
	{
		this->list.push_back = new gui::Button(
			200, 200,
			150, 100, //x and y size 
			&this->font, list[i], 30,
			sf::Color(250, 250, 250, 250), sf::Color(250, 250, 250, 350), sf::Color(20, 20, 20, 50),
			sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
		);
	}


	this->activeElem = new Button(*this->list[default_index]); 
}

gui::DropDownList::~DropDownList()
{
	delete this->activeElem;
	for (auto *&i : this->list)
	{
		delete i;
	}
}


// Accessors
const bool gui::DropDownList::getKeyTime()
{
	if (this->keyTime >= keyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}
	
	return false;

}

// Functions // 
void gui::DropDownList::updateKeyTime(const float& dt)
{
	if (this->keyTime < this->keyTimeMax)
	{
		this->keyTime += 10.f * dt;
	}
}

void gui::DropDownList::update(const sf::Vector2f& mousePos, const float& dt)
{
	this->activeElem->update(mousePos);

	if (this->activeElem->isPressed())
	{
		if (this->showList)
			this->showList = false;

		else
			this->showList = true;
	}

	if (this->showList)
	{
		for (auto& i : this->list)
		{
			i->update(mousePos);

		}
	}


	
}

void gui::DropDownList::render(sf::RenderTarget& target)
{
	this->activeElem->render(target);


	if (this->showList)
	{
		for (auto& i : this->list)
		{
			i->render(target);
		}
	}
}
