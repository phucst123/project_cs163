#include<iostream>
#include"Homemenu.h"

void HomeMenu::initBackground()
{
	this->img.setSize(sf::Vector2f(1280.0f, 720.0f));


	this->background.loadFromFile("b02.png");
	this->img.setTexture(&this->background);
}

void HomeMenu::initFonts()
{
	this->arial.loadFromFile("arial 1.ttf");
}

void HomeMenu::initButtons()
{
	Button btt1("Eng to Eng", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
	btt1.setPosition({ 950,100 });
	btt1.setFont(arial);

	Button btt2("Eng to Vie", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
	btt2.setPosition({ 950,200 });
	btt2.setFont(arial);

	Button btt3("Vie to Eng", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
	btt3.setPosition({ 950,300 });
	btt3.setFont(arial);

	Button btt4("Slang", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
	btt4.setPosition({ 950,400 });
	btt4.setFont(arial);

	Button btt5("Emoji", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
	btt5.setPosition({ 950,500 });
	btt5.setFont(arial);

	Button btt6("Exit", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
	btt6.setPosition({ 950,600 });
	btt6.setFont(arial);
}


void HomeMenu::initData()
{
	loadData();
}

void HomeMenu::initShape()
{
	sf::CircleShape square(50, 4);
	sf::CircleShape square2(50, 4);
	sf::CircleShape square3(50, 4);

	float xVelocity = 3;
	float yVelocity = 3;

	float xVelocity1 = 3;
	float yVelocity1 = 3;

	float xVelocity2 = 3;
	float yVelocity2 = 3;

	float xVelocity3 = 3;

}

//HomeMenu::HomeMenu(sf::RenderWindow* window, std::stack<State*>* states)
//{
//	this->initData();
//	this->initBackground();
//	this->initFonts();
//	this->initButtons();
//}