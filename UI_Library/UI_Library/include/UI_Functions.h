#ifndef UI_FUNCTIONS
#define UI_FUNCTIONS

#include "Global.h"

struct UI_Functions
{
public:
	bool m_isHighlighted{ false };

	virtual void update(const sf::Time &t_dt, const Xbox360Controller & t_control) {};
	virtual void setSize(sf::Vector2f &t_size) {};
	virtual sf::Vector2f getSize() { return sf::Vector2f(0, 0); };
	virtual void setPosition(sf::Vector2f & t_pos) {};
	virtual sf::Vector2f getPosition() { return sf::Vector2f(0, 0); };
	virtual void setColor(const sf::Color & t_color) {};
	virtual sf::Color getColor() { return sf::Color(0, 0, 0, 0); };
	virtual void reset() {};
	virtual void set_isHighlighted(const bool t_bool) {};
	virtual bool get_isHiglighted() { return m_isHighlighted; };

};

#endif // !UI_FUNCTIONS
#pragma once
