#pragma once
#include "Shape.h"
#include <string>
#include <sstream>

class Line :
	public Shape
{
public:
	Line();
	virtual ~Line();

	virtual void initialize(string stbAttributes);
	virtual void draw(Picture&);
	virtual void drawWithShadow(Picture&);

//protected:
//	RGBTriple color;
//	Coordinate startCoord;

private:
	Coordinate endCoord;
};

