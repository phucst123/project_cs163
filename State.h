#pragma once
#include"global.h"
#include<cstdio>
#include <stack>
#include <SFML/Graphics.hpp>



class State
{
private:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	const bool& getQuit() const;
	void endState();
	virtual void updateMousePos();
	virtual void updateInput(const float& dt) = 0;
};