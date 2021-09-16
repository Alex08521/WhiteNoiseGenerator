#pragma once
#include <iostream>
#include "field.h"
#include "MyRand.h"
#include "coordinates.h"
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class NoiseGen
{
private:
	field<short> field;
	short fieldX;
	short fieldY;
	MyRand random;
	string name;
public:
	NoiseGen();
	NoiseGen(short X, short Y);
	~NoiseGen();
	bool generate();
	bool clear();
	bool save(string saveDir);
	bool rename(string nuname);
	bool resize(short X, short Y);

};

