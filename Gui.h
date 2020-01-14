#ifndef GUI_H
#define GUI_H

// defined libs
#include <iostream>
#include <ctime>
#include <cstdlib>	
#include <sstream>
#include <vector>

//sfml libs
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

enum buttonState { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

namespace gui 
{

	class Button
	{
	private:
		short unsigned buttonState;

		sf::RectangleShape button;
		sf::Font* font;
		sf::Text text;

		sf::Texture btnTexture;

		sf::Color textIdleColor;
		sf::Color textHoverColor;
		sf::Color textActiveColor;


		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;



	public:
		Button(float x, float y, float width, float height,
			sf::Font* font, std::string text, unsigned char_size,
			sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
			sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
		~Button();

		/*Accesors*/
		const bool isPressed() const;
		const std::string getText() const;

		//Modifiers
		void setText(const std::string text);

		//functions
		void background();
		void update(const sf::Vector2f& mousePos);
		void render(sf::RenderTarget& target);
	};

	class DropDownList {
	private:
		float keyTime;
		float keyTimeMax;
		sf::Font& font;
		gui::Button* activeElem;
		std::vector <gui::Button*> list;
		bool showList;



	public:
		DropDownList(sf::Font& font, std::string list[], unsigned nrOfElems, const unsigned default_index = 0);
		~DropDownList();



		//Functions
		const bool getKeyTime();
		void updateKeyTime(const float& dt);
		void update(const sf::Vector2f& mousePos, const float& dt);
		void render(sf::RenderTarget& target);
	};

}


#endif // !BUTTON_H
