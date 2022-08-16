#pragma once
#include"Button.h"
#include"global.h"
#include"State.h"
#include "DetailMenu.h"

using namespace sf;
class HomeMenu : public State
{

private:
	Texture backgroundTexture;
	RectangleShape background;
	Font arial;
	
	std::map<std::string, Button*> buttons;

	void initBackground();
	void initFonts();
	void initButtons();
	void initData();
	void initShape();

public:
	HomeMenu(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~HomeMenu();
	void updateEvents();
	/*void updateInput(const float& dt);*/
	void update(const float& dt);
	void render(RenderTarget* target = nullptr);
	void renderButtons(RenderTarget* target = nullptr);
	void updateButtons();

};