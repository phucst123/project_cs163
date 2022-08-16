#include "State.h"


State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
	this->window = window;
	this->states = states;
	this->quit = false;
}

State::State(sf::RenderWindow* window, std::stack<State*>* states,Trie*& WordTrie,Trie*& DefinitionTrie, vector<pair<string, string>>& searchHistory, vector<pair<string, string>>& favoritelist)
{
	this->window = window;
	this->states = states;
	this->quit = false;
	this->myTrie = WordTrie;
	this->DefTrie = DefinitionTrie;
	this->history = searchHistory;
	this->favorlist = favoritelist;
}

State::State(sf::RenderWindow* window, std::stack<State*>* states, Trie*& WordTrie)
{
	this->window = window;
	this->states = states;
	this->quit = false;
	this->myTrie = WordTrie;
}


State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::endState()
{
	this->quit = true;
}


void State::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
