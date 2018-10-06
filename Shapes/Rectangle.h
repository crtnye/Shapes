#pragma once
#include "Shape.h"
#include <string>
#include <sstream>

class Rectangle :
	public Shape
{
public:
	Rectangle();
	virtual ~Rectangle();

	virtual void initialize(string stbAttributes);
	virtual void draw(Picture&);
	virtual void drawWithShadow(Picture&);

//protected:
//	RGBTriple color;
//	Coordinate startCoord;

private:
	int width;
	int height;
};

