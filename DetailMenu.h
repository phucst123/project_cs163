#pragma once
#pragma once
#include"Button.h"
#include"global.h"
#include"State.h"
#include "RandomWordState.h"

using namespace sf;
class DetailMenu : public State
{

private:
	Texture backgroundTexture;
	RectangleShape background;
	Font arial;
	Trie*& myTrie;
	Trie*& DefTrie;
	const vector<pair<string, string>> history;
	vector<pair<string, string>>& favorlist;

	std::map<std::string, Button*> buttons;

	void initBackground();
	void initFonts();
	void initButtons();

public:
	DetailMenu(sf::RenderWindow* window, std::stack<State*>* states, Trie*& WordTrie, Trie*& DefinitionTrie, vector<pair<string, string>>& searchHistory, vector<pair<string, string>>& favoritelist);
	virtual ~DetailMenu();
	void updateEvents();
	/*void updateInput(const float& dt);*/
	void update(const float& dt);
	void render(RenderTarget* target = nullptr);
	void renderButtons(RenderTarget* target = nullptr);
	void updateButtons();

};