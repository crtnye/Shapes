#pragma once
#include "Shape.h"
#include <string>
#include <sstream>

class Point :
	public Shape
{
public:
	Point();
	virtual ~Point();

	virtual void initialize(string stbAttributes);
	virtual void draw(Picture&);
	virtual void drawWithShadow(Picture&);

//protected:
	//RGBTriple color;
	//Coordinate startCoord;

private:
	int xCoord = 0;
	int yCoord = 0;
};

