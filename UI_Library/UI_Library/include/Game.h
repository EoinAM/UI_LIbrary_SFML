#ifndef GAME
#define GAME

#include "Global.h"
#include "Label.h"
#include "Button.h"
#include <array>
class Game
{
public:
	Game();
	~Game() {};

	void run();
	sf::Font m_font;

	void m_labelTests();
	void buttonTests();

protected:
	void update(double t_dt);
	void render();
	void processEvents();
	void processGameEvents(sf::Event &t_event);

	
	Label m_label;
	std::array<Button,3> m_buttons;
	

	sf::RenderWindow m_window;
	
	Xbox360Controller m_controller;
};

#endif 
