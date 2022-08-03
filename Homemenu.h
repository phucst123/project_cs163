#pragma once
#include"Homemenu.h"
#include"Button.h"
#include"global.h"
#include"State.h"

class HomeMenu : public State
{
	sf::Texture background;
	sf::RectangleShape img;
	sf::Font arial;

private:
	void initBackground();
	void initFonts();
	void initButtons();
	void initData();
	void initShape();

public:
	HomeMenu(sf::RenderWindow* window, std::stack<State*>* states);	
};