#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "NoiseGen.h"

using namespace sf;

class MInterface
{
public:
	RenderWindow window;
	Font font;
	Event event;
	Mouse mouse;
	Vector2i pixelPos;
	RectangleShape rectangle;
	CircleShape circle;
	Text text;
	Keyboard keyboard;
	NoiseGen mapGen;

	MInterface();
	void MainProces();

};

