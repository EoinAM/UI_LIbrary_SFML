#ifndef BUTTON
#define BUTTON

#include "Global.h"
#include "Label.h"
#include "UI_Functions.h"

class Button : UI_Functions
{
public:
	Button();
	~Button();

	void setup(sf::Vector2f &t_pos = sf::Vector2f(0, 0), sf::Vector2f t_size = sf::Vector2f(50, 50), Label t_label = Label(), sf::Color t_color = sf::Color::White, const bool &t_Highlight = bool(), sf::Texture &t_texture = sf::Texture(), sf::IntRect t_intrect = sf::IntRect(0,0,0,0));
	void setup(Button & t_button);
	void update(const double t_dt, Xbox360Controller & t_control);
	void render(sf::RenderWindow & t_window);
	bool get_isPressed();
	void set_isPressed(bool t_bool);
	void reset();

	bool m_prevHighlighted{ false };
	
	void setSize(sf::Vector2f & t_size);
	void setColor(sf::Color t_color);
	void setOutlineColor(sf::Color t_color);
	void setPosition(sf::Vector2f t_pos);
	void set_isHighlighted(bool t_bool);

	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	sf::Color getColor();
	sf::Color getOutlineColor();

	Label m_label;
	sf::RectangleShape m_body;
private:
	bool m_isPressed{false};
	bool m_ishighlightAnimated{ false };

	const float m_animScalar{ 0.5f };

};


#endif // !Button

