#include "Label.h"

/// <summary>
/// destructor taking values to set up layout on initialisation
/// </summary>
Label::Label(std::string t_string, sf::Vector2f t_pos, const  sf::Color & t_color, sf::Font & t_font, int t_charSize)
{
	if (t_string != "")
	{
		m_text.setString(t_string);
		m_text.setPosition(t_pos);
		m_text.setFillColor(t_color);
		m_text.setFont(t_font);
		m_text.setCharacterSize(t_charSize);
	}
}



/// <summary>
/// Label Set up to change label attributes after initialisation
/// </summary>
void Label::setup(std::string t_string, sf::Vector2f t_pos, const sf::Color t_color, sf::Font & t_font, int t_charSize)
{
	m_text.setString(t_string);
	m_text.setPosition(t_pos);
	m_text.setFillColor(t_color);
	m_text.setFont(t_font);
	m_text.setCharacterSize(t_charSize);
}

/// <summary>
/// Set the text color
/// </summary>
void Label::setColor(sf::Color t_color)
{
	m_text.setFillColor(t_color);
}

/// <summary>
/// Get the text color
/// </summary>
sf::Color Label::getColor() const
{
	return m_text.getFillColor();
}

/// <summary>
/// Set the text Size
/// </summary>
void Label::setCharSize(int t_size)
{
	m_text.setCharacterSize(t_size);
}

/// <summary>
/// Get the text Size
/// </summary>
int Label::getCharSize() const
{
	return m_text.getCharacterSize();
}

/// <summary>
/// Set the text String
/// </summary>
void Label::setString(std::string t_String)
{
	m_text.setString(t_String);
}

/// <summary>
/// Get the text String
/// </summary>
std::string Label::getString() const
{
	return m_text.getString();
}

/// <summary>
/// Set the texts origin 
/// </summary>
void Label::setOrigin(sf::Vector2f t_origin)
{
	m_text.setOrigin(t_origin);
}

/// <summary>
/// Get the texts origin 
/// </summary>
sf::Vector2f Label::getOrigin() const
{
	return m_text.getOrigin();
}

/// <summary>
/// Set the texts Posotition on the Screen
/// </summary>
void Label::setPosition(sf::Vector2f t_position)
{
	m_text.setPosition(t_position);
}

/// <summary>
/// Get the texts Posotition on the Screen
/// </summary>
sf::Vector2f Label::getPosition() const
{
	return m_text.getPosition();
}

sf::Text Label::getText()
{
	return m_text;
}

/// <summary>
/// Draws The text object on screen
/// </summary>
void Label::render(sf::RenderWindow & t_window)
{
	t_window.draw(getText());
}
