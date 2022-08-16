#include<iostream>
#include"RandomWordState.h"


void RandomWord::initBackground()
{
	this->background.setSize(Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)
	)
	);
	//std::cout << system("dir")<<"\n";
	this->backgroundTexture.loadFromFile("b02.png");
	this->background.setTexture(&this->backgroundTexture);

}

void RandomWord::initFonts()
{
	this->arial.loadFromFile("arial 1.ttf");
}

RandomWord::RandomWord(sf::RenderWindow* window, std::stack<State*>* states, Trie* WordTrie)
	: State(window, states,myTrie)
{
	this->initBackground();
	this->initFonts();
	this->myTrie = WordTrie;
	word = myTrie->getRandomWord();
}

void RandomWord::printOutRandomWord(RenderTarget* target)
{
	Text noti1;
	noti1.setString(this->word.first);
	noti1.setPosition(Vector2f(200.f, 200.f));
	noti1.setCharacterSize(20);
	noti1.setFillColor(Color::Black);
	noti1.setFont(this->arial);
	target->draw(noti1 );

	Text noti2;
	noti2.setString(this->word.second);
	noti2.setPosition(Vector2f(200.f, 300.f));
	noti2.setCharacterSize(20);
	noti2.setFillColor(Color::Black);
	noti2.setFont(this->arial);
	target->draw(noti2);

}

void RandomWord::updateEvents()
{
	switch (this->ev.type)
	{
	case Event::Closed:
		this->endState();
		break;
	default:
		break;
	}
}

void RandomWord::update(const float& dt)
{
	this->updateMousePos();
}

void RandomWord::render(RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	this->printOutRandomWord(target);
}


