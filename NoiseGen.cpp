#include "NoiseGen.h"

NoiseGen::NoiseGen()
{
	fieldX = 0;
	fieldY = 0;
	field = 0;
	name = "Untitled";
}

NoiseGen::NoiseGen(short X, short Y)
{
	fieldX = X;
	fieldY = Y;
	field.resize(fieldX, fieldY);
	name = "Untitled";
	for (int y = 0; y < fieldY; y++)
	{
		for (int x = 0; x < fieldX; x++)
		{
			field(x, y) = 0;
		}
	}
}

NoiseGen::~NoiseGen()
{
	
}

bool NoiseGen::generate()
{
	for (int y = 0; y < fieldY; y++)
	{
		for (int x = 0; x < fieldX; x++)
		{
			field(x, y) = random(255);
		}
	}

	return true;
}

bool NoiseGen::clear()
{
	for (int y = 0; y < fieldY; y++)
	{
		for (int x = 0; x < fieldX; x++)
		{
			field(x,y) = 0;
		}
	}
	return true;
}

bool NoiseGen::save(string saveDir)
{

	std::string directory = saveDir +"\\";
	std::string format = ".png";
	std::string filename = directory + name + format;
	Image savedmap;
	RenderWindow window;
	Event event;
	Vertex pixel[1];
	
	window.create(VideoMode(fieldX, fieldY), name, Style::Default);

	savedmap.create(fieldX, fieldY, Color::Black);
	

	for (int i = 0; i < fieldY; i++)
	{
		for (int j = 0; j < fieldX; j++)
		{
			char a = field(j,i);
			savedmap.setPixel(j, i, Color(a,a,a));
		}
	}

	while (window.isOpen())
	{
		window.clear();

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		for (int i = 0; i < fieldY; i++)
		{
			for (int j = 0; j < fieldX; j++)
			{
				char a = field(j, i);
				pixel[0] = Vertex(Vector2f(j, i), Color(a, a, a));
				window.draw(pixel, 1, Points);
			}
		}

		window.display();
	}

	if (!savedmap.saveToFile(filename))
	{
		return false;
	}
	else
	{
		return true;
	}

	return true;
}

bool NoiseGen::rename(string nuname)
{
	name = nuname;
	return true;
}

bool NoiseGen::resize(short X, short Y)
{
	fieldX = X;
	fieldY = Y;
	bool ans = field.resize(fieldX, fieldY);
	for (int y = 0; y < fieldY; y++)
	{
		for (int x = 0; x < fieldX; x++)
		{
			field(x, y) = 0;
		}
	}
	return ans;
}
