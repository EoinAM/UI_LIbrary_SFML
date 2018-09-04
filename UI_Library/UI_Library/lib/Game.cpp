#include "Game.h"


static double const MS_PER_UPDATE{ 10.0 };

Game::Game() :
	m_window(sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height, 32), "UI Library", sf::Style::Default),
	m_label("test",sf::Vector2f(200,250), sf::Color::Red, m_font, 100)
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			m_buttons.at(0).setup(sf::Vector2f(300, 300), sf::Vector2f(200, 50), m_label, sf::Color::Green, true);
		}
		else if (i != 0)
		{
			m_buttons.at(i).setup(m_buttons.at(i - 1).getPosition() + sf::Vector2f(0,200), sf::Vector2f(200, 50), m_label, sf::Color::Green, true);
		}
		//sf::Vector2f & t_pos, sf::Vector2f t_size, Label t_label, sf::Color t_color, const bool &t_Highlight, sf::Texture &t_texture, sf::IntRect t_intrect

	}

	m_font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf");

	m_window.setVerticalSyncEnabled(true);
	m_labelTests();
}


void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();
		
		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}
		update(MS_PER_UPDATE);

		render();
	}

}

void Game::m_labelTests()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		int charSize = m_label.getCharSize();
		m_label.setCharSize(charSize  + 5);
		m_label.setColor(sf::Color::Red);

		m_label.setOrigin(sf::Vector2f(600, 600));

		m_label.setString("change");
	}

}

void Game::buttonTests()
{
}

void Game::processEvents()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type = sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(event);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_window.close();
		}
	}
}

/// <summary>
/// Handles key handler inputs
/// </summary>
void Game::processGameEvents(sf::Event &t_event)
{

}

void Game::update(double t_dt)
{
	if (m_controller.isConnected())
	{
		m_controller.update();
	}

	for (int i = 0; i < 3; i++)
	{
		m_buttons.at(i).update(t_dt, m_controller);
	}
	

	m_labelTests();
}

void Game::render()
{
	m_window.clear();

	for (int i = 0; i < 3; i++)
	{
		m_buttons.at(i).render(m_window);
	}
	//m_label.render(m_window);
	m_window.display();
}




