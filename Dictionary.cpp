#include "Dictionary.h"


Dictionary::Dictionary() {
	this->initVariables();
	this->initWindow();
	this->initState();
}

void Dictionary::initVariables()
{
	this->window = nullptr;
	this->fullscreen = false;

}

void Dictionary::initWindow()
{

	this->videoModes = VideoMode::getFullscreenModes();

	this->videoMode.height = 750;
	this->videoMode.width = 1000;
	unsigned antialiasing_level = 0;

	this->fullscreen = false;
	this->windowSettings.antialiasingLevel = antialiasing_level;
	if (this->fullscreen) {
		this->window = new RenderWindow(this->videoMode, "Dictionary", Style::Fullscreen, windowSettings);
	}
	else {


		std::string name;
		//name += "                                               ";
		//name += "                                                                 ";
		name += "Dictionary";
		this->window = new RenderWindow(this->videoMode, "Dictionary", Style::Titlebar | Style::Close, windowSettings);
		/*Image icon;
		icon.loadFromFile("Resources/icons/ico.png");
		this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		this->window = new RenderWindow(this->videoMode, name, Style::Titlebar, windowSettings);
		this->window = new RenderWindow(this->videoMode, "Minesweeper",Style::None, windowSettings);*/

	}
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);

}

void Dictionary::initState()
{
	this->states.push(new Homemenu(this->window, &this->states));
}

void Dictionary::run()
{
	while (this->running())
	{
		this->update();
		this->render();
	}
}

void Dictionary::updateSFMLEvents()
{
	if (!this->states.empty()) {
		while (this->window->pollEvent(this->states.top()->ev)) this->states.top()->updateEvents();
	}
	else {
		while (this->window->pollEvent(this->ev)) this->updateEvents();
	}
}

void Dictionary::updateEvents()
{
	switch (this->ev.type)
	{
	case Event::Closed:
		closeWindow();
		break;
	case Event::MouseButtonReleased:
		mouseProc();
	}
}

void Dictionary::closeWindow()
{
	this->window->close();
}

void Dictionary::mouseProc()
{
	switch (this->ev.mouseButton.button)
	{
	case Mouse::Left:
		std::cout << "\nLeft click " << Mouse::getPosition(*this->window).x << " " << Mouse::getPosition(*this->window).y;
		//field.open_cell(mouse_cell_x, mouse_cell_y);

		break;
	case sf::Mouse::Right:
		std::cout << "\nRight click";
		//field.flag_cell(mouse_cell_x, mouse_cell_y);
	}
}

void Dictionary::update()
{

	this->updateSFMLEvents();


	if (!this->states.empty()) {
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();

		}
	}
	else this->window->close();
}

void Dictionary::render()
{
	this->window->clear();
	if (!this->states.empty()) {
		this->states.top()->render();
	}
	this->window->display();
}

