#pragma once
#include"global.h"
#include<cstdio>
#include <stack>
#include <SFML/Graphics.hpp>


using namespace sf;
class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	Trie* myTrie;
	Trie* DefTrie;
	vector<pair<string, string>> history;
	vector<pair<string, string>> favorlist;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	State(sf::RenderWindow* window, std::stack<State*>* states, Trie*& WordTrie);
	State(sf::RenderWindow* window, std::stack<State*>* states, Trie*& WordTrie, Trie*& DefinitionTrie, vector<pair<string, string>>& searchHistory, vector<pair<string, string>>& favoritelist);
	virtual ~State();
	Event ev;
	const bool& getQuit() const;
	void endState();
	void updateMousePos();
	virtual void updateEvents() = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};