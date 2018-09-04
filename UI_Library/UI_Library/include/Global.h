#ifndef GLOBAL
#define GLOBAL

#include "Xbox360Controller.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

struct ScreenSize
{
	static const unsigned int s_width { 1920 };
	static const unsigned int s_height{ 1080 };

	static const unsigned int halfDivisor{ 2 };
};

#endif // !GLOBAL
