#pragma once
#include <malloc.h>

template <typename fieldvar>

class field
{
private:
	int sideX;
	int sideY;
	int numOfElems;
	fieldvar* fieldArr;
	fieldvar* startArr;
	int X;
	int Y;
public:
	field();
	field(int numOfElements);
	field(int x, int y);
	~field();
	void moveTo(int x, int y);
	void writeIn(fieldvar var);
	fieldvar& readOn();
	fieldvar& operator()(int x, int y);
	void operator=(fieldvar var);
	void operator++();
	operator fieldvar();
	int returnX();
	int returnY();
	void destroy();
	bool resize(int x, int y);
	fieldvar& move_up();
	fieldvar& move_down();
	fieldvar& move_left();
	fieldvar& move_right();
	fieldvar& move_upl();
	fieldvar& move_upr();
	fieldvar& move_downl();
	fieldvar& move_downr();
	fieldvar& moveToCentral();
};