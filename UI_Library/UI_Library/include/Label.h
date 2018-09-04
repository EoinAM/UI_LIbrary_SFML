#ifndef LABEL
#define LABEL

#include "Global.h"

class Label
{
public:
	Label(std::string t_string = "", sf::Vector2f t_pos = sf::Vector2f(0, 0), const   sf::Color & t_color = sf::Color::White, sf::Font & t_font = sf::Font(), int t_charSize = 20);
	~Label() {};
	
	void setup(std::string t_string = std::string(), sf::Vector2f t_pos = sf::Vector2f(0, 0), const sf::Color t_color = sf::Color::White, sf::Font & t_font = sf::Font(), int t_charSize = 20);

	void setColor(const sf::Color t_color);
	sf::Color getColor() const;
	
	void setCharSize(int t_size);
	int getCharSize() const;

	void setString(std::string t_String);
	std::string getString() const;
	
	void setOrigin(sf::Vector2f t_origin);
	sf::Vector2f getOrigin()  const;

	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;

	sf::Text getText();

	void render(sf::RenderWindow & t_window);
	sf::Text m_text;
private:
	
	sf::Vector2f m_position{ 0,0 };
};


#endif // !LABEL
