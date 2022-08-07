#include <iostream>
#include <vector>
#include "Global.h"
#include "Homemenu.h"

using namespace sf;

class Dictionary
{
private:
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;
	std::vector<VideoMode> videoModes;
	ContextSettings windowSettings;
	bool fullscreen;

	std::stack<State*> states;

	void initVariables();
	void initWindow();
	void initState();
	void updateEvents();

public:
	Dictionary();
	virtual ~Dictionary();
	
	const bool running() const;


	void updateSFMLEvents();
	void update();

	void render();
	void run();

	void closeWindow();
	void mouseProc();
};