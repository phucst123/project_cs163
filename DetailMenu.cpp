#include<iostream>
#include"DetailMenu.h"

//void HomeMenu::initBackground()
//{
//	this->img.setSize(sf::Vector2f(1280.0f, 720.0f));
//
//
//	this->background.loadFromFile("b02.png");
//	this->img.setTexture(&this->background);
//}
//
//void HomeMenu::initFonts()
//{
//	this->arial.loadFromFile("arial 1.ttf");
//}

void DetailMenu::initBackground()
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

void DetailMenu::initFonts()
{
	this->arial.loadFromFile("arial 1.ttf");
}

//void HomeMenu::initButtons()
//{
//	Button btt1("Eng to Eng", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
//	btt1.setPosition({ 950,100 });
//	btt1.setFont(arial);
//
//	Button btt2("Eng to Vie", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
//	btt2.setPosition({ 950,200 });
//	btt2.setFont(arial);
//
//	Button btt3("Vie to Eng", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
//	btt3.setPosition({ 950,300 });
//	btt3.setFont(arial);
//
//	Button btt4("Slang", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
//	btt4.setPosition({ 950,400 });
//	btt4.setFont(arial);
//
//	Button btt5("Emoji", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
//	btt5.setPosition({ 950,500 });
//	btt5.setFont(arial);
//
//	Button btt6("Exit", { 200,50 }, 20, sf::Color::Cyan, sf::Color::Black);
//	btt6.setPosition({ 950,600 });
//	btt6.setFont(arial);
//}

void DetailMenu::initButtons()
{
	this->buttons["search_state"] = new Button(220, 230, 150, 50,
		&arial, "SEARCH",
		Color::Cyan, Color::Black, Color::Red);

	this->buttons["searchByDef_state"] = new Button(220, 330, 150, 50,
		&arial, "SEARCH BY DEFINITION",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["add_state"] = new Button(220, 430, 150, 50,
		&arial, "ADD",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["delete_state"] = new Button(220, 530, 150, 50,
		&arial, "DELETE",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["viewAllWords_state"] = new Button(220, 630, 150, 50,
		&arial, "VIEW ALL WORDS",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["viewHistorySearch_state"] = new Button(420, 230, 150, 50,
		&arial, "VIEW HISTORY SEARCH",
		Color::Cyan, Color::Black, Color::Red);

	this->buttons["viewFavoriteList_state"] = new Button(420, 330, 150, 50,
		&arial, "VIEW FAVORITE LIST",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["getRandomWord_state"] = new Button(420, 430, 150, 50,
		&arial, "GET RANDOM WORD",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["gameSection_state"] = new Button(420, 530, 150, 50,
		&arial, "GAME SECTION ",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["back_state"] = new Button(420, 630, 150, 50,
		&arial, "BACK",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));


}




DetailMenu::DetailMenu(sf::RenderWindow* window, std::stack<State*>* states, Trie*& WordTrie, Trie*& DefinitionTrie, vector<pair<string, string>>& searchHistory, vector<pair<string, string>>& favoritelist)
	: State(window, states,myTrie,DefTrie,history,favorlist)
{
	this->initBackground();
	this->initFonts();
	this->initButtons();
	this->myTrie = WordTrie;
	this->DefTrie = DefinitionTrie;
	this->history = searchHistory;
	this->favorlist = favoritelist;
}

DetailMenu::~DetailMenu()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {

		delete it->second;
	}
}

void DetailMenu::updateEvents()
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

void DetailMenu::update(const float& dt)
{
	this->updateMousePos();

	this->updateButtons();

	/*this->updateInput(dt);*/

	//system("cls");
	//std::cout << this->mosePosView.x << " " << this->mosePosView.y << "\n";
}

void DetailMenu::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->buttons["search_state"]->isPressedLeft()) {
		searchWord(this->myTrie, &this->history, favorlist);
	}

	if (this->buttons["searchByDef_state"]->isPressedLeft()) {
		
	}

	if (this->buttons["add_state"]->isPressedLeft()) {
		
	}

	if (this->buttons["delete_state"]->isPressedLeft()) {
		
	}

	if (this->buttons["viewAllWords_state"]->isPressedLeft()) {
		
	}

	if (this->buttons["viewHistorySearch_state"]->isPressedLeft()) {

	}

	if (this->buttons["viewFavoriteList_state"]->isPressedLeft()) {

	}

	if (this->buttons["getRandomWord_state"]->isPressedLeft()) {
		this->states->push(new RandomWord(this->window, this->states, ENGTOENG));
	}

	if (this->buttons["gameSection_state"]->isPressedLeft()) {

	}


	if (this->buttons["back_state"]->isPressedLeft()) {
		this->endState();
	}

}

void DetailMenu::render(RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	this->renderButtons(target);
}

void DetailMenu::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}


//void HomeMenu::updateInput(const float& dt)
//{
//
//}