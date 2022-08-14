#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

enum button_states { BTN_IDLE = 0, BTN_HOVER = 1, BTN_ACTIVE_L = 2, BTN_ACTIVE_R = 3 };
//class Button {
//public:
//	Button() { }
//
//	Button(string t, sf::Vector2f size, int charsize, sf::Color bgColor, sf::Color textcolor) {
//		text.setString(t);
//		//text.setColor(textcolor);
//		text.setCharacterSize(charsize);
//		text.setFillColor(textcolor);
//		
//		button.setSize(size);
//		button.setFillColor(bgColor);
//		
//
//	}
//
//	void setFont(sf::Font& font) {
//		text.setFont(font);
//	}
//
//	void setBackColor(sf::Color color) {
//		button.setFillColor(color);
//	}
//
//	//void setTextColor(sf::Color color) {
//	//	text.setColor(color);
//	//}
//
//	void setPosition(sf::Vector2f pos) {
//		button.setPosition(pos);
//		
//		float xpos = (pos.x + button.getGlobalBounds().width / 3) - (text.getGlobalBounds().width / 2);
//		float ypos = (pos.y + button.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 2);
//
//		text.setPosition({ xpos, ypos });
//	}
//
//	void drawTo(sf::RenderWindow& window) {
//		window.draw(button);
//		window.draw(text);
//	}
//
//	bool isMouseOver(sf::RenderWindow& window) {
//		float mouseX = sf::Mouse::getPosition(window).x;
//		float mouseY = sf::Mouse::getPosition(window).y;
//
//		float butx = button.getPosition().x;
//		float buty = button.getPosition().y;
//
//		float butxWidth = button.getPosition().x + button.getGlobalBounds().width;
//		float butyHeight = button.getPosition().y + button.getGlobalBounds().height;
//
//		if (mouseX<butxWidth && mouseX>butx && mouseY <butyHeight && mouseY >buty) {
//			return true;
//		}
//		return false;
//	}
//
//private:
//	sf::RectangleShape button;
//	sf::Text text;
//};

class Button
{
private:
	void updateByMouse(const Vector2f mousePos);
	void updateType();

protected:
	short unsigned buttonState;

	RectangleShape shape;
	Texture* texture;
	Font* font;
	Text text;
	Clock clock;
	float delay;

	Color idleColor;
	Color hoverColor;
	Color activeColor;

public:
	Button(float x, float y, float width, float height, Font* font, std::string text, Color idleColor, Color hoverColor, Color activeColor);
	~Button();

	bool isPressedLeft();
	bool isPressedRight();
	void setTextSize(int size);
	void setCenter();
	bool setTexture(std::string filePath);
	void setText(std::string text);
	void setPosition(Vector2f pos);

	std::string getText();

	void update(const Vector2f mousePos);
	void render(RenderTarget* target);

};