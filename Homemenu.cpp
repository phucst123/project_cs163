#include<iostream>
#include"Homemenu.h"

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

void HomeMenu::initBackground()
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

void HomeMenu::initFonts()
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

void HomeMenu::initButtons()
{
	this->buttons["ENGTOENG_STATE"] = new Button(420, 230, 150, 50,
		&arial, "ENGTOENG",
		Color::Cyan, Color::Black, Color::Red);

	this->buttons["ENGTOVIE_STATE"] = new Button(420, 330, 150, 50,
		&arial, "ENGTOVIE",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	/*this->buttons["GAME_STATE"]->setTextSize(20);
	this->buttons["GAME_STATE"]->setCenter();*/

	this->buttons["VIETOENG_STATE"] = new Button(420, 430, 150, 50,
		&arial, "VIETOENG",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["SLANG_STATE"] = new Button(420, 530, 150, 50,
		&arial, "SLANG",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["EMOJI_STATE"] = new Button(420, 630, 150, 50,
		&arial, "EMOJI",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(420, 730, 150, 50,
		&arial, "QUIT",
		Color(70, 70, 70, 200), Color(150, 150, 150, 255), Color(20, 20, 20, 200));


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

HomeMenu::HomeMenu(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->initData();
	this->initBackground();
	this->initFonts();
	this->initButtons();
}

HomeMenu::~HomeMenu()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it) {

		delete it->second;
	}
}

void HomeMenu::updateEvents()
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

void HomeMenu::update(const float& dt)
{
	this->updateMousePos();

	this->updateButtons();

	/*this->updateInput(dt);*/

	//system("cls");
	//std::cout << this->mosePosView.x << " " << this->mosePosView.y << "\n";
}

void HomeMenu::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->buttons["ENGTOENG_STATE"]->isPressedLeft()) { 
		this->states->push(new DetailMenu(this->window, this->states, ENGTOENG, ENGTOENG_DEF, HistoryEngToEng, FavorListEngToEng));
		//detailMenu(ENGTOENG, ENGTOENG_DEF, HistoryEngToEng, FavorListEngToEng);
	}

	else if (this->buttons["ENGTOVIE_STATE"]->isPressedLeft()) {
		//detailMenu(ENGTOVIE, ENGTOVIE_DEF, HistoryEngToVie, FavorListEngToVie);
		this->states->push(new DetailMenu(this->window, this->states, ENGTOVIE, ENGTOVIE_DEF, HistoryEngToVie, FavorListEngToVie));
	}

	else if (this->buttons["VIETOENG_STATE"]->isPressedLeft()) {
		//detailMenu(VIETOENG, VIETOENG_DEF, HistoryVieToEng, FavorListVieToEng);
		this->states->push(new DetailMenu(this->window, this->states, VIETOENG, VIETOENG_DEF, HistoryVieToEng, FavorListVieToEng));
	}

	else if (this->buttons["SLANG_STATE"]->isPressedLeft()) {
		//detailMenu(SLANG, SLANG_DEF, HistorySlang, FavorListSlang);
		this->states->push(new DetailMenu(this->window, this->states, SLANG, SLANG_DEF, HistorySlang, FavorListSlang));
	}

	else if (this->buttons["EMOJI_STATE"]->isPressedLeft()) {
		//detailMenu(EMOJI, EMOJI_DEF, HistoryEmoji, FavorListEmoji);
		this->states->push(new DetailMenu(this->window, this->states, EMOJI, EMOJI_DEF, HistoryEmoji, FavorListEmoji));
	}


	if (this->buttons["EXIT_STATE"]->isPressedLeft()) {
		this->endState();
	}

}

void HomeMenu::render(RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	this->renderButtons(target);
}

void HomeMenu::renderButtons(RenderTarget* target)
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