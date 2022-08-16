#pragma once
#include"Button.h"
#include"global.h"
#include"State.h"

using namespace sf;
class RandomWord : public State
{

private:
	Texture backgroundTexture;
	RectangleShape background;
	Font arial;
	Trie* myTrie;
	
	std::pair<string, string> word;
	std::map<std::string, Button*> buttons;
	void initBackground();
	void initFonts();

public:

	RandomWord(sf::RenderWindow* window, std::stack<State*>* states,Trie* myTrie);
	void updateEvents();
	void update(const float& dt);
	void printOutRandomWord(RenderTarget* target);
	void render(RenderTarget* target = nullptr);

};

