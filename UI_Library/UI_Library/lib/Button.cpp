#include "Button.h"

Button::Button()
{
	m_body.setOrigin(m_body.getSize().x / ScreenSize::halfDivisor, m_body.getSize().y / ScreenSize::halfDivisor);
	m_body.setOutlineColor(sf::Color::White);
	setup();
}

Button::~Button()
{
}

void Button::setup(sf::Vector2f & t_pos, sf::Vector2f t_size, Label t_label, sf::Color t_color, const bool &t_Highlight, sf::Texture &t_texture, sf::IntRect t_intrect)
{
	setPosition(t_pos);
	setSize(t_size);
	setColor(t_color);
	m_isHighlighted = t_Highlight;
	m_body.setOrigin(m_body.getSize().x / ScreenSize::halfDivisor, m_body.getSize().y / ScreenSize::halfDivisor);
	m_body.setTexture(&t_texture);
	m_body.setTextureRect(t_intrect);
	m_label = Label(t_label);
}

void Button::setup(Button & t_button)
{
	setPosition(t_button.getPosition());
	setSize(t_button.getSize());
	setColor(t_button.getColor());
	set_isHighlighted(t_button.get_isHiglighted());
	m_body.setOrigin(m_body.getSize().x / ScreenSize::halfDivisor, m_body.getSize().y / ScreenSize::halfDivisor);
	m_body.setTexture(m_body.getTexture());
	m_body.setTextureRect(m_body.getTextureRect());
	m_label = Label(t_button.m_label);

}

void Button::update(const double t_dt, Xbox360Controller & t_control)
{
	if (m_isHighlighted)
	{
		if (!m_prevHighlighted)
		{
			m_ishighlightAnimated = true;
		}

		if (m_ishighlightAnimated)
		{
			if (m_body.getOutlineThickness() < 5)
			{
				m_body.setOutlineThickness(m_body.getOutlineThickness() + (0.4 * m_animScalar));
			}
			else
			{
				m_ishighlightAnimated = false;
			}
		}

		if (!m_isPressed && !t_control.m_previousState.A && t_control.m_currentState.A)
		{
			m_isPressed = true;
		}
		else if (m_isPressed && (!t_control.m_previousState.A && t_control.m_currentState.A))
		{
			m_isPressed = false;
		}
	}

	else
	{
		if (m_body.getOutlineThickness() > 0)
		{
			m_body.setOutlineThickness(m_body.getOutlineThickness() - (0.4 * m_animScalar));
		}
		else
		{
			m_body.setOutlineThickness(0);
			m_ishighlightAnimated = false;
		}
	}

	m_prevHighlighted = m_isHighlighted;

}

bool Button::get_isPressed()
{
	return m_isPressed;
}

void Button::set_isPressed(bool t_bool)
{
	m_isPressed = t_bool;
}

void Button::setSize(sf::Vector2f & t_size)
{
	m_body.setSize(t_size);
	m_body.setOrigin(t_size.x / ScreenSize::halfDivisor, t_size.y / ScreenSize::halfDivisor);
}

void Button::setColor(sf::Color t_color)
{
	m_body.setFillColor(t_color);
}

void Button::setOutlineColor(sf::Color t_color)
{
	m_body.setOutlineColor(t_color);
}

void Button::setPosition(sf::Vector2f t_pos)
{
	m_body.setPosition(t_pos);
}

void Button::set_isHighlighted(bool t_bool)
{
	m_isHighlighted = t_bool;
}

sf::Vector2f Button::getSize()
{
	return m_body.getSize();
}

sf::Vector2f Button::getPosition()
{
	return m_body.getPosition();
}

sf::Color Button::getColor()
{
	return m_body.getFillColor();
}

sf::Color Button::getOutlineColor()
{
	return m_body.getOutlineColor();
}

void Button::reset()
{
	m_isPressed = false;
	m_isHighlighted = false;
	m_prevHighlighted = false; 
	m_ishighlightAnimated = false;
	m_body.setOutlineThickness(0);
}

void Button::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
	m_label.render(t_window);
}